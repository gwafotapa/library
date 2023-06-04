#include "data_model.h"

#include <QCoreApplication>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>

#include "comic_book.h"
#include "comic_book_writer.h"
#include "standard_book.h"
#include "writer.h"

DataModel::DataModel(const QString& connection_name, QObject* parent) :
    QSqlTableModel(
        parent,
        QSqlDatabase::addDatabase("QSQLITE", connection_name)) {
    // QString data_dir = QCoreApplication::applicationDirPath() + "/data";
    // QDir().mkpath(data_dir);
    // QString data_path = data_dir + "/" + std::string(db_filename);

    QString db_path =
        QCoreApplication::applicationDirPath() + "/" + db_filename;
    database().setDatabaseName(db_path);
    qDebug() << db_path;
    database().open();

    create_table(
        // QString::fromStdString(std::string(table_books)),
        // QString::fromUtf8(table_books),
        books_table_name,
        books_column_names,
        books_column_types);
    create_table(
        comic_books_table_name,
        comic_books_column_names,
        comic_books_column_types);
}

DataModel::~DataModel() {
    if (database().isOpen()) {
        database().close();
    }
}

void DataModel::set_table_standard_books() {
    setTable(books_table_name);
}

void DataModel::set_table_comic_books() {
    setTable(comic_books_table_name);
}

void DataModel::create_table(
    const QString& table_name,
    const QStringList& column_names,
    const QStringList& column_types) {
    if (!database().tables().contains(table_name)) {
        qDebug() << "Table " + table_name + " not found";
        QString create_query = "CREATE TABLE \"" + table_name + "\" (";
        for (long long i = 0; i < column_names.size(); ++i) {
            create_query += "\"" + column_names[i] + "\" " + column_types[i];
            if (i + 1 < column_names.size()) {
                create_query += ", ";
            }
        }
        create_query += ")";
        qDebug() << create_query;
        QSqlQuery query(database());
        bool result = query.exec(create_query);
        qDebug()
            << (result ? "Table " + table_name + " created"
                       : query.lastError().databaseText());
    }
}

void DataModel::add_author(const Author& author, const QString& table_name) {
    QString column = author.writes() ? "Writer" : "Illusstrator";
    setTable(table_name);
    setFilter(
        "(Title IS NULL OR Title = '') AND " + column + "s = '"
        + author.get_name() + "'");
    select();
    if (rowCount() == 0) {
        QSqlRecord rec = record();
        rec.setValue(column + "s", author.get_name());
        insertRecord(-1, rec);
        submit();
        emit author_added(author);
    } else {
        qDebug() << column + " is already in the database";
        emit author_exists(author);
    }
    clear();
}

void DataModel::add_writer(const Writer& writer) {
    add_author(writer, books_table_name);
}

void DataModel::add_writers(const QList<Writer>& writers) {
    for (const Writer& writer : writers) {
        add_writer(writer);
    }
}

void DataModel::add_comic_book_writer(const ComicBookWriter& writer) {
    add_author(writer, comic_books_table_name);
}

void DataModel::add_comic_book_writers(const QList<ComicBookWriter>& writers) {
    for (const ComicBookWriter& writer : writers) {
        add_comic_book_writer(writer);
    }
}

void DataModel::add_illustrator(const Illustrator& illustrator) {
    add_author(illustrator, comic_books_table_name);
}

void DataModel::add_illustrators(const QList<Illustrator>& illustrators) {
    for (const Illustrator& illustrator : illustrators) {
        add_illustrator(illustrator);
    }
}

void DataModel::add_standard_book(const StandardBook& book) {
    setTable(books_table_name);
    setFilter(
        "Title = '" + book.get_title() + "' AND Writers = '"
        + book.writers_to_string() + "'");
    select();
    if (rowCount() == 0) {
        QSqlRecord rec = record();
        rec.setValue("Title", book.get_title());
        rec.setValue("Writers", book.writers_to_string());
        insertRecord(-1, rec);
        submit();
        emit book_added(book);
    } else {
        qDebug() << "Book is already in the database";
        emit book_exists(book);
    }
    clear();
}

void DataModel::add_comic_book(const ComicBook& book) {
    setTable(comic_books_table_name);
    setFilter(
        "Title = '" + book.get_title() + "' AND Writers = '"
        + book.writers_to_string() + "' AND Illustrators = '"
        + book.illustrators_to_string() + "'");
    select();
    if (rowCount() == 0) {
        QSqlRecord rec = record();
        rec.setValue("Title", book.get_title());
        rec.setValue("Writers", book.writers_to_string());
        rec.setValue("Illustrators", book.illustrators_to_string());
        insertRecord(-1, rec);
        submit();
        emit book_added(book);
    } else {
        qDebug() << "Comic book is already in the database";
        emit book_exists(book);
    }
    clear();
}

void DataModel::search_standard_books(QString title, QString writers) {
    title = title.simplified();
    writers = writers.simplified();

    setTable(books_table_name);
    QString filter;
    if (!title.isEmpty()) {
        filter += "Title LIKE '%" + title + "%'";
    }
    if (!writers.isEmpty()) {
        if (!filter.isEmpty()) {
            filter += " AND ";
        }
        filter += "Writers LIKE '%" + writers + "%'";
    }
    setFilter(filter);
    sort(1, Qt::AscendingOrder);

    qDebug() << selectStatement();
}

void DataModel::search_comic_books(
    QString title,
    QString writers,
    QString illustrators) {
    title = title.simplified();
    writers = writers.simplified();
    illustrators = illustrators.simplified();

    setTable(comic_books_table_name);
    QString filter;
    if (!title.isEmpty()) {
        filter += "Title LIKE '%" + title + "%'";
    }
    if (!writers.isEmpty()) {
        if (!filter.isEmpty()) {
            filter += " AND ";
        }
        filter += "Writers LIKE '%" + writers + "%'";
    }
    if (!illustrators.isEmpty()) {
        if (!filter.isEmpty()) {
            filter += " AND ";
        }
        filter += "Illustrators LIKE '%" + illustrators + "%'";
    }
    setFilter(filter);
    // setSort(2, Qt::AscendingOrder);
    sort(1, Qt::AscendingOrder);
    // select();

    qDebug() << selectStatement();
};
