#include "add_std_book_widget.h"

#include "ui_add_std_book_widget.h"

AddStdBookWidget::AddStdBookWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::AddStdBookWidget) {
    ui->setupUi(this);

    title_line = new QLineEdit;
    writers_line = new QLineEdit;
    writers_line->setPlaceholderText("Writer1, Writer2, ...");

    form_layout = new QFormLayout(this);
    form_layout->addRow("Title", title_line);
    form_layout->addRow("Writers", writers_line);
}

AddStdBookWidget::~AddStdBookWidget() {
    delete ui;
}
