//
// Created by Administrateur on 26/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ButtonsWidget.h" resolved

#include "buttonswidget.h"

#include "ui_ButtonsWidget.h"

ButtonsWidget::ButtonsWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ButtonsWidget) {
    ui->setupUi(this);
}

ButtonsWidget::~ButtonsWidget() {
    delete ui;
}
