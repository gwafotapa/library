#ifndef ADD_WIDGET_H
#define ADD_WIDGET_H

#include <QBoxLayout>
#include <QComboBox>
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
    AddBookWidget* book() const;
    AddAuthorWidget* author() const;

  private:
    Ui::AddWidget* ui;
    QVBoxLayout* main_layout;
    QHBoxLayout* buttons_layout;
    QComboBox* combo_box;
    QStackedWidget* stacked_widget;
    AddBookWidget* add_book_widget;
    AddAuthorWidget* add_author_widget;
    // QPushButton* add_button;
    // QPushButton* clear_button;
    QTableView* table_view;
    DataModel* data_model;
};

#endif  // ADD_WIDGET_H
