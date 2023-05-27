//
// Created by Administrateur on 27/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MessageWidget.h" resolved

#include "messagewidget.h"

#include "ui_messagewidget.h"

MessageWidget::MessageWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MessageWidget) {
    ui->setupUi(this);
}

MessageWidget::~MessageWidget() {
    delete ui;
}
