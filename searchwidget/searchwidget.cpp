#include "searchwidget.h"

#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qtableview.h>

#include <QComboBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include "../datamodel/datamodel.h"
#include "ui_searchwidget.h"

SearchWidget::SearchWidget(DataModel* data_model, QWidget* parent) :
    QWidget(parent),
    ui(new Ui::SearchWidget) {
    ui->setupUi(this);

    combo_box = new QComboBox;
    combo_box->addItem("Non-comic books / authors");
    combo_box->addItem("Comic books / authors");

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

    table_view = new QTableView;
    table_view->setModel(data_model);

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
    main_layout->addStretch();
    main_layout->addWidget(table_view);
    setLayout(main_layout);

    non_comic_book_search();

    connect(
        combo_box,
        static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        this,
        &SearchWidget::select_search);

    connect(clear_button, &QPushButton::clicked, this, &SearchWidget::clear);
}

SearchWidget::~SearchWidget() {
    delete ui;
}

QPushButton* SearchWidget::get_search_button() const {
    return search_button;
}

void SearchWidget::non_comic_book_search() const {
    // TODO: factorize
    // QPalette read_only_palette;
    // read_only_palette.setColor(QPalette::Base, Qt::lightGray);
    // read_only_palette.setColor(QPalette::Text, Qt::darkGray);

    // writers_line->setReadOnly(false);
    // writers_line->setPalette(QApplication::style()->standardPalette());
    // cb_writers_line->setReadOnly(true);
    // cb_writers_line->setPalette(read_only_palette);
    // cb_illustrators_line->setReadOnly(true);
    // cb_illustrators_line->setPalette(read_only_palette);
    form_layout->setRowVisible(2, false);
    // writers_line->show();
    // cb_writers_line->hide();
    // cb_illustrators_line->hide();
}

void SearchWidget::comic_book_search() const {
    // TODO: factorize
    // QPalette read_only_palette;
    // read_only_palette.setColor(QPalette::Base, Qt::lightGray);
    // read_only_palette.setColor(QPalette::Text, Qt::darkGray);

    // writers_line->setReadOnly(true);
    // writers_line->setPalette(read_only_palette);
    // cb_writers_line->setReadOnly(false);
    // cb_writers_line->setPalette(QApplication::style()->standardPalette());
    // cb_illustrators_line->setReadOnly(false);
    // cb_illustrators_line->setPalette(QApplication::style()->standardPalette());
    form_layout->setRowVisible(2, true);
    // writers_line->hide();
    // cb_writers_line->show();
    // cb_illustrators_line->show();
}

void SearchWidget::select_search(int index) {
    index == 0 ? non_comic_book_search() : comic_book_search();
}

void SearchWidget::clear() {
    title_line->clear();
    writers_line->clear();
    illustrators_line->clear();
}
