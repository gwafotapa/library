#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book {
  public:
    Book(QString const& title, QString const& authors) :
        title_ {title},
        authors_ {authors} {}

    QString title() const;
    QString authors() const;

  private:
    QString title_;
    QString authors_;
};

#endif  // BOOK_H
