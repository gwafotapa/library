#ifndef ADD_WIDGET_H
#define ADD_WIDGET_H

#include <QBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QStackedWidget>
#include <QWidget>

#include "../add_author_widget/add_author_widget.h"
#include "../add_book_widget/add_book_widget.h"
#include "../datamodel/datamodel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class AddWidget;
}
QT_END_NAMESPACE

class AddWidget: public QWidget {
    Q_OBJECT

  public:
    explicit AddWidget(DataModel* data_model, QWidget* parent = nullptr);
    ~AddWidget() override;

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
};

#endif  // ADD_WIDGET_H
