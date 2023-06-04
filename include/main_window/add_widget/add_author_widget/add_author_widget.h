#ifndef ADD_AUTHOR_WIDGET_H
#define ADD_AUTHOR_WIDGET_H

#include <QCheckBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>

namespace Ui {
class AddAuthorWidget;
}

class AddAuthorWidget: public QWidget {
    Q_OBJECT

  public:
    explicit AddAuthorWidget(QWidget* parent = nullptr);
    ~AddAuthorWidget();
    const QLineEdit* get_name_line() const;
    const QCheckBox* get_writer() const;
    const QCheckBox* get_comic_book_writer() const;
    const QCheckBox* get_illustrator() const;
    void clear();

  private:
    Ui::AddAuthorWidget* ui;

    QVBoxLayout* main_layout;
    QFormLayout* form_layout;
    QHBoxLayout* buttons_layout;

    QLineEdit* name_line;
    QCheckBox* writer;
    QCheckBox* comic_book_writer;
    QCheckBox* illustrator;
};

#endif  // ADD_AUTHOR_WIDGET_H
