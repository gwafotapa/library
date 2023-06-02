#ifndef COMIC_BOOK_H
#define COMIC_BOOK_H

#include <QString>

#include "book.h"
#include "comic_book_writer.h"
#include "illustrator.h"

class ComicBook: public Book {
  public:
    ComicBook(QString title, ComicBookWriter writer, Illustrator illustrator) :
        title {title},
        writer {writer},
        illustrator {illustrator} {}
    QString
    get_title() const override;  // TODO: change syntax for private title_
    ComicBookWriter get_writer() const;
    Illustrator get_illustrator() const;

  private:
    QString title;
    ComicBookWriter writer;
    Illustrator illustrator;
};

#endif  // COMIC_BOOK_H
