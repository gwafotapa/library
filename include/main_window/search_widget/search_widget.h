#ifndef SEARCH_WIDGET_H
#define SEARCH_WIDGET_H

#include <QBoxLayout>
#include <QComboBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QWidget>

#include "data_model.h"

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

  signals:
    void search_standard_books(const QString& title, const QString& writers);
    void search_comic_books(
        const QString& title,
        const QString& writers,
        const QString& illustrators);

  private:
    Ui::SearchWidget* ui;

    QVBoxLayout* main_layout;
    QFormLayout* form_layout;
    QHBoxLayout* buttons_layout;

    QComboBox* combo_box;
    QWidget* form_widget;
    QLineEdit* title_line;
    QLineEdit* writers_line;
    QLineEdit* illustrators_line;
    QPushButton* search_button;
    QPushButton* clear_button;
    QLabel* results_label;
    DataModel* data_model;
    QTableView* table_view;

  private slots:
    void select_search(int book_type);
    void clear();
    void set_results_label();
};

#endif  // SEARCH_WIDGET_H
