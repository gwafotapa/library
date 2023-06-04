#ifndef ILLUSTRATOR_H
#define ILLUSTRATOR_H

#include <QString>

#include "author.h"

class Illustrator: public Author {
  public:
    Illustrator(const QString& name) : Author(name) {}
    bool makes_standard_books() const override;
    bool makes_comic_books() const override;
};

#endif  // ILLUSTRATOR_H
