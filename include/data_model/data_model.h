#ifndef DATA_MODEL_H
#define DATA_MODEL_H

#include <QList>
#include <QSqlTableModel>
#include <QString>
#include <QStringList>

#include "author.h"
#include "book.h"
#include "comic_book.h"
#include "comic_book_writer.h"
#include "illustrator.h"
#include "standard_book.h"
#include "writer.h"

class DataModel: public QSqlTableModel {
    Q_OBJECT

  public:
    DataModel(const QString& connection_name, QObject* parent = nullptr);
    ~DataModel();
    void set_table_standard_books();
    void set_table_comic_books();

  public slots:
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

    inline static const QString db_filename = "Library.db";
    inline static const QString books_table_name = "Standard Books";
    inline static const QString comic_books_table_name = "Comic Books";
    inline static const QStringList books_column_names = {"Title", "Writers"};
    inline static const QStringList comic_books_column_names = {
        "Title",
        "Writers",
        "Illustrators"};
    inline static const QStringList books_column_types {"VARCHAR", "VARCHAR"};
    inline static const QStringList comic_books_column_types = {
        "VARCHAR",
        "VARCHAR",
        "VARCHAR"};
};

#endif  // DATA_MODEL_H
