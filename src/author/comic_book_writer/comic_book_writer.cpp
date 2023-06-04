#include "comic_book_writer.h"

bool ComicBookWriter::makes_standard_books() const {
    return false;
}

bool ComicBookWriter::makes_comic_books() const {
    return true;
}

bool ComicBookWriter::writes() const {
    return true;
}

bool ComicBookWriter::illustrates() const {
    return false;
}
