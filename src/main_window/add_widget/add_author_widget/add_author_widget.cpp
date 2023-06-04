#include "add_author_widget.h"

#include <QCheckBox>
#include <QFormLayout>
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

    form_layout = new QFormLayout;
    form_layout->addRow("Name", name_line);
    form_layout->addWidget(writer);
    form_layout->addWidget(comic_book_writer);
    form_layout->addWidget(illustrator);

    setLayout(form_layout);
}

AddAuthorWidget::~AddAuthorWidget() {
    delete ui;
}

const QLineEdit* AddAuthorWidget::get_name_line() const {
    return name_line;
}

const QCheckBox* AddAuthorWidget::get_writer() const {
    return writer;
}

const QCheckBox* AddAuthorWidget::get_comic_book_writer() const {
    return comic_book_writer;
}

const QCheckBox* AddAuthorWidget::get_illustrator() const {
    return illustrator;
}

void AddAuthorWidget::clear() {
    name_line->clear();
    writer->setChecked(false);
    comic_book_writer->setChecked(false);
    illustrator->setChecked(false);
}
