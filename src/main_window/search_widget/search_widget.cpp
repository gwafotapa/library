#include "search_widget.h"

#include <qboxlayout.h>
#include <qnamespace.h>
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
    // title_line->setClearButtonEnabled(true);
    // title_line->setStyleSheet("background-color: whitesmoke");
    // title_line->setFixedSize(title_line->sizeHint());

    writers_line = new QLineEdit;
    // writers_line->setClearButtonEnabled(true);
    writers_line->setPlaceholderText("Writer1, Writer2, ...");

    illustrators_line = new QLineEdit;
    // illustrators_line->setClearButtonEnabled(true);
    illustrators_line->setPlaceholderText("Illustrator1, Illustrator2, ...");
    // QSizePolicy retain = illustrators_line->sizePolicy();
    // retain.setRetainSizeWhenHidden(true);
    // illustrators_line->setSizePolicy(retain);
    // illustrators_line->setFixedHeight(illustrators_line->sizeHint().height());

    search_button = new QPushButton("Search");
    search_button->setSizePolicy(
        QSizePolicy::Expanding,
        QSizePolicy::Expanding);
    search_button->setMaximumSize(300, 50);
    // search_button->setStyleSheet("max-width: 250; max-height: 50; color: blue");
    // search_button->setMinimumSize(
    // 2 * search_button->width(),
    // 3 * search_button->height());
    // 150,
    // 100);
    // search_button->setFixedSize(
    //     2 * search_button->width(),
    //     3 * search_button->height());
    clear_button = new QPushButton("Clear");
    // clear_button->resize(clear_button->width(), 3 * clear_button->height());
    clear_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // clear_button->setMaximumSize(300, 50);
    // clear_button->setStyleSheet("max-width: 250; max-height: 50; color: blue");

    results_label = new QLabel;

    data_model = new DataModel("search widget", this);
    table_view = new QTableView;
    table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table_view->horizontalHeader()->setStyleSheet("color: blue");
    table_view->setStyleSheet("selection-background-color: blue");
    table_view->setSortingEnabled(true);
    table_view->setModel(data_model);

    form_layout = new QFormLayout;
    form_layout->setLabelAlignment(Qt::AlignHCenter);
    form_layout->addRow("Title", title_line);
    form_layout->addRow("Writers", writers_line);
    form_layout->addRow("Illustrators", illustrators_line);
    int labels_width =
        form_layout->labelForField(illustrators_line)->sizeHint().width();
    QLabel* title_label =
        static_cast<QLabel*>(form_layout->labelForField(title_line));
    title_label->setFixedWidth(labels_width);
    title_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    // Fix form height such that it does not shrink when a row is hidden
    form_widget = new QWidget;
    form_widget->setLayout(form_layout);
    form_widget->setFixedHeight(form_widget->sizeHint().height());
    // form_widget->setFixedSize(form_widget->sizeHint());

    // form_layout->setSizeConstraint(QLayout::SetFixedSize);
    // form_layout->addRow(illustrators_line);

    // illustrators_widget = new LabelLineEdit("Illustrators");
    // QSizePolicy retain = illustrators_widget->sizePolicy();
    // retain.setRetainSizeWhenHidden(true);
    // illustrators_widget->setSizePolicy(retain);

    buttons_layout = new QHBoxLayout;
    buttons_layout->addWidget(search_button);
    buttons_layout->addWidget(clear_button);
    // buttons_layout->setSpacing(100);

    main_layout = new QVBoxLayout;
    // main_layout->setSpacing(10);
    main_layout->addWidget(combo_box);
    // main_layout->addLayout(form_layout);
    main_layout->addWidget(form_widget);
    main_layout->addLayout(buttons_layout);
    main_layout->addWidget(results_label);
    main_layout->addWidget(table_view);
    // main_layout->addStretch();
    // main_layout->setStretchFactor(combo_box, 0);
    // main_layout->setStretchFactor(form_layout, 0);
    // main_layout->setStretchFactor(buttons_layout, 1);
    // main_layout->setStretchFactor(results_label, 1);
    setLayout(main_layout);
    // setFixedHeight(sizeHint().height());

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
    search_button->disconnect();
    title_line->disconnect();
    writers_line->disconnect();
    illustrators_line->disconnect();

    switch (book_type) {
        case 0: {  // Non-comic book and writers
            // form_layout->takeRow(2);
            // main_layout->takeAt(3);
            form_layout->setRowVisible(2, false);
            // form_layout->setRowVisible(3, false);
            // illustrators_widget->hide();
            auto search = [&]() {
                emit search_standard_books(
                    title_line->text(),
                    writers_line->text());
                set_results_label();
            };
            connect(search_button, &QPushButton::clicked, search);
            connect(title_line, &QLineEdit::returnPressed, search);
            connect(writers_line, &QLineEdit::returnPressed, search);

            // data_model->setTable("Books");
            // data_model->select();
            break;
        }
        case 1: {  // Comic books, writers and illustrators
            // form_layout->addRow(illustrators_line);
            form_layout->setRowVisible(2, true);
            // form_layout->setRowVisible(3, true);
            // illustrators_widget->show();
            auto search = [&]() {
                emit search_comic_books(
                    title_line->text(),
                    writers_line->text(),
                    illustrators_line->text());
                set_results_label();
            };

            connect(search_button, &QPushButton::clicked, search);
            connect(title_line, &QLineEdit::returnPressed, search);
            connect(writers_line, &QLineEdit::returnPressed, search);
            connect(illustrators_line, &QLineEdit::returnPressed, search);
            break;
        }
    }
}

void SearchWidget::clear() {
    title_line->clear();
    writers_line->clear();
    illustrators_line->clear();
    results_label->clear();
    data_model->clear();
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
