#include "illustrator.h"

bool Illustrator::makes_standard_books() const {
    return false;
}

bool Illustrator::makes_comic_books() const {
    return true;
}

bool Illustrator::writes() const {
    return false;
}

bool Illustrator::illustrates() const {
    return true;
}
