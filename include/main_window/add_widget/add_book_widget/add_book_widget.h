#ifndef ADD_BOOK_WIDGET_H
#define ADD_BOOK_WIDGET_H

#include <QCheckBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QWidget>

#include "comic_book.h"
#include "comic_book_writer.h"
#include "standard_book.h"

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
    //   void select_book_type(int book_type);

  private:
    Ui::AddBookWidget* ui;

    // QVBoxLayout* main_layout;
    QFormLayout* form_layout;
    // QHBoxLayout* buttons_layout;

    QWidget* form_widget;
    QLineEdit* title_line;
    QLineEdit* writers_line;
    QLineEdit* illustrators_line;
    QCheckBox* check_box;
    // QPushButton* add_button;
    // QPushButton* clear_button;

  private slots:
    void writer_illustrator(int state);
    void copy_writer_to_illustrator();
    // void add_book_and_writers();
    // void add_comic_book_and_authors();
};

#endif  // ADD_BOOK_WIDGET_H
