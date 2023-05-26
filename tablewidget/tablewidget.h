//
// Created by Administrateur on 26/05/2023.
//

#ifndef LIBRARY_TABLEWIDGET_H
#define LIBRARY_TABLEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class TableWidget;
}
QT_END_NAMESPACE

class TableWidget: public QWidget {
    Q_OBJECT

  public:
    explicit TableWidget(QWidget* parent = nullptr);
    ~TableWidget() override;

  private:
    Ui::TableWidget* ui;
};

#endif  //LIBRARY_TABLEWIDGET_H
