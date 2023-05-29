#include "add_author_widget.h"

#include <QCheckBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>

#include "ui_add_author_widget.h"

AddAuthorWidget::AddAuthorWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::AddAuthorWidget) {
    ui->setupUi(this);

    name_line = new QLineEdit;
    writer = new QCheckBox("Writer");
    comic_book_writer = new QCheckBox("Comic book writer");
    illustrator = new QCheckBox("Comic book illustrator");

    form_layout = new QFormLayout(this);
    form_layout->addRow("Name", name_line);
    form_layout->addWidget(writer);
    form_layout->addWidget(comic_book_writer);
    form_layout->addWidget(illustrator);
}

AddAuthorWidget::~AddAuthorWidget() {
    delete ui;
}
