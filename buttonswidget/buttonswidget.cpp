#include "buttonswidget.h"

#include "ui_buttonswidget.h"

ButtonsWidget::ButtonsWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ButtonsWidget) {
    ui->setupUi(this);
}

ButtonsWidget::~ButtonsWidget() {
    delete ui;
}
