#ifndef ADD_AUTHOR_WIDGET_H
#define ADD_AUTHOR_WIDGET_H

#include <qboxlayout.h>

#include <QCheckBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
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

    QVBoxLayout* main_layout;
    QFormLayout* form_layout;
    QHBoxLayout* buttons_layout;

    QLineEdit* name_line;
    QCheckBox* writer;
    QCheckBox* comic_book_writer;
    QCheckBox* illustrator;
    QPushButton* add_button;
    QPushButton* clear_button;

  private slots:
    void clear();
};

#endif  // ADD_AUTHOR_WIDGET_H
