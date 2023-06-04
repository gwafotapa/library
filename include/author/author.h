#ifndef AUTHOR_H
#define AUTHOR_H

#include <QString>

class Author {
  public:
    Author(const QString& name) : name {name} {}
    virtual ~Author() {};
    QString get_name() const;
    virtual bool makes_standard_books() const = 0;
    virtual bool makes_comic_books() const = 0;
    virtual bool writes() const = 0;
    virtual bool illustrates() const = 0;

  private:
    QString name;
};

#endif  // AUTHOR_H
