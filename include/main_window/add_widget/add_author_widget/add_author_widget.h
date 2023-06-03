#ifndef ADD_AUTHOR_WIDGET_H
#define ADD_AUTHOR_WIDGET_H

#include <qboxlayout.h>

#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include "comic_book_writer.h"
#include "illustrator.h"
#include "writer.h"

namespace Ui {
class AddAuthorWidget;
}

class AddAuthorWidget: public QWidget {
    Q_OBJECT

  public:
    explicit AddAuthorWidget(QWidget* parent = nullptr);
    ~AddAuthorWidget();
    QLineEdit* get_name_line() const;
    QCheckBox* get_writer() const;
    QCheckBox* get_comic_book_writer() const;
    QCheckBox* get_illustrator() const;
    void clear();
    // signals:
    //   void add_writer(const Writer& writer);
    //   void add_comic_book_writer(const ComicBookWriter& writer);
    //   void add_illustrator(const Illustrator& illustrator);

  private:
    Ui::AddAuthorWidget* ui;

    QVBoxLayout* main_layout;
    QFormLayout* form_layout;
    QHBoxLayout* buttons_layout;

    QLineEdit* name_line;
    QCheckBox* writer;
    QCheckBox* comic_book_writer;
    QCheckBox* illustrator;
    // QPushButton* add_button;
    // QPushButton* clear_button;
    // QLabel* message;
};

#endif  // ADD_AUTHOR_WIDGET_H
