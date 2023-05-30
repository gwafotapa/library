#include "datamodel.h"

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

void DataModel::add_writers(QStringList& writers) {
    // QStringList writer_list = writers.split(u',');
    for (QString& writer : writers) {
        add_writer(writer);
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
