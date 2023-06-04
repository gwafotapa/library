#include "comic_book_writer_illustrator.h"

bool ComicBookWriterIllustrator::makes_standard_books() const {
    return false;
}

bool ComicBookWriterIllustrator::makes_comic_books() const {
    return true;
}
