#ifndef STANDARD_BOOK_H
#define STANDARD_BOOK_H

#include <QList>
#include <QString>

#include "book.h"
#include "writer.h"

class StandardBook: public Book {
  public:
    StandardBook(QString title, QList<Writer> writers) :
        title {title},
        writers {writers} {}
    QString
    get_title() const override;  // TODO: change syntax for private title_
    QList<Writer> get_writers() const;
    QString writers_to_string() const;

  private:
    QString title;
    QList<Writer> writers;
};

#endif  // STANDARD_BOOK_H
