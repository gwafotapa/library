#include "add_comic_book_widget.h"

#include <QCheckBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QStyle>

#include "ui_add_comic_book_widget.h"

AddComicBookWidget::AddComicBookWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::AddComicBookWidget) {
    ui->setupUi(this);

    title_line = new QLineEdit;
    writers_line = new QLineEdit;
    writers_line->setPlaceholderText("Writer1, Writer2, ...");
    illustrators_line = new QLineEdit;
    illustrators_line->setPlaceholderText("Illustrator1, Illustrator2, ...");
    check_box = new QCheckBox(this);

    form_layout = new QFormLayout(this);
    form_layout->addRow("Title", title_line);
    form_layout->addRow("Writers", writers_line);
    form_layout->addRow("Illustrators", illustrators_line);
    form_layout->addRow("Writer / Illustrator", check_box);

    connect(
        check_box,
        &QCheckBox::stateChanged,
        this,
        &AddComicBookWidget::writer_illustrator);
}

AddComicBookWidget::~AddComicBookWidget() {
    delete ui;
}

void AddComicBookWidget::writer_illustrator(int state) {
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
            &AddComicBookWidget::copy_writer_to_illustrator);
    } else {
        illustrators_line->setReadOnly(false);
        illustrators_line->setPalette(QApplication::style()->standardPalette());

        disconnect(
            writers_line,
            &QLineEdit::textEdited,
            this,
            &AddComicBookWidget::copy_writer_to_illustrator);
    }
}

void AddComicBookWidget::copy_writer_to_illustrator() {
    illustrators_line->setText(writers_line->text());
}
