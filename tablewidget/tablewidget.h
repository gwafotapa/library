#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

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

#endif  // TABLEWIDGET_H
