#include "standard_book.h"

QString StandardBook::get_title() const {
    return title;
}

QList<Writer> StandardBook::get_writers() const {
    return writers;
}

QString StandardBook::writers_to_string() const {
    QString writers_str;
    for (const Writer& writer : writers) {
        writers_str += writer.get_name();
    }
    return writers_str;
}