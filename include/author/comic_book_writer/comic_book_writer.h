#ifndef COMIC_BOOK_WRITER_H
#define COMIC_BOOK_WRITER_H

#include <QString>

#include "author.h"

class ComicBookWriter: public Author {
  public:
    ComicBookWriter(const QString& name) : Author(name) {}
    bool makes_standard_books() const override;
    bool makes_comic_books() const override;
    bool writes() const override;
    bool illustrates() const override;
};

#endif  // COMIC_BOOK_WRITER_H
