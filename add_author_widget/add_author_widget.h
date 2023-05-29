#ifndef ADD_AUTHOR_WIDGET_H
#define ADD_AUTHOR_WIDGET_H

#include <QCheckBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QWidget>

namespace Ui {
class AddAuthorWidget;
}

class AddAuthorWidget: public QWidget {
    Q_OBJECT

  public:
    explicit AddAuthorWidget(QWidget* parent = nullptr);
    ~AddAuthorWidget();

  private:
    Ui::AddAuthorWidget* ui;
    QFormLayout* form_layout;
    QLineEdit* name_line;
    QCheckBox* writer;
    QCheckBox* comic_book_writer;
    QCheckBox* illustrator;
};

#endif  // ADD_AUTHOR_WIDGET_H
