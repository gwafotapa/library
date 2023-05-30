#include "datamodel.h"

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
