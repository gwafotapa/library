#ifndef ADD_BOOK_WIDGET_H
#define ADD_BOOK_WIDGET_H

#include <QCheckBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QWidget>

namespace Ui {
class AddBookWidget;
}

class AddBookWidget: public QWidget {
    Q_OBJECT

  public:
    explicit AddBookWidget(QWidget* parent = nullptr);
    ~AddBookWidget();
    const QLineEdit* get_title_line() const;
    const QLineEdit* get_writers_line() const;
    const QLineEdit* get_illustrators_line() const;

  public slots:
    void clear();

  private:
    Ui::AddBookWidget* ui;

    QFormLayout* form_layout;

    QWidget* form_widget;
    QLineEdit* title_line;
    QLineEdit* writers_line;
    QLineEdit* illustrators_line;
    QCheckBox* check_box;

  private slots:
    void writer_illustrator(int state);
    void copy_writer_to_illustrator();
};

#endif  // ADD_BOOK_WIDGET_H
