#ifndef BUTTONSWIDGET_H
#define BUTTONSWIDGET_H

#include <qpushbutton.h>

#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ButtonsWidget;
}
QT_END_NAMESPACE

class ButtonsWidget: public QWidget {
    Q_OBJECT

  public:
    explicit ButtonsWidget(QWidget* parent = nullptr);
    ~ButtonsWidget() override;

    QPushButton* get_add_button() const;
    QPushButton* get_search_button() const;

  private:
    Ui::ButtonsWidget* ui;
    QHBoxLayout* h_box_layout;
    QPushButton* add_button;
    QPushButton* search_button;
};

#endif  // BUTTONSWIDGET_H
