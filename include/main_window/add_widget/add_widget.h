#ifndef ADD_WIDGET_H
#define ADD_WIDGET_H

#include <QBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QTableView>
#include <QWidget>

#include "add_author_widget.h"
#include "add_book_widget.h"
#include "data_model.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class AddWidget;
}
QT_END_NAMESPACE

class AddWidget: public QWidget {
    Q_OBJECT

  public:
    explicit AddWidget(QWidget* parent = nullptr);
    ~AddWidget() override;
    // QComboBox* get_combo_box() const;
    AddBookWidget* book_widget() const;
    AddAuthorWidget* author_widget() const;

  public slots:
    void book_added(const Book& book) const;
    void book_exists(const Book& book) const;
    void author_added(const Author*) const;
    void author_exists(const Author& author) const;

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
    Ui::AddWidget* ui;
    QVBoxLayout* main_layout;
    QHBoxLayout* buttons_layout;
    QComboBox* combo_box;
    QStackedWidget* stacked_widget;
    AddBookWidget* add_book_widget;
    AddAuthorWidget* add_author_widget;
    QPushButton* add_button;
    QPushButton* clear_button;
    QLabel* message;
    DataModel* data_model;
#ifndef NDEBUG
    QTableView* table_view;
#endif

    void book_page();
    void comic_book_page();
    void author_page();

    const QString message_std_style = "background-color: white; color: black";
    const QString message_err_style = "background-color: white; color: red";
};

#endif  // ADD_WIDGET_H
