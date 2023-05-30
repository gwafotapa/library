#include "add_book_widget.h"

#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qtableview.h>

#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QStyle>

#include "../datamodel/datamodel.h"
#include "ui_add_book_widget.h"

AddBookWidget::AddBookWidget(DataModel* data_model, QWidget* parent) :
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
    check_box = new QCheckBox("Writers / Illustrators");
    add_button = new QPushButton("Add");
    clear_button = new QPushButton("Clear");

    form_layout = new QFormLayout;
    form_layout->addRow("Title", title_line);
    form_layout->addRow("Writers", writers_line);
    form_layout->addRow("Illustrators", illustrators_line);
    form_layout->addRow("", check_box);

    buttons_layout = new QHBoxLayout;
    buttons_layout->addWidget(add_button);
    buttons_layout->addWidget(clear_button);

    table_view = new QTableView;
    table_view->setModel(data_model);
    this->data_model = data_model;

    main_layout = new QVBoxLayout;
    main_layout->addLayout(form_layout);
    main_layout->addLayout(buttons_layout);
    main_layout->addWidget(table_view);
    main_layout->addStretch();
    setLayout(main_layout);

    set_book_type(0);

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

void AddBookWidget::set_book_type(int book_type) {
    switch (book_type) {
        case 0:
            form_layout->setRowVisible(2, false);
            form_layout->setRowVisible(3, false);
            connect(
                add_button,
                &QPushButton::clicked,
                this,
                &AddBookWidget::add_book_and_writers);
            disconnect(
                add_button,
                &QPushButton::clicked,
                this,
                &AddBookWidget::add_comic_book_and_authors);
            data_model->setTable("Books");
            data_model->select();
            break;
        case 1:
            form_layout->setRowVisible(2, true);
            form_layout->setRowVisible(3, true);
            connect(
                add_button,
                &QPushButton::clicked,
                this,
                &AddBookWidget::add_comic_book_and_authors);
            disconnect(
                add_button,
                &QPushButton::clicked,
                this,
                &AddBookWidget::add_book_and_writers);
            data_model->setTable("Comic Books");
            data_model->select();
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

void AddBookWidget::add_book_and_writers() {
    QString writers = writers_line->text();
    QStringList writer_list = writers.split(u',');
    data_model->add_writers(writer_list);

    QString title = title_line->text();
    data_model->add_book(title, writers);
}

void AddBookWidget::add_comic_book_and_authors() {
    QString writers = writers_line->text();
    QStringList writer_list = writers.split(u',');
    data_model->add_comic_book_writers(writer_list);

    QString illustrators = illustrators_line->text();
    QStringList illustrator_list = illustrators.split(u',');
    data_model->add_illustrators(illustrator_list);

    QString title = title_line->text();
    data_model->add_comic_book(title, writers, illustrators);
}
