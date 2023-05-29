#include "add_book_widget.h"

#include <qpushbutton.h>

#include <QCheckBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QStyle>

#include "ui_add_book_widget.h"

AddBookWidget::AddBookWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::AddBookWidget) {
    ui->setupUi(this);

    title_line = new QLineEdit;
    title_line->setClearButtonEnabled(true);
    writers_line = new QLineEdit;
    writers_line->setPlaceholderText("Writer1, Writer2, ...");
    writers_line->setClearButtonEnabled(true);
    illustrators_line = new QLineEdit;
    illustrators_line->setPlaceholderText("Illustrator1, Illustrator2, ...");
    illustrators_line->setClearButtonEnabled(true);
    check_box = new QCheckBox;
    add_button = new QPushButton("Add");
    clear_button = new QPushButton("Clear");

    form_layout = new QFormLayout;
    form_layout->addRow("Title", title_line);
    form_layout->addRow("Writers", writers_line);
    form_layout->addRow("Illustrators", illustrators_line);
    form_layout->addRow("Writer / Illustrator", check_box);

    buttons_layout = new QHBoxLayout;
    buttons_layout->addWidget(add_button);
    buttons_layout->addWidget(clear_button);

    main_layout = new QVBoxLayout;
    main_layout->addLayout(form_layout);
    main_layout->addLayout(buttons_layout);
    main_layout->addStretch();
    setLayout(main_layout);

    set_add_book_mode(0);

    connect(
        check_box,
        &QCheckBox::stateChanged,
        this,
        &AddBookWidget::writer_illustrator);

    connect(clear_button, &QPushButton::clicked, this, &AddBookWidget::clear);
}

AddBookWidget::~AddBookWidget() {
    delete ui;
}

void AddBookWidget::set_add_book_mode(int mode) {
    switch (mode) {
        case 0:  // Add book
            form_layout->setRowVisible(2, false);
            form_layout->setRowVisible(3, false);
            break;
        case 1:  // Add comic book
            form_layout->setRowVisible(2, true);
            form_layout->setRowVisible(3, true);
            break;
    }
}

void AddBookWidget::writer_illustrator(int state) {
    if (state == Qt::Checked) {
        // TODO: factorize read only palette
        QPalette read_only_palette;
        read_only_palette.setColor(QPalette::Base, Qt::lightGray);
        read_only_palette.setColor(QPalette::Text, Qt::darkGray);

        illustrators_line->setReadOnly(true);
        illustrators_line->setPalette(read_only_palette);
        copy_writer_to_illustrator();

        connect(
            writers_line,
            &QLineEdit::textEdited,
            this,
            &AddBookWidget::copy_writer_to_illustrator);
    } else {
        illustrators_line->setReadOnly(false);
        illustrators_line->setPalette(QApplication::style()->standardPalette());

        disconnect(
            writers_line,
            &QLineEdit::textEdited,
            this,
            &AddBookWidget::copy_writer_to_illustrator);
    }
}

void AddBookWidget::copy_writer_to_illustrator() {
    illustrators_line->setText(writers_line->text());
}

void AddBookWidget::clear() {
    title_line->clear();
    writers_line->clear();
    illustrators_line->clear();
    check_box->setChecked(false);
}
