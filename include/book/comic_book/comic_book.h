#ifndef COMIC_BOOK_H
#define COMIC_BOOK_H

#include <QList>
#include <QString>

#include "book.h"
#include "comic_book_writer.h"
#include "illustrator.h"

class ComicBook: public Book {
  public:
    ComicBook(
        QString title,
        QList<ComicBookWriter> writers,
        QList<Illustrator> illustrators) :
        title {title},
        writers {writers},
        illustrators {illustrators} {}
    QString
    get_title() const override;  // TODO: change syntax for private title_
    QList<ComicBookWriter> get_writers() const;  // TODO: return references ?
    QList<Illustrator> get_illustrators() const;
    QString writers_to_string() const;
    QString illustrators_to_string() const;

  private:
    QString title;
    QList<ComicBookWriter> writers;
    QList<Illustrator> illustrators;
};

#endif  // COMIC_BOOK_H
