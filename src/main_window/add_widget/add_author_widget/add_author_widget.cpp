#include "add_author_widget.h"

#include <qpushbutton.h>
#include <qsizepolicy.h>

#include <QCheckBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QSizePolicy>

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
    add_button = new QPushButton("Add");
    clear_button = new QPushButton("Clear");

    form_layout = new QFormLayout;
    // form_layout->setSizeConstraint(QLayout::SetFixedSize);
    form_layout->addRow("Name", name_line);
    form_layout->addWidget(writer);
    form_layout->addWidget(comic_book_writer);
    form_layout->addWidget(illustrator);

    buttons_layout = new QHBoxLayout;
    buttons_layout->addWidget(add_button);
    buttons_layout->addWidget(clear_button);

    main_layout = new QVBoxLayout;
    main_layout->addLayout(form_layout);
    main_layout->addLayout(buttons_layout);
    main_layout->addStretch();
    setLayout(main_layout);

    connect(clear_button, &QPushButton::clicked, this, &AddAuthorWidget::clear);

    // assert(main_layout->setStretchFactor(form_layout, 1));
    // assert(main_layout->setStretchFactor(buttons_layout, 10));

    // main_layout->setStretchFactor(setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed));
}

AddAuthorWidget::~AddAuthorWidget() {
    delete ui;
}

void AddAuthorWidget::clear() {
    name_line->clear();
    writer->setChecked(false);
    comic_book_writer->setChecked(false);
    illustrator->setChecked(false);
}
