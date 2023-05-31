#include "datamodel.h"

#include <qnamespace.h>

#include <QSqlRecord>

DataModel::~DataModel() {
    if (db_.isOpen()) {
        db_.close();
    }
}

void DataModel::create_table(
    const QString& table_name,
    const QStringList& column_names,
    const QStringList& column_types) {
    if (!db_.tables().contains(table_name)) {
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
        QSqlQuery query(db_);
        bool result = query.exec(create_query);
        qDebug()
            << (result ? "Table " + table_name + " created"
                       : query.lastError().databaseText());
    }
}

void DataModel::add_writer(QString& writer) {
    writer = writer.simplified();
    if (writer.isEmpty()) {
        qDebug() << "Name of writer is empty";
        return;
    }

    setTable(books_table_name);
    setFilter("Writers = '" + writer + "'");
    select();
    if (rowCount() == 0) {
        QSqlRecord rec = record();
        rec.setValue("Writers", writer);
        insertRecord(-1, rec);
        submit();
    } else {
        qDebug() << "Writer is already in the database";
    }
    setFilter("");
    select();
}

void DataModel::add_writers(QStringList& writers) {
    // QStringList writer_list = writers.split(u',');
    for (QString& writer : writers) {
        add_writer(writer);
    }
}

// TODO: factor with add_writer (table name is the only difference)
void DataModel::add_comic_book_writer(QString& writer) {
    writer = writer.simplified();
    if (writer.isEmpty()) {
        qDebug() << "Name of writer is empty";
        return;
    }

    setTable(comic_books_table_name);
    setFilter("Writers = '" + writer + "'");
    select();
    if (rowCount() == 0) {
        QSqlRecord rec = record();
        rec.setValue("Writers", writer);
        insertRecord(-1, rec);
        submit();
    } else {
        qDebug() << "Writer is already in the database";
    }
    setFilter("");
    select();
}

void DataModel::add_comic_book_writers(QStringList& writers) {
    for (QString& writer : writers) {
        add_comic_book_writer(writer);
    }
}

// TODO: factor with add_writer and add_comic_book_writer as add_author
void DataModel::add_illustrator(QString& illustrator) {
    illustrator = illustrator.simplified();
    if (illustrator.isEmpty()) {
        qDebug() << "Name of illustrator is empty";
        return;
    }

    setTable(comic_books_table_name);
    setFilter("Illustrators = '" + illustrator + "'");
    select();
    if (rowCount() == 0) {
        QSqlRecord rec = record();
        rec.setValue("Illustrators", illustrator);
        insertRecord(-1, rec);
        submit();
    } else {
        qDebug() << "Illustrator is already in the database";
    }
    setFilter("");
    select();
}

void DataModel::add_illustrators(QStringList& illustrators) {
    for (QString& illustrator : illustrators) {
        add_illustrator(illustrator);
    }
}

void DataModel::add_book(QString& title, QString& writers) {
    title = title.simplified();
    writers = writers.simplified();
    if (title.isEmpty() || writers.isEmpty()) {
        qDebug() << "Empty string: " << (title.isEmpty() ? "Title" : "Writers");
        return;
    }

    setTable(books_table_name);
    setFilter("Title = '" + title + "' AND Writers = '" + writers + "'");
    select();
    if (rowCount() == 0) {
        QSqlRecord rec = record();
        rec.setValue("Title", title);
        rec.setValue("Writers", writers);
        insertRecord(-1, rec);
        submit();
    } else {
        qDebug() << "Book is already in the database";
    }
    setFilter("");
    select();
}

void DataModel::add_comic_book(
    QString& title,
    QString& writers,
    QString& illustrators) {
    title = title.simplified();
    writers = writers.simplified();
    illustrators = illustrators.simplified();
    if (title.isEmpty()) {
        qDebug() << "Empty string: Title";
        return;
    }
    if (writers.isEmpty()) {
        qDebug() << "Empty string: Writers";
        return;
    }
    if (illustrators.isEmpty()) {
        qDebug() << "Empty string: Illustrators";
        return;
    }

    setTable(comic_books_table_name);
    setFilter(
        "Title = '" + title + "' AND Writers = '" + writers
        + "' AND Illustrators = '" + illustrators + "'");
    select();
    if (rowCount() == 0) {
        QSqlRecord rec = record();
        rec.setValue("Title", title);
        rec.setValue("Writers", writers);
        rec.setValue("Illustrators", illustrators);
        insertRecord(-1, rec);
        submit();
    } else {
        qDebug() << "Comic book is already in the database";
    }
    setFilter("");
    select();
}

void DataModel::search_books_and_writers(QString& title, QString& writers) {
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

void DataModel::search_comic_books_and_authors(
    QString& title,
    QString& writers,
    QString& illustrators) {
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
    select();

    qDebug() << selectStatement();
    // for (int i = 0; i < rowCount(); ++i) {
    //     qDebug() << record(i);
    // }
};
