#include "add_author_widget.h"

#include <qpushbutton.h>
#include <qsizepolicy.h>

#include <QCheckBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QSizePolicy>

#include "comic_book_writer.h"
#include "ui_add_author_widget.h"

AddAuthorWidget::AddAuthorWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::AddAuthorWidget) {
    ui->setupUi(this);

    name_line = new QLineEdit;
    name_line->setClearButtonEnabled(true);
    writer = new QCheckBox("Writer");
    comic_book_writer = new QCheckBox("Comic book writer");
    illustrator = new QCheckBox("Comic book illustrator");
    // add_button = new QPushButton("Add");
    // clear_button = new QPushButton("Clear");
    // message = new QLabel;

    form_layout = new QFormLayout;
    // form_layout->setSizeConstraint(QLayout::SetFixedSize);
    form_layout->addRow("Name", name_line);
    form_layout->addWidget(writer);
    form_layout->addWidget(comic_book_writer);
    form_layout->addWidget(illustrator);

    // buttons_layout = new QHBoxLayout;
    // buttons_layout->addWidget(add_button);
    // buttons_layout->addWidget(clear_button);

    // main_layout = new QVBoxLayout;
    // main_layout->addLayout(form_layout);
    // main_layout->addLayout(buttons_layout);
    // main_layout->addWidget(message);
    // main_layout->addStretch();
    setLayout(form_layout);

    // connect(clear_button, &QPushButton::clicked, this, &AddAuthorWidget::clear);

    // connect(add_button, &QPushButton::clicked, [&]() {
    //     QString name = name_line->text().simplified();
    //     if (name.isEmpty()) {
    //         message->setText("Error: blank author");
    //         message->setStyleSheet("QLabel { color : red; }");
    //         return;
    //     }
    //     if (!writer->isChecked() && !comic_book_writer->isChecked()
    //         && !illustrator->isChecked()) {
    //         message->setText("Error: all boxes unchecked");
    //         message->setStyleSheet("QLabel { color : red; }");
    //         return;
    //     }
    //     message->clear();
    //     if (writer->isChecked()) {
    //         emit add_writer(Writer(name));
    //     }
    //     if (comic_book_writer->isChecked()) {
    //         emit add_comic_book_writer(ComicBookWriter(name));
    //     }
    //     if (illustrator->isChecked()) {
    //         emit add_illustrator(Illustrator(name));
    //     }
    // });
}

AddAuthorWidget::~AddAuthorWidget() {
    delete ui;
}

QLineEdit* AddAuthorWidget::get_name_line() const {
    return name_line;
}

QCheckBox* AddAuthorWidget::get_writer() const {
    return writer;
}

QCheckBox* AddAuthorWidget::get_comic_book_writer() const {
    return comic_book_writer;
}

QCheckBox* AddAuthorWidget::get_illustrator() const {
    return illustrator;
}

void AddAuthorWidget::clear() {
    name_line->clear();
    writer->setChecked(false);
    comic_book_writer->setChecked(false);
    illustrator->setChecked(false);
}
