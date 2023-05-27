#include "formwidget.h"

#include <qformlayout.h>
#include <qlineedit.h>

#include "ui_formwidget.h"

FormWidget::FormWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::FormWidget) {
    ui->setupUi(this);

    title_line = new QLineEdit;
    authors_line = new QLineEdit;
    authors_line->setPlaceholderText("Author1, Author2, ...");

    form_layout = new QFormLayout(this);
    form_layout->addRow("Title", title_line);
    form_layout->addRow("Authors", authors_line);
}

FormWidget::~FormWidget() {
    delete ui;
}
