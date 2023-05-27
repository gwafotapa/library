#include "buttonswidget.h"

#include <qboxlayout.h>
#include <qpushbutton.h>

#include "ui_buttonswidget.h"

ButtonsWidget::ButtonsWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ButtonsWidget) {
    ui->setupUi(this);
    add_button = new QPushButton("Add");
    search_button = new QPushButton("Search");

    h_box_layout = new QHBoxLayout(this);
    h_box_layout->addWidget(add_button);
    h_box_layout->addWidget(search_button);
}

ButtonsWidget::~ButtonsWidget() {
    delete ui;
}
