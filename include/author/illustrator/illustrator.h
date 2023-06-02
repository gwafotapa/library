#ifndef ILLUSTRATOR_H
#define ILLUSTRATOR_H

#include <QString>

#include "author.h"

class Illustrator: public Author {
  public:
    Illustrator(const QString& name) : Author(name) {}
    virtual int book_type() const override;
};

#endif  // ILLUSTRATOR_H
