#ifndef COMIC_BOOK_WRITER_ILLUSTRATOR_H
#define COMIC_BOOK_WRITER_ILLUSTRATOR_H

#include <QString>

#include "author.h"
#include "comic_book_writer.h"
#include "illustrator.h"

// TODO: no constructor ? avoir double inheritance ? Remove it entirely ?
class ComicBookWriterIllustrator: public ComicBookWriter, public Illustrator {
  public:
    /* ComicBookWriterIllustrator(const QString& name_) : Author::name {name_} {} */
    /*     ComicBookWriter(name), */
    /*     Illustrator(name) {} */
    /* ComicBookWriterIllustrator(const QString& name) : Illustrator(name) {} */
    int book_type() const override;
};

#endif  // COMIC_BOOK_WRITER_ILLUSTRATOR_H
