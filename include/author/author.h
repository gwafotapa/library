#ifndef AUTHOR_H
#define AUTHOR_H

#include <QString>

class Author {
  public:
    Author(const QString& name) : name {name} {}
    virtual ~Author() {};
    QString get_name() const;
    virtual int book_type() const = 0;

  private:
    QString name;
};

#endif  // AUTHOR_H
