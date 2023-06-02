#include "comic_book.h"

QString ComicBook::get_title() const {
    return title;
}

QList<ComicBookWriter> ComicBook::get_writers() const {
    return writers;
}

QList<Illustrator> ComicBook::get_illustrators() const {
    return illustrators;
}
