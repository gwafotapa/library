#include "searchwidget.h"

#include <qpushbutton.h>

#include <QBoxLayout>
#include <QComboBox>
#include <QFormLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QWidget>

#include "../datamodel/datamodel.h"
#include "ui_searchwidget.h"

SearchWidget::SearchWidget(DataModel* data_model, QWidget* parent) :
    QWidget(parent),
    ui(new Ui::SearchWidget) {
    ui->setupUi(this);

    combo_box = new QComboBox;
    combo_box->addItem("Non-comic books and writers");
    combo_box->addItem("Comic books, writers and illustrators");

    title_line = new QLineEdit;
    title_line->setClearButtonEnabled(true);

    writers_line = new QLineEdit;
    writers_line->setClearButtonEnabled(true);
    writers_line->setPlaceholderText("Writer1, Writer2, ...");

    illustrators_line = new QLineEdit;
    illustrators_line->setClearButtonEnabled(true);
    illustrators_line->setPlaceholderText("Illustrator1, Illustrator2, ...");

    search_button = new QPushButton("Search");
    clear_button = new QPushButton("Clear");

    search_log = new QLabel;
    table_view = new QTableView;
    table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table_view->setSortingEnabled(true);
    table_view->setModel(data_model);
    this->data_model = data_model;

    form_layout = new QFormLayout;
    form_layout->addRow("Title", title_line);
    form_layout->addRow("Writers", writers_line);
    form_layout->addRow("Illustrators", illustrators_line);

    buttons_layout = new QHBoxLayout;
    buttons_layout->addWidget(search_button);
    buttons_layout->addWidget(clear_button);

    main_layout = new QVBoxLayout;
    main_layout->addWidget(combo_box);
    main_layout->addLayout(form_layout);
    main_layout->addLayout(buttons_layout);
    main_layout->addWidget(search_log);
    main_layout->addWidget(table_view);
    // main_layout->addStretch();
    setLayout(main_layout);

    select_search(0);

    connect(
        combo_box,
        static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        this,
        &SearchWidget::select_search);

    connect(clear_button, &QPushButton::clicked, this, &SearchWidget::clear);

    connect(
        search_button,
        &QPushButton::clicked,
        this,
        &SearchWidget::update_search_log);
}

SearchWidget::~SearchWidget() {
    delete ui;
}

// QPushButton* SearchWidget::get_search_button() const {
//     return search_button;
// }

void SearchWidget::select_search(int book_type) {
    switch (book_type) {
        case 0:
            form_layout->setRowVisible(2, false);
            connect(
                search_button,
                &QPushButton::clicked,
                this,
                &SearchWidget::search_books_and_writers);
            disconnect(
                search_button,
                &QPushButton::clicked,
                this,
                &SearchWidget::search_comic_books_and_authors);
            data_model->setTable("Books");
            data_model->select();
            break;
        case 1:
            form_layout->setRowVisible(2, true);
            connect(
                search_button,
                &QPushButton::clicked,
                this,
                &SearchWidget::search_comic_books_and_authors);
            disconnect(
                search_button,
                &QPushButton::clicked,
                this,
                &SearchWidget::search_books_and_writers);
            data_model->setTable("Comic Books");
            data_model->select();
            break;
    }
}

void SearchWidget::clear() {
    title_line->clear();
    writers_line->clear();
    illustrators_line->clear();
}

void SearchWidget::search_books_and_writers() const {
    QString title = title_line->text();
    QString writers = writers_line->text();
    data_model->search_books_and_writers(title, writers);
}

void SearchWidget::search_comic_books_and_authors() const {
    QString title = title_line->text();
    QString writers = writers_line->text();
    QString illustrators = illustrators_line->text();
    data_model->search_comic_books_and_authors(title, writers, illustrators);
}

void SearchWidget::update_search_log() {
    int rows = data_model->rowCount();
    switch (rows) {
        case 0:
            search_log->setText("No results found");
            break;
        case 1:
            search_log->setText("1 result found");
            break;
        default:
            search_log->setText(QString::number(rows) + " results found");
    }
}
