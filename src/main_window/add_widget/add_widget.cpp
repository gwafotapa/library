#include "add_widget.h"

#include <QBoxLayout>
#include <QComboBox>
#include <QFormLayout>
#include <QHeaderView>
#include <QPushButton>
#include <QStackedWidget>
#include <QTableView>

#include "author.h"
#include "comic_book.h"
#include "comic_book_writer.h"
#include "data_model.h"
#include "illustrator.h"
#include "standard_book.h"
#include "ui_add_widget.h"
#include "writer.h"

AddWidget::AddWidget(QWidget* parent) : QWidget(parent), ui(new Ui::AddWidget) {
    ui->setupUi(this);

    combo_box = new QComboBox;
    combo_box->addItem("Book");
    combo_box->addItem("Comic book");
    combo_box->addItem("Author");

    add_book_widget = new AddBookWidget;
    add_author_widget = new AddAuthorWidget;

    stacked_widget = new QStackedWidget;
    stacked_widget->addWidget(add_book_widget);
    stacked_widget->addWidget(add_author_widget);

    add_button = new QPushButton("Add");
    add_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    clear_button = new QPushButton("Clear");
    clear_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    message = new QLabel;
    message->setStyleSheet(message_std_style);

    data_model = new DataModel("add_widget", this);

#ifndef NDEBUG
    table_view = new QTableView;
    table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table_view->horizontalHeader()->setStyleSheet("color: blue");
    table_view->setStyleSheet("selection-background-color: blue");
    table_view->setSortingEnabled(true);
    table_view->setModel(data_model);
#endif

    setup_layout();
    setup_connections();

    book_page();
}

void AddWidget::setup_layout() {
    buttons_layout = new QHBoxLayout;
    buttons_layout->addWidget(add_button);
    buttons_layout->addWidget(clear_button);

    main_layout = new QVBoxLayout;
    main_layout->addWidget(combo_box);
    main_layout->addWidget(stacked_widget);
    main_layout->addLayout(buttons_layout, 1);
    main_layout->addWidget(message);
#ifndef NDEBUG
    main_layout->addWidget(table_view, 1);
#else
    main_layout->addStretch(1);
#endif

    setLayout(main_layout);
}

void AddWidget::setup_connections() {
    connect(combo_box, &QComboBox::currentIndexChanged, [&](int index) {
        switch (index) {
            case 0:
                book_page();
                break;
            case 1:
                comic_book_page();
                break;
            case 2:
                author_page();
                break;
        }
    });

    connect(
        this,
        &AddWidget::add_standard_book,
        data_model,
        &DataModel::add_standard_book);
    connect(
        this,
        &AddWidget::add_comic_book,
        data_model,
        &DataModel::add_comic_book);
    connect(this, &AddWidget::add_writer, data_model, &DataModel::add_writer);
    connect(
        this,
        &AddWidget::add_comic_book_writer,
        data_model,
        &DataModel::add_comic_book_writer);
    connect(
        this,
        &AddWidget::add_illustrator,
        data_model,
        &DataModel::add_illustrator);
    connect(this, &AddWidget::add_writers, data_model, &DataModel::add_writers);
    connect(
        this,
        &AddWidget::add_comic_book_writers,
        data_model,
        &DataModel::add_comic_book_writers);
    connect(
        this,
        &AddWidget::add_illustrators,
        data_model,
        &DataModel::add_illustrators);

    connect(data_model, &DataModel::book_added, this, &AddWidget::book_added);
    connect(data_model, &DataModel::book_exists, this, &AddWidget::book_exists);
    connect(
        data_model,
        &DataModel::author_added,
        this,
        &AddWidget::author_added);
    connect(
        data_model,
        &DataModel::author_exists,
        this,
        &AddWidget::author_exists);

    connect(clear_button, &QPushButton::clicked, [&]() {
        add_book_widget->clear();
        add_author_widget->clear();
        message->clear();
#ifndef NDEBUG
        data_model->clear();
#endif
    });
}

AddWidget::~AddWidget() {
    delete ui;
}

AddBookWidget* AddWidget::book_widget() const {
    return add_book_widget;
}

AddAuthorWidget* AddWidget::author_widget() const {
    return add_author_widget;
}

void AddWidget::book_page() {
    stacked_widget->setCurrentIndex(0);
    static_cast<QFormLayout*>(book_widget()->layout())->setRowVisible(2, false);
    static_cast<QFormLayout*>(book_widget()->layout())->setRowVisible(3, false);
    add_button->disconnect();
    add_book_widget->get_title_line()->disconnect();
    add_book_widget->get_writers_line()->disconnect();
    add_book_widget->get_illustrators_line()->disconnect();

    auto add = [&]() {  // TODO: make a function and clean disconnects above
        QString title = book_widget()->get_title_line()->text().simplified();
        if (title.isEmpty()) {
            message->setText("Error: blank title");
            message->setStyleSheet(message_err_style);
            return;
        }
        QList<Writer> writers;
        for (QString& writer :
             book_widget()->get_writers_line()->text().split(u',')) {
            writer = writer.simplified();
            if (writer.isEmpty()) {
                message->setText("Error: blank writer");
                message->setStyleSheet(message_err_style);
                return;
            }
            writers.push_back(Writer(writer));
        }
        message->clear();
        emit add_standard_book(StandardBook(title, writers));
        emit add_writers(writers);
    };
    connect(add_button, &QPushButton::clicked, add);
    connect(add_book_widget->get_title_line(), &QLineEdit::returnPressed, add);
    connect(
        add_book_widget->get_writers_line(),
        &QLineEdit::returnPressed,
        add);
    connect(
        add_book_widget->get_illustrators_line(),
        &QLineEdit::returnPressed,
        add);
    message->clear();
#ifndef NDEBUG
    data_model->set_table_standard_books();
    data_model->select();
#endif
}

