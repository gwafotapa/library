#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <qboxlayout.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <qformlayout.h>
#include <qpushbutton.h>
#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class SearchWidget;
}
QT_END_NAMESPACE

class SearchWidget: public QWidget {
    Q_OBJECT

  public:
    explicit SearchWidget(QWidget* parent = nullptr);
    ~SearchWidget() override;

    QPushButton* get_search_button() const;
    void regular_book_search() const;
    void comic_book_search() const;

  private:
    Ui::SearchWidget* ui;
    QFormLayout* form_layout;

    QComboBox* combo_box;
    QLineEdit* title_line;
    QLineEdit* writers_line;
    QLineEdit* cb_writers_line;
    QLineEdit* cb_illustrators_line;
    QPushButton* search_button;

  private slots:
    void select_search(int index);
};

#endif  // SEARCHWIDGET_H
