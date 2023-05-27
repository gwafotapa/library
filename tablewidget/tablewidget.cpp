#include "tablewidget.h"

#include <qtableview.h>

#include "ui_tablewidget.h"

TableWidget::TableWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::TableWidget) {
    ui->setupUi(this);
    table_view = new QTableView(this);
}

TableWidget::~TableWidget() {
    delete ui;
}

QTableView* TableWidget::get_table_view() const {
    return table_view;
}
