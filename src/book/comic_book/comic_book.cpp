#include "comic_book.h"

#include "comic_book_writer.h"
#include "illustrator.h"

QString ComicBook::get_title() const {
    return title;
}

bool ComicBook::has_pictures() const {
    return true;
}

const QList<ComicBookWriter>& ComicBook::get_writers() const {
    return writers;
}

const QList<Illustrator>& ComicBook::get_illustrators() const {
    return illustrators;
}

QString ComicBook::writers_to_string() const {
    QString writers_str;
    for (const ComicBookWriter& writer : writers) {
        writers_str += writer.get_name() + ", ";
    }
    writers_str.chop(2);
    return writers_str;
}

QString ComicBook::illustrators_to_string() const {
    QString illustrators_str;
    for (const Illustrator& illustrator : illustrators) {
        illustrators_str += illustrator.get_name() + ", ";
    }
    illustrators_str.chop(2);
    return illustrators_str;
}
