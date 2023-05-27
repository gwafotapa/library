#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QTableView>
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

    QTableView* get_table_view() const;

  private:
    Ui::TableWidget* ui;
    QTableView* table_view;
};

#endif  // TABLEWIDGET_H
