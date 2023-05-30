#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QBoxLayout>
#include <QComboBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QWidget>

#include "../datamodel/datamodel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class SearchWidget;
}
QT_END_NAMESPACE

class SearchWidget: public QWidget {
    Q_OBJECT

  public:
    explicit SearchWidget(DataModel* data_model, QWidget* parent = nullptr);
    ~SearchWidget() override;

    // QPushButton* get_search_button() const;
    void search_books_and_writers() const;
    void search_comic_books_and_authors() const;

  private:
    Ui::SearchWidget* ui;
    QVBoxLayout* main_layout;
    QFormLayout* form_layout;
    QHBoxLayout* buttons_layout;

    QComboBox* combo_box;
    QLineEdit* title_line;
    QLineEdit* writers_line;
    QLineEdit* illustrators_line;
    QPushButton* search_button;
    QPushButton* clear_button;
    QTableView* table_view;
    DataModel* data_model;

  private slots:
    void select_search(int book_type);
    void clear();
};

#endif  // SEARCHWIDGET_H
