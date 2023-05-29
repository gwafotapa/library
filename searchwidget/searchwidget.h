#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QComboBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

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
    void non_comic_book_search() const;
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
    QPushButton* clear_button;

  private slots:
    void select_search(int index);
    void clear_fields();
};

#endif  // SEARCHWIDGET_H
