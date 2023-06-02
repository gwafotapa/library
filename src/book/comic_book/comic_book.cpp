#include "comic_book.h"

QString ComicBook::get_title() const {
    return title;
}

ComicBookWriter ComicBook::get_writer() const {
    return writer;
}

Illustrator ComicBook::get_illustrator() const {
    return illustrator;
}
