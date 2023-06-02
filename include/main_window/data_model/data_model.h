#ifndef DATA_MODEL_H
#define DATA_MODEL_H

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QList>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>

#include "book.h"

class DataModel: public QSqlTableModel {
    Q_OBJECT

  public:
    DataModel(
        QObject* parent = nullptr,
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE")) :
        QSqlTableModel(parent, db) {
        db_ = db;
        // QString data_dir = QCoreApplication::applicationDirPath() + "/data";
        // QDir().mkpath(data_dir);
        // QString data_path = data_dir + "/" + std::string(db_filename);

        QString db_path =
            QCoreApplication::applicationDirPath() + "/" + db_filename;
        db_.setDatabaseName(db_path);
        qDebug() << db_path;
        db_.open();

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
        // setTable("Books");
    }
    ~DataModel();

  public slots:
    void select_table(const QString& table);
    void add_writer(QString& writer);
    void add_writers(QStringList& writers);
    void add_comic_book_writer(QString& writer);
    void add_comic_book_writers(QStringList& writers);
    void add_illustrator(QString& illustrator);
    void add_illustrators(QStringList& illustrators);
    void add_standard_book(QString& title, QString& writers);
    void
    add_comic_book(QString& title, QString& writers, QString& illustrators);
    void search_books_and_writers(QString title, QString writers);
    void search_comic_books_and_authors(
        QString title,
        QString writers,
        QString illustrators);

  signals:
    void book_added(const Book& book) const;

  private:
    const QString db_filename = "library.db";
    const QString books_table_name = "Books";
    const QStringList books_column_names = {"Title", "Writers"};
    const QStringList books_column_types {"VARCHAR", "VARCHAR"};
    const QString comic_books_table_name = "Comic Books";
    const QStringList comic_books_column_names = {
        "Title",
        "Writers",
        "Illustrators"};
    const QStringList comic_books_column_types = {
        "VARCHAR",
        "VARCHAR",
        "VARCHAR"};

    QSqlDatabase db_;

    void create_table(
        const QString& table_name,
        const QStringList& table_column_names,
        const QStringList& column_types);
};

#endif  // DATA_MODEL_H
