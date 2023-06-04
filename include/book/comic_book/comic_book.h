#ifndef COMIC_BOOK_H
#define COMIC_BOOK_H

#include <QList>
#include <QString>
#include <algorithm>

#include "book.h"
#include "comic_book_writer.h"
#include "illustrator.h"

class ComicBook: public Book {
  public:
    ComicBook(
        QString title,
        QList<ComicBookWriter> writers,
        QList<Illustrator> illustrators) :
        title {title},
        writers {writers},
        illustrators {illustrators} {
        std::sort(
            this->writers.begin(),
            this->writers.end(),
            [](auto w1, auto w2) { return w1.get_name() < w2.get_name(); });
        std::sort(
            this->illustrators.begin(),
            this->illustrators.end(),
            [](auto i1, auto i2) { return i1.get_name() < i2.get_name(); });
    }
    QString get_title() const override;
    bool has_pictures() const override;
    const QList<ComicBookWriter>& get_writers() const;
    const QList<Illustrator>& get_illustrators() const;
    QString writers_to_string() const;
    QString illustrators_to_string() const;

  private:
    QString title;
    QList<ComicBookWriter> writers;
    QList<Illustrator> illustrators;
};

#endif  // COMIC_BOOK_H
