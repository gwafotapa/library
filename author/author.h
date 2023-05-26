#ifndef AUTHOR_H
#define AUTHOR_H

#include <QString>

class Author {
  public:
    Author(QString const& first_name, QString const& last_name) :
        first_name_ {first_name},
        last_name_ {last_name} {}

    QString first_name() const;
    QString last_name() const;

  private:
    QString first_name_;
    QString last_name_;
};

#endif  // AUTHOR_H
