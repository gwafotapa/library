#ifndef WRITER_H
#define WRITER_H

#include <QString>

#include "author.h"

class Writer: public Author {
  public:
    Writer(const QString& name) : Author(name) {}
    bool makes_standard_books() const override;
    bool makes_comic_books() const override;
    bool writes() const override;
    bool illustrates() const override;
};

#endif  // WRITER_H
