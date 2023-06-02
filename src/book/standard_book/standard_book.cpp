#include "standard_book.h"

QString StandardBook::get_title() const {
    return title;
}

QList<Writer> StandardBook::get_writers() const {
    return writers;
}
