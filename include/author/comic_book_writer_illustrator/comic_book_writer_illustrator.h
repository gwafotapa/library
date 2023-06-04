#ifndef COMIC_BOOK_WRITER_ILLUSTRATOR_H
#define COMIC_BOOK_WRITER_ILLUSTRATOR_H

#include <QString>

#include "author.h"

class ComicBookWriterIllustrator: public Author {
  public:
    ComicBookWriterIllustrator(const QString& name) : Author(name) {}
    bool makes_standard_books() const override;
    bool makes_comic_books() const override;
};

#endif  // COMIC_BOOK_WRITER_ILLUSTRATOR_H
