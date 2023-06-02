#ifndef WRITER_H
#define WRITER_H

#include <QString>

#include "author.h"

class Writer: public Author {
  public:
    Writer(const QString& name) : Author(name) {}
    int book_type() const override;
};

#endif  // WRITER_H
