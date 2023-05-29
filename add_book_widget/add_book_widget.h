#ifndef ADD_BOOK_WIDGET_H
#define ADD_BOOK_WIDGET_H

#include <QCheckBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

namespace Ui {
class AddBookWidget;
}

class AddBookWidget: public QWidget {
    Q_OBJECT

  public:
    explicit AddBookWidget(QWidget* parent = nullptr);
    ~AddBookWidget();

  public slots:
    void set_add_book_mode(int mode);

  private:
    Ui::AddBookWidget* ui;

    QVBoxLayout* main_layout;
    QFormLayout* form_layout;
    QHBoxLayout* buttons_layout;

    QLineEdit* title_line;
    QLineEdit* writers_line;
    QLineEdit* illustrators_line;
    QCheckBox* check_box;
    QPushButton* add_button;
    QPushButton* clear_button;

  private slots:
    void writer_illustrator(int state);
    void copy_writer_to_illustrator();
    void clear();
};

#endif  // ADD_BOOK_WIDGET_H
