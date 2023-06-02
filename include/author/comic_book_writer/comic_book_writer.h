#ifndef COMIC_BOOK_WRITER_H
#define COMIC_BOOK_WRITER_H

#include <QString>

#include "author.h"

class ComicBookWriter: public Author {
  public:
    /* ComicBookWriter(const QString& name) : Author(name) {} */
    virtual int book_type() const override;
};

#endif  // COMIC_BOOK_WRITER_H
