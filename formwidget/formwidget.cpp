//
// Created by Administrateur on 26/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FormWidget.h" resolved

#include "formwidget.h"

#include "ui_FormWidget.h"

FormWidget::FormWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::FormWidget) {
    ui->setupUi(this);
}

FormWidget::~FormWidget() {
    delete ui;
}
