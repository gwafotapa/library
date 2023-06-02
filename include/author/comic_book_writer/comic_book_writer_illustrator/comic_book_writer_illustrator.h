#ifndef COMIC_BOOK_WRITER_ILLUSTRATOR_H
#define COMIC_BOOK_WRITER_ILLUSTRATOR_H

#include <QString>

#include "comic_book_writer.h"
#include "illustrator.h"

class ComicBookWriterIllustrator: public ComicBookWriter, public Illustrator {
  public:
    /* ComicBookWriterIllustrator(const QString& name) : */
    /*     ComicBookWriter(name), */
    /*     Illustrator(name) {} */
    /* ComicBookWriterIllustrator(const QString& name) : Illustrator(name) {} */
    int book_type() const override;
};

#endif  // COMIC_BOOK_WRITER_ILLUSTRATOR_H
