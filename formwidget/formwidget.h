//
// Created by Administrateur on 26/05/2023.
//

#ifndef LIBRARY_FORMWIDGET_H
#define LIBRARY_FORMWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class FormWidget;
}
QT_END_NAMESPACE

class FormWidget: public QWidget {
    Q_OBJECT

  public:
    explicit FormWidget(QWidget* parent = nullptr);
    ~FormWidget() override;

  private:
    Ui::FormWidget* ui;
};

#endif  //LIBRARY_FORMWIDGET_H
