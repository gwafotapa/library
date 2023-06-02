#include "add_book_widget.h"

#include <QCheckBox>
#include <QFormLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QStyle>
#include <QTableView>

#include "comic_book.h"
#include "data_model.h"
#include "standard_book.h"
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
    message = new QLabel("coucou");
    message->setStyleSheet("QLabel { color : blue; }");

    form_layout = new QFormLayout;
    form_layout->addRow("Title", title_line);
    form_layout->addRow("Writers", writers_line);
    form_layout->addRow("Illustrators", illustrators_line);
    form_layout->addRow("", check_box);

    buttons_layout = new QHBoxLayout;
    buttons_layout->addWidget(add_button);
    buttons_layout->addWidget(clear_button);

    table_view = new QTableView;
    table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table_view->setModel(data_model);
    this->data_model = data_model;

    main_layout = new QVBoxLayout;
    main_layout->addLayout(form_layout);
    main_layout->addLayout(buttons_layout);
    main_layout->addWidget(message);
    main_layout->addWidget(table_view);
    // main_layout->addStretch();
    setLayout(main_layout);

    select_book_type(0);

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

void AddBookWidget::select_book_type(int book_type) {
    message->clear();
    disconnect(add_button, &QPushButton::clicked, this, nullptr);
    switch (book_type) {
        case 0:
            form_layout->setRowVisible(2, false);
            form_layout->setRowVisible(3, false);
            connect(
                add_button,
                &QPushButton::clicked,
                [&]() {  // TODO: make a function
                    QString title = title_line->text().simplified();
                    if (title.isEmpty()) {
                        message->setText("Error: blank title");
                        message->setStyleSheet("QLabel { color : red; }");
                        return;
                    }
                    QList<Writer> writers;
                    for (QString& writer : writers_line->text().split(u',')) {
                        writer = writer.simplified();
                        if (writer.isEmpty()) {
                            message->setText("Error: blank writer");
                            message->setStyleSheet("QLabel { color : red; }");
                            return;
                        }
                        writers.push_back(Writer(writer));
                    }
                    message->clear();
                    emit add_standard_book(StandardBook(title, writers));
                    // for (const Writer& writer : writers) {
                    //     emit add_writer(writer);
                    // }
                    emit add_writers(writers);
                });
            data_model->setTable("Standard Books");
            data_model->select();
            break;
        case 1:
            form_layout->setRowVisible(2, true);
            form_layout->setRowVisible(3, true);
            connect(
                add_button,
                &QPushButton::clicked,
                [&]() {  // TODO: make a function
                    QString title = title_line->text().simplified();
                    if (title.isEmpty()) {
                        message->setText("Error: blank title");
                        message->setStyleSheet("QLabel { color : red; }");
                        return;
                    }
                    QList<ComicBookWriter> writers;
                    for (QString& writer : writers_line->text().split(u',')) {
                        writer = writer.simplified();
                        if (writer.isEmpty()) {
                            message->setText("Error: blank writer");
                            message->setStyleSheet("QLabel { color : red; }");
                            return;
                        }
                        writers.push_back(ComicBookWriter(writer));
                    }
                    QList<Illustrator> illustrators;
                    for (QString& illustrator :
                         illustrators_line->text().split(u',')) {
                        illustrator = illustrator.simplified();
                        if (illustrator.isEmpty()) {
                            message->setText("Error: blank illustrator");
                            message->setStyleSheet("QLabel { color : red; }");
                            return;
                        }
                        illustrators.push_back(Illustrator(illustrator));
                    }
                    message->clear();
                    emit add_comic_book(
                        ComicBook(title, writers, illustrators));
                    // for (const ComicBookWriter& writer : writers) {
                    //     emit add_comic_book_writer(writer);
                    // }
                    emit add_comic_book_writers(writers);
                    // for (const Illustrator& illustrator : illustrators) {
                    //     emit add_illustrator(illustrator);
                    // }
                    emit add_illustrators(illustrators);
                });
            data_model->setTable("Comic Books");
            data_model->select();
            break;
    }
}

void AddBookWidget::book_added(const Book& book) const {
    message->setText("Added book \"" + book.get_title() + "\"");
}

// TODO: change all palette to stylesheet
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
    message->clear();
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
