#include "searchwidget.h"

#include <qboxlayout.h>
#include <qcheckbox.h>
#include <qpushbutton.h>

#include "ui_searchwidget.h"

SearchWidget::SearchWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::SearchWidget) {
    ui->setupUi(this);

    title_checkbox = new QCheckBox("Title");
    title_checkbox->setChecked(true);
    authors_checkbox = new QCheckBox("Authors");
    authors_checkbox->setChecked(true);
    search_button = new QPushButton("Search");

    h_box_layout = new QHBoxLayout(this);
    h_box_layout->addWidget(title_checkbox);
    h_box_layout->addWidget(authors_checkbox);
    h_box_layout->addWidget(search_button);
}

SearchWidget::~SearchWidget() {
    delete ui;
}

bool SearchWidget::title_checked() const {
    return title_checkbox->isChecked();
}

bool SearchWidget::authors_checked() const {
    return authors_checkbox->isChecked();
}

QPushButton* SearchWidget::get_search_button() const {
    return search_button;
}
