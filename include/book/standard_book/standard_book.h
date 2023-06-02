#ifndef STANDARD_BOOK_H
#define STANDARD_BOOK_H

#include <QList>
#include <QString>
#include <algorithm>

#include "book.h"
#include "writer.h"

class StandardBook: public Book {
  public:
    StandardBook(QString title, QList<Writer> writers) :
        title {title},
        writers {writers} {
        std::sort(
            this->writers.begin(),
            this->writers.end(),
            [](auto w1, auto w2) { return w1.get_name() < w2.get_name(); });
    }
    QString
    get_title() const override;  // TODO: change syntax for private title_
    QList<Writer> get_writers() const;
    QString writers_to_string() const;

  private:
    QString title;
    QList<Writer> writers;
};

#endif  // STANDARD_BOOK_H
