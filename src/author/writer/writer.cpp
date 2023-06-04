#include "writer.h"

bool Writer::makes_standard_books() const {
    return true;
}

bool Writer::makes_comic_books() const {
    return false;
}

bool Writer::writes() const {
    return true;
}

bool Writer::illustrates() const {
    return false;
}
