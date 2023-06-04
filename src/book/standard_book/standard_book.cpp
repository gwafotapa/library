#include "standard_book.h"

QString StandardBook::get_title() const {
    return title;
}

bool StandardBook::has_pictures() const {
    return false;
}

QList<Writer> StandardBook::get_writers() const {
    return writers;
}

QString StandardBook::writers_to_string() const {
    QString writers_str;
    for (const Writer& writer : writers) {
        writers_str += writer.get_name() + ", ";
    }
    writers_str.chop(2);
    return writers_str;
}
