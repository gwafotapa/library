#include "data_model.h"

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
    // setTable("Standard Books");
}

DataModel::~DataModel() {
    if (database().isOpen()) {
        database().close();
    }
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

// TODO: select ? Implement 2 table views to "store" the results ?
// void DataModel::select_table(const QString& table) {
//     setTable(table);
//     // select();
// }

void DataModel::add_writer(const Writer& writer) {
    setTable(books_table_name);
    setFilter(
        "(Title IS NULL OR Title = '') AND Writers = '" + writer.get_name()
        + "'");
    select();
    if (rowCount() == 0) {
        QSqlRecord rec = record();
        rec.setValue("Writers", writer.get_name());
        insertRecord(-1, rec);
        submit();
        emit author_added(&writer);
    } else {
        qDebug() << "Writer is already in the database";
        emit author_exists(writer);
    }
    // setFilter(
    //     "");  // TODO: set filter back to its previous value ? Remove because any query should set its filter first ?
    // select();
    clear();
}

void DataModel::add_writers(const QList<Writer>& writers) {
    for (const Writer& writer : writers) {
        add_writer(writer);
    }
}

// TODO: factor with add_writer (table name is the only difference)
void DataModel::add_comic_book_writer(const ComicBookWriter& writer) {
    setTable(comic_books_table_name);
    setFilter("Writers = '" + writer.get_name() + "'");
    select();
    if (rowCount() == 0) {
        QSqlRecord rec = record();
        rec.setValue("Writers", writer.get_name());
        insertRecord(-1, rec);
        submit();
        emit author_added(&writer);
    } else {
        qDebug() << "Writer is already in the database";
        emit author_exists(writer);
    }
    clear();
    // setFilter("");
    // select();
}

void DataModel::add_comic_book_writers(const QList<ComicBookWriter>& writers) {
    for (const ComicBookWriter& writer : writers) {
        add_comic_book_writer(writer);
    }
}

// TODO: factor with add_writer and add_comic_book_writer as add_author
void DataModel::add_illustrator(const Illustrator& illustrator) {
    setTable(comic_books_table_name);
    setFilter("Illustrators = '" + illustrator.get_name() + "'");
    select();
    if (rowCount() == 0) {
        QSqlRecord rec = record();
        rec.setValue("Illustrators", illustrator.get_name());
        insertRecord(-1, rec);
        submit();
        emit author_added(&illustrator);
    } else {
        qDebug() << "Illustrator is already in the database";
        emit author_exists(illustrator);
    }
    // setFilter("");
    // select();
    clear();
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
    // setFilter("");
    // select();
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
    // setFilter("");
    // select();
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
    // for (int i = 0; i < rowCount(); ++i) {
    //     qDebug() << record(i);
    // }
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
    // for (int i = 0; i < rowCount(); ++i) {
    //     qDebug() << record(i);
    // }
};
