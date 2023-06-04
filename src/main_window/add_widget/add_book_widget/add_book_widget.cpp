#include "add_book_widget.h"

#include <qnamespace.h>

#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QStyle>
#include <QTableView>

#include "comic_book.h"
#include "standard_book.h"
#include "ui_add_book_widget.h"

AddBookWidget::AddBookWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::AddBookWidget) {
    ui->setupUi(this);

    title_line = new QLineEdit;
    // title_line->setClearButtonEnabled(true);
    writers_line = new QLineEdit;
    writers_line->setPlaceholderText("Writer1, Writer2, ...");
    // writers_line->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    // writers_line->setClearButtonEnabled(true);
    illustrators_line = new QLineEdit;
    illustrators_line->setPlaceholderText("Illustrator1, Illustrator2, ...");
    // illustrators_line->setClearButtonEnabled(true);
    check_box = new QCheckBox("Writers / Illustrators");
    // add_button = new QPushButton("Add");
    // clear_button = new QPushButton("Clear");

    form_layout = new QFormLayout;
    form_layout->setLabelAlignment(Qt::AlignHCenter);
    // form_layout->setSizeConstraint(QLayout::SetFixedSize);
    // qDebug() << form_layout->verticalSpacing();
    // form_layout->setSpacing(0);
    form_layout->addRow("Title", title_line);
    form_layout->addRow("Writers", writers_line);
    form_layout->addRow("Illustrators", illustrators_line);
    form_layout->addRow("", check_box);
    int labels_width =
        form_layout->labelForField(illustrators_line)->sizeHint().width();
    QLabel* title_label =
        static_cast<QLabel*>(form_layout->labelForField(title_line));
    title_label->setFixedWidth(labels_width);
    title_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    // buttons_layout = new QHBoxLayout;
    // buttons_layout->addWidget(add_button);
    // buttons_layout->addWidget(clear_button);

    // main_layout = new QVBoxLayout;
    // main_layout->addLayout(form_layout);
    // main_layout->addLayout(buttons_layout);
    // main_layout->addStretch();
    setLayout(form_layout);
    setFixedHeight(sizeHint().height());
    // layout()->setSizeConstraint(QLayout::SetFixedSize);

    // select_book_type(0);

    connect(
        check_box,
        &QCheckBox::stateChanged,
        this,
        &AddBookWidget::writer_illustrator);

    // connect(clear_button, &QPushButton::clicked, this, &AddBookWidget::clear);
}

AddBookWidget::~AddBookWidget() {
    delete ui;
}

const QLineEdit* AddBookWidget::get_title_line() const {
    return title_line;
}

const QLineEdit* AddBookWidget::get_writers_line() const {
    return writers_line;
}

const QLineEdit* AddBookWidget::get_illustrators_line() const {
    return illustrators_line;
}

void AddBookWidget::writer_illustrator(int state) {
    if (state == Qt::Checked) {
        // QPalette read_only_palette;
        // read_only_palette.setColor(QPalette::Base, Qt::lightGray);
        // read_only_palette.setColor(QPalette::Text, Qt::darkGray);

        illustrators_line->setReadOnly(true);
        illustrators_line->setStyleSheet(
            "background-color: silver; color: gray");
        // illustrators_line->setPalette(read_only_palette);
        copy_writer_to_illustrator();

        connect(
            writers_line,
            &QLineEdit::textEdited,
            this,
            &AddBookWidget::copy_writer_to_illustrator);
    } else {
        illustrators_line->setReadOnly(false);
        illustrators_line->setStyleSheet(
            "background-color: white; color: black");
        // illustrators_line->setPalette(QApplication::style()->standardPalette());

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
    // message->clear();
}

// void AddBookWidget::add_book_and_writers() {
//     QString writers = writers_line->text();
//     QStringList writer_list = writers.split(u',');
//     data_model->add_writers(writer_list);

//     QString title = title_line->text();
//     data_model->add_standard_book(title, writers);
// }

// void AddBookWidget::add_comic_book_and_authors() {
//     QString writers = writers_line->text();
//     QStringList writer_list = writers.split(u',');
//     data_model->add_comic_book_writers(writer_list);

//     QString illustrators = illustrators_line->text();
//     QStringList illustrator_list = illustrators.split(u',');
//     data_model->add_illustrators(illustrator_list);

//     QString title = title_line->text();
//     data_model->add_comic_book(title, writers, illustrators);
// }