void AddWidget::comic_book_page() {
    stacked_widget->setCurrentIndex(0);
    static_cast<QFormLayout*>(book_widget()->layout())->setRowVisible(2, true);
    static_cast<QFormLayout*>(book_widget()->layout())->setRowVisible(3, true);
    add_button->disconnect();
    add_book_widget->get_title_line()->disconnect();
    add_book_widget->get_writers_line()->disconnect();
    add_book_widget->get_illustrators_line()->disconnect();

    auto add = [&]() {  // TODO: make a function and clean disconnects above
        QString title = book_widget()->get_title_line()->text().simplified();
        if (title.isEmpty()) {
            message->setText("Error: blank title");
            message->setStyleSheet(message_err_style);
            return;
        }
        QList<ComicBookWriter> writers;
        for (QString& writer :
             book_widget()->get_writers_line()->text().split(u',')) {
            writer = writer.simplified();
            if (writer.isEmpty()) {
                message->setText("Error: blank writer");
                message->setStyleSheet(message_err_style);
                return;
            }
            writers.push_back(ComicBookWriter(writer));
        }
        QList<Illustrator> illustrators;
        for (QString& illustrator :
             book_widget()->get_illustrators_line()->text().split(u',')) {
            illustrator = illustrator.simplified();
            if (illustrator.isEmpty()) {
                message->setText("Error: blank illustrator");
                message->setStyleSheet(message_err_style);
                return;
            }
            illustrators.push_back(Illustrator(illustrator));
        }
        message->clear();
        emit add_comic_book(ComicBook(title, writers, illustrators));
        emit add_comic_book_writers(writers);
        emit add_illustrators(illustrators);
    };
    connect(add_button, &QPushButton::clicked, add);
    connect(add_book_widget->get_title_line(), &QLineEdit::returnPressed, add);
    connect(
        add_book_widget->get_writers_line(),
        &QLineEdit::returnPressed,
        add);
    connect(
        add_book_widget->get_illustrators_line(),
        &QLineEdit::returnPressed,
        add);

    message->clear();
#ifndef NDEBUG
    data_model->set_table_comic_books();
    data_model->select();
#endif
}

void AddWidget::author_page() {
    stacked_widget->setCurrentIndex(1);
    add_button->disconnect();
    add_author_widget->get_name_line()->disconnect();

    auto add = [&]() {  // TODO: make a function and clean disconnects above
        QString name = author_widget()->get_name_line()->text().simplified();
        if (name.isEmpty()) {
            message->setText("Error: blank author");
            message->setStyleSheet(message_err_style);
            return;
        }
        if (!author_widget()->get_writer()->isChecked()
            && !author_widget()->get_comic_book_writer()->isChecked()
            && !author_widget()->get_illustrator()->isChecked()) {
            message->setText("Error: all boxes unchecked");
            message->setStyleSheet(message_err_style);
            return;
        }
        message->clear();
        if (author_widget()->get_writer()->isChecked()) {
            emit add_writer(Writer(name));
        }
        if (author_widget()->get_comic_book_writer()->isChecked()) {
            emit add_comic_book_writer(ComicBookWriter(name));
        }
        if (author_widget()->get_illustrator()->isChecked()) {
            emit add_illustrator(Illustrator(name));
        }
    };
    connect(add_button, &QPushButton::clicked, add);
    connect(add_author_widget->get_name_line(), &QLineEdit::returnPressed, add);
    message->clear();
#ifndef NDEBUG
    if (data_model->tableName().isEmpty()) {
        data_model->set_table_standard_books();
    }
    data_model->select();
#endif
}

void AddWidget::book_added(const Book& book) const {
    message->setText("Added book \"" + book.get_title() + "\"");
    message->setStyleSheet(message_std_style);
#ifndef NDEBUG
    data_model->select();
#endif
}

void AddWidget::book_exists(const Book& book) const {
    message->setText(
        "Book \"" + book.get_title() + "\" is already in the database");
    message->setStyleSheet(message_err_style);
}

void AddWidget::author_added(const Author& author) const {
    QString added_author = "Added ";
    if (author.makes_standard_books()) {
        added_author += "writer";
    } else if (author.writes()) {
        added_author += "comic book writer";
    } else {
        added_author += "illustrator";
    }
    added_author += " \"" + author.get_name() + "\"";
    message->setText(
        message->text().isEmpty() ? added_author
                                  : message->text() + "\n" + added_author);
    message->setStyleSheet(message_std_style);
#ifndef NDEBUG
    if (author.makes_standard_books()) {
        data_model->set_table_standard_books();
    } else {
        data_model->set_table_comic_books();
    }
    data_model->select();
#endif
}

void AddWidget::author_exists(const Author& author) const {
    if (message->text().isEmpty()) {
        message->setText(
            "Author \"" + author.get_name() + "\" is already in the database");
        message->setStyleSheet(message_err_style);
    }
}
