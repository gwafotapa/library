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
#include "comic_book.h"
#include "comic_book_writer.h"
#include "illustrator.h"
#include "standard_book.h"

const QString db_filename = "library.db";
const QString books_table_name = "Standard Books";
const QStringList books_column_names = {"Title", "Writers"};
const QStringList books_column_types {"VARCHAR", "VARCHAR"};
const QString comic_books_table_name = "Comic Books";
const QStringList comic_books_column_names = {
    "Title",
    "Writers",
    "Illustrators"};
const QStringList comic_books_column_types = {"VARCHAR", "VARCHAR", "VARCHAR"};

class DataModel: public QSqlTableModel {
    Q_OBJECT

  public:
    DataModel(const QString& connection_name, QObject* parent = nullptr);
    ~DataModel();

  public slots:
    // void select_table(const QString& table);
    void add_writer(const Writer& writer);
    void add_writers(const QList<Writer>& writers);
    void add_comic_book_writer(const ComicBookWriter& writer);
    void add_comic_book_writers(const QList<ComicBookWriter>& writers);
    void add_illustrator(const Illustrator& illustrator);
    void add_illustrators(const QList<Illustrator>& illustrators);
    void add_standard_book(const StandardBook& book);
    void add_comic_book(const ComicBook& book);
    void search_standard_books(QString title, QString writers);
    void
    search_comic_books(QString title, QString writers, QString illustrators);

  signals:
    void book_added(const Book& book);
    void book_exists(const Book& book);
    void author_added(const Author& author);
    void author_exists(const Author& author);

  private:
    void add_author(const Author& author, const QString& table_name);
    void create_table(
        const QString& table_name,
        const QStringList& table_column_names,
        const QStringList& column_types);
};

#endif  // DATA_MODEL_H
