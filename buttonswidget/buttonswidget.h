//
// Created by Administrateur on 26/05/2023.
//

#ifndef LIBRARY_BUTTONSWIDGET_H
#define LIBRARY_BUTTONSWIDGET_H

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

  private:
    Ui::ButtonsWidget* ui;
    QHBoxLayout* h_box_layout;
    QPushButton* add_button;
    QPushButton* search_button;
};

#endif  //LIBRARY_BUTTONSWIDGET_H
