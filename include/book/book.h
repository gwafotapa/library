#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book {
  public:
    virtual ~Book() {}
    virtual QString get_title() const = 0;
    virtual bool has_pictures() const = 0;
};

#endif  // BOOK_H
