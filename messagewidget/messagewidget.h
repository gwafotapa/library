//
// Created by Administrateur on 27/05/2023.
//

#ifndef LIBRARY_MESSAGEWIDGET_H
#define LIBRARY_MESSAGEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MessageWidget;
}
QT_END_NAMESPACE

class MessageWidget: public QWidget {
    Q_OBJECT

  public:
    explicit MessageWidget(QWidget* parent = nullptr);
    ~MessageWidget() override;

  private:
    Ui::MessageWidget* ui;
};

#endif  //LIBRARY_MESSAGEWIDGET_H
