#include "add_book_widget.h"

#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

#include "ui_add_book_widget.h"

AddBookWidget::AddBookWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::AddBookWidget) {
    ui->setupUi(this);

    title_line = new QLineEdit;
    writers_line = new QLineEdit;
    writers_line->setPlaceholderText("Writer1, Writer2, ...");
    illustrators_line = new QLineEdit;
    illustrators_line->setPlaceholderText("Illustrator1, Illustrator2, ...");
    check_box = new QCheckBox("Writers / Illustrators");

    form_layout = new QFormLayout;
    form_layout->setLabelAlignment(Qt::AlignHCenter);
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

    setLayout(form_layout);
    setFixedHeight(sizeHint().height());

    connect(
        check_box,
        &QCheckBox::stateChanged,
        this,
        &AddBookWidget::writer_illustrator);
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
        illustrators_line->setReadOnly(true);
        illustrators_line->setStyleSheet(
            "background-color: silver; color: gray");
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
