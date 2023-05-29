#include "searchwidget.h"

#include <QComboBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include "ui_searchwidget.h"

SearchWidget::SearchWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::SearchWidget) {
    ui->setupUi(this);

    combo_box = new QComboBox;
    combo_box->addItem("Regular book");
    combo_box->addItem("Comic book");
    title_line = new QLineEdit;
    writers_line = new QLineEdit;
    cb_writers_line = new QLineEdit;
    cb_illustrators_line = new QLineEdit;
    search_button = new QPushButton("Search");

    form_layout = new QFormLayout(this);
    form_layout->addRow("", combo_box);
    form_layout->addRow("Title", title_line);
    form_layout->addRow("Writers", writers_line);
    form_layout->addRow("Comic book writers", cb_writers_line);
    form_layout->addRow("Comic book illustrators", cb_illustrators_line);
    form_layout->addRow("", search_button);

    regular_book_search();

    connect(
        combo_box,
        static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        this,
        &SearchWidget::select_search);
}

SearchWidget::~SearchWidget() {
    delete ui;
}

QPushButton* SearchWidget::get_search_button() const {
    return search_button;
}

void SearchWidget::regular_book_search() const {
    // TODO: factorize
    QPalette read_only_palette;
    read_only_palette.setColor(QPalette::Base, Qt::lightGray);
    read_only_palette.setColor(QPalette::Text, Qt::darkGray);

    writers_line->setReadOnly(false);
    writers_line->setPalette(QApplication::style()->standardPalette());
    cb_writers_line->setReadOnly(true);
    cb_writers_line->setPalette(read_only_palette);
    cb_illustrators_line->setReadOnly(true);
    cb_illustrators_line->setPalette(read_only_palette);
}

void SearchWidget::comic_book_search() const {
    // TODO: factorize
    QPalette read_only_palette;
    read_only_palette.setColor(QPalette::Base, Qt::lightGray);
    read_only_palette.setColor(QPalette::Text, Qt::darkGray);

    writers_line->setReadOnly(true);
    writers_line->setPalette(read_only_palette);
    cb_writers_line->setReadOnly(false);
    cb_writers_line->setPalette(QApplication::style()->standardPalette());
    cb_illustrators_line->setReadOnly(false);
    cb_illustrators_line->setPalette(QApplication::style()->standardPalette());
}

void SearchWidget::select_search(int index) {
    index == 0 ? regular_book_search() : comic_book_search();
}
