#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>

class DataModel: public QSqlTableModel {
    Q_OBJECT

  private:
    QSqlDatabase db_;

  public:
    DataModel(
        QObject* parent = nullptr,
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE")) :
        QSqlTableModel(parent, db) {
        db_ = db;
        QString data_dir = QCoreApplication::applicationDirPath() + "/data";
        QDir().mkpath(data_dir);
        QString data_path = data_dir + "/library.db";
        db_.setDatabaseName(data_path);
        qDebug() << data_path;
        db_.open();

        QSqlQuery query(db_);
        if (!db_.tables().contains("Books")) {
            qDebug() << "Table 'Books' not found";
            bool result = query.exec(
                "CREATE TABLE Books (title VARCHAR, authors VARCHAR)");
            qDebug()
                << (result ? "Table 'Books' created"
                           : query.lastError().databaseText());
        }
        if (!db_.tables().contains("Authors")) {
            qDebug() << "Table 'Authors' not found";
            bool result = query.exec("CREATE TABLE Authors (name VARCHAR)");
            qDebug()
                << (result ? "Table 'Authors' created"
                           : query.lastError().databaseText());
        }
        /* setTable("books"); */
    }
    ~DataModel();
};

#endif  // DATAMODEL_H
