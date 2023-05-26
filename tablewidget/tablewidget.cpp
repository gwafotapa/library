//
// Created by Administrateur on 26/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TableWidget.h" resolved

#include "tablewidget.h"

#include "ui_TableWidget.h"

TableWidget::TableWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::TableWidget) {
    ui->setupUi(this);
}

TableWidget::~TableWidget() {
    delete ui;
}
