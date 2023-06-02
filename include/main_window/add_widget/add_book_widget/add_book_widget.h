#ifndef ADD_BOOK_WIDGET_H
#define ADD_BOOK_WIDGET_H

#include <qboxlayout.h>

#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QWidget>

#include "comic_book.h"
#include "comic_book_writer.h"
#include "data_model.h"
#include "standard_book.h"

namespace Ui {
class AddBookWidget;
}

class AddBookWidget: public QWidget {
    Q_OBJECT

  public:
    explicit AddBookWidget(DataModel* data_model, QWidget* parent = nullptr);
    ~AddBookWidget();

  public slots:
    void select_book_type(int book_type);
    void book_added(const Book& book) const;

  signals:
    void add_standard_book(const StandardBook& book);
    void add_comic_book(const ComicBook& book);
    void add_author(const Author& author);  // TODO: useful ?
    void add_writer(const Writer& writer);
    void add_writers(const QList<Writer>& writers);
    void add_comic_book_writer(const ComicBookWriter& writer);
    void add_comic_book_writers(const QList<ComicBookWriter>& writers);
    void add_illustrator(const Illustrator& illustrator);
    void add_illustrators(const QList<Illustrator>& illustrators);

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
    QLabel* message;
    QTableView* table_view;
    DataModel* data_model;

  private slots:
    void writer_illustrator(int state);
    void copy_writer_to_illustrator();
    void clear();
    // void add_book_and_writers();
    // void add_comic_book_and_authors();
};

#endif  // ADD_BOOK_WIDGET_H
