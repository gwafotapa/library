#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <qboxlayout.h>
#include <qcheckbox.h>
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

    bool title_checked() const;
    bool authors_checked() const;
    QPushButton* get_search_button() const;

  private:
    Ui::SearchWidget* ui;
    QHBoxLayout* h_box_layout;
    QCheckBox* title_checkbox;
    QCheckBox* authors_checkbox;
    QPushButton* search_button;
};

#endif  // SEARCHWIDGET_H
