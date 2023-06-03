#include "search_widget.h"

#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qsizepolicy.h>

#include <QBoxLayout>
#include <QComboBox>
#include <QFormLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QWidget>

#include "data_model.h"
#include "ui_search_widget.h"

SearchWidget::SearchWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::SearchWidget) {
    ui->setupUi(this);

    combo_box = new QComboBox;
    combo_box->addItem("Standard books and writers");
    combo_box->addItem("Comic books, writers and illustrators");

    title_line = new QLineEdit;
    title_line->setClearButtonEnabled(true);

    writers_line = new QLineEdit;
    writers_line->setClearButtonEnabled(true);
    writers_line->setPlaceholderText("Writer1, Writer2, ...");

    illustrators_line = new QLineEdit;
    illustrators_line->setClearButtonEnabled(true);
    illustrators_line->setPlaceholderText("Illustrator1, Illustrator2, ...");
    QSizePolicy retain = illustrators_line->sizePolicy();
    retain.setRetainSizeWhenHidden(true);
    illustrators_line->setSizePolicy(retain);

    search_button = new QPushButton("Search");
    clear_button = new QPushButton("Clear");

    results_label = new QLabel;

    data_model = new DataModel("search widget", this);
    table_view = new QTableView;
    table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table_view->setSortingEnabled(true);
    table_view->setModel(data_model);

    form_layout = new QFormLayout;
    form_layout->addRow("Title", title_line);
    form_layout->addRow("Writers", writers_line);
    form_layout->addRow("Illustrators", illustrators_line);
    // form_layout->addRow(illustrators_line);

    // illustrators_widget = new LabelLineEdit("Illustrators");
    // QSizePolicy retain = illustrators_widget->sizePolicy();
    // retain.setRetainSizeWhenHidden(true);
    // illustrators_widget->setSizePolicy(retain);

    buttons_layout = new QHBoxLayout;
    buttons_layout->addWidget(search_button);
    buttons_layout->addWidget(clear_button);

    main_layout = new QVBoxLayout;
    main_layout->addWidget(combo_box);
    main_layout->addLayout(form_layout);
    // main_layout->addWidget(illustrators_widget);
    main_layout->addLayout(buttons_layout);
    main_layout->addWidget(results_label);
    main_layout->addWidget(table_view);
    // main_layout->addStretch();
    setLayout(main_layout);

    select_search(0);

    connect(
        combo_box,
        static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        this,
        &SearchWidget::select_search);

    // connect(
    //     this,
    //     &SearchWidget::select_table,
    //     data_model,
    //     &DataModel::select_table);
    connect(
        this,
        &SearchWidget::search_standard_books,
        data_model,
        &DataModel::search_standard_books);
    connect(
        this,
        &SearchWidget::search_comic_books,
        data_model,
        &DataModel::search_comic_books);

    connect(clear_button, &QPushButton::clicked, this, &SearchWidget::clear);

    // connect(
    //     search_button,
    //     &QPushButton::clicked,
    //     this,
    //     &SearchWidget::set_results_label);
}

SearchWidget::~SearchWidget() {
    delete ui;
}

// QComboBox* SearchWidget::get_combo_box() const {
//     return combo_box;
// }

// QPushButton* SearchWidget::get_search_button() const {
//     return search_button;
// }

void SearchWidget::select_search(int book_type) {
    data_model->clear();
    results_label->clear();
    disconnect(search_button, &QPushButton::clicked, this, nullptr);
    switch (book_type) {
        case 0:  // Non-comic book and writers
            // form_layout->takeRow(2);
            // main_layout->takeAt(3);
            form_layout->setRowVisible(2, false);
            // form_layout->setRowVisible(3, false);
            // illustrators_widget->hide();
            // emit select_table(
            //     "Standard Books");  // TODO: replace the constant, necessary ?
            connect(search_button, &QPushButton::clicked, [&]() {
                emit search_standard_books(
                    title_line->text(),
                    writers_line->text());
                set_results_label();
            });
            // data_model->setTable("Books");
            // data_model->select();
            break;
        case 1:  // Comic books, writers and illustrators
            // form_layout->addRow(illustrators_line);
            form_layout->setRowVisible(2, true);
            // form_layout->setRowVisible(3, true);
            // illustrators_widget->show();
            // emit select_table("Comic Books");  // TODO: Necessary ?
            connect(search_button, &QPushButton::clicked, [&]() {
                emit search_comic_books(
                    title_line->text(),
                    writers_line->text(),
                    illustrators_line->text());
                set_results_label();
            });
            // data_model->setTable("Comic Books");
            // data_model->select();
            break;
    }
}

void SearchWidget::clear() {
    title_line->clear();
    writers_line->clear();
    illustrators_line->clear();
}

// void SearchWidget::search_books_and_writers() const {
//     QString title = title_line->text();
//     QString writers = writers_line->text();
// data_model->search_books_and_writers(title, writers);
// }

// void SearchWidget::search_comic_books_and_authors() const {
//     QString title = title_line->text();
//     QString writers = writers_line->text();
//     QString illustrators = illustrators_line->text();
// data_model->search_comic_books_and_authors(title, writers, illustrators);
// }

void SearchWidget::set_results_label() {
    int rows = table_view->model()->rowCount();
    // int rows = data_model->rowCount();
    switch (rows) {
        case 0:
            results_label->setText("No results found");
            break;
        case 1:
            results_label->setText("1 result found");
            break;
        default:
            results_label->setText(QString::number(rows) + " results found");
    }
}
