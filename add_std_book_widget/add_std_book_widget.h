#ifndef ADD_STD_BOOK_WIDGET_H
#define ADD_STD_BOOK_WIDGET_H

#include <QFormLayout>
#include <QLineEdit>
#include <QWidget>

namespace Ui {
class AddStdBookWidget;
}

class AddStdBookWidget: public QWidget {
    Q_OBJECT

  public:
    explicit AddStdBookWidget(QWidget* parent = nullptr);
    ~AddStdBookWidget();

  private:
    Ui::AddStdBookWidget* ui;
    QFormLayout* form_layout;
    QLineEdit* title_line;
    QLineEdit* writers_line;
};

#endif  // ADD_STD_BOOK_WIDGET_H
