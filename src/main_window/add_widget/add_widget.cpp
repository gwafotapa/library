#include "add_widget.h"

#include <qformlayout.h>
#include <qpushbutton.h>

#include <QBoxLayout>
#include <QComboBox>
#include <QHeaderView>
#include <QPushButton>
#include <QStackedWidget>

// #include <qformlayout.h>
// #include <qlineedit.h>
// #include <qnamespace.h>

#include "comic_book_writer.h"
#include "data_model.h"
#include "ui_add_widget.h"

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
    clear_button = new QPushButton("Clear");

    message = new QLabel("coucou");
    message->setStyleSheet("QLabel { color : blue; }");

    data_model = new DataModel("add_widget", this);
    data_model->setTable(
        "Standard Books");  // TODO: replace all table strings with constants or a call
    data_model->select();
    table_view = new QTableView;
    table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table_view->setModel(data_model);

    buttons_layout = new QHBoxLayout;
    buttons_layout->addWidget(add_button);
    buttons_layout->addWidget(clear_button);

    main_layout = new QVBoxLayout;
    main_layout->addWidget(combo_box);
    main_layout->addWidget(stacked_widget);
    main_layout->addLayout(buttons_layout);
    main_layout->addWidget(message);
    main_layout->addWidget(table_view);
    main_layout->addStretch();

    // TODO: put message here for both add_book_widget and add_author_widget

    // main_layout->addStretch();
    // main_layout->addLayout(buttons_layout);
    setLayout(main_layout);

    // connect(combo_box, &QComboBox::currentIndexChanged, [&](int index) {
    //     stacked_widget->setFixedHeight(
    //         stacked_widget->currentWidget()->sizeHint().height());
    // });

    book_page();

    // connect(combo_box, &QComboBox::currentIndexChanged, [&](int index) {
    //     stacked_widget->setCurrentIndex(index <= 1 ? 0 : 1);
    // });

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

    // connect(combo_box, &QComboBox::currentIndexChanged, [&](int index) {
    //     switch (index) {
    //         case 0:
    //             table_view->setVisible(true);
    //             data_model->setTable("Standard Books");
    //             data_model->select();
    //             break;
    //         case 1:
    //             table_view->setVisible(true);
    //             data_model->setTable("Comic Books");
    //             data_model->select();
    //             break;
    //         case 2:
    //             table_view->setVisible(false);
    //             break;
    //     }
    // });

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
    });
}

AddWidget::~AddWidget() {
    delete ui;
}

// QComboBox* AddWidget::get_combo_box() const {
//     return combo_box;
// }

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
    connect(
        add_button,
        &QPushButton::clicked,
        [&]() {  // TODO: make a function
            QString title =
                book_widget()->get_title_line()->text().simplified();
            if (title.isEmpty()) {
                message->setText("Error: blank title");
                message->setStyleSheet("QLabel { color : red; }");
                return;
            }
            QList<Writer> writers;
            for (QString& writer :
                 book_widget()->get_writers_line()->text().split(u',')) {
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
    message->clear();
    data_model->clear();
    table_view->setVisible(true);
    // data_model->setTable("Standard Books");
    // data_model->select();
}

void AddWidget::comic_book_page() {
    stacked_widget->setCurrentIndex(0);
    static_cast<QFormLayout*>(book_widget()->layout())->setRowVisible(2, true);
    static_cast<QFormLayout*>(book_widget()->layout())->setRowVisible(3, true);
    add_button->disconnect();
    connect(
        add_button,
        &QPushButton::clicked,
        [&]() {  // TODO: make a function
            QString title =
                book_widget()->get_title_line()->text().simplified();
            if (title.isEmpty()) {
                message->setText("Error: blank title");
                message->setStyleSheet("QLabel { color : red; }");
                return;
            }
            QList<ComicBookWriter> writers;
            for (QString& writer :
                 book_widget()->get_writers_line()->text().split(u',')) {
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
                 book_widget()->get_illustrators_line()->text().split(u',')) {
                illustrator = illustrator.simplified();
                if (illustrator.isEmpty()) {
                    message->setText("Error: blank illustrator");
                    message->setStyleSheet("QLabel { color : red; }");
                    return;
                }
                illustrators.push_back(Illustrator(illustrator));
            }
            message->clear();
            emit add_comic_book(ComicBook(title, writers, illustrators));
            // for (const ComicBookWriter& writer : writers) {
            //     emit add_comic_book_writer(writer);
            // }
            emit add_comic_book_writers(writers);
            // for (const Illustrator& illustrator : illustrators) {
            //     emit add_illustrator(illustrator);
            // }
            emit add_illustrators(illustrators);
        });
    message->clear();
    data_model->clear();
    table_view->setVisible(true);
    // data_model->setTable("Comic Books");
    // data_model->select();
}

void AddWidget::author_page() {
    stacked_widget->setCurrentIndex(1);
    add_button->disconnect();
    connect(add_button, &QPushButton::clicked, [&]() {
        QString name = author_widget()->get_name_line()->text().simplified();
        if (name.isEmpty()) {
            message->setText("Error: blank author");
            message->setStyleSheet("QLabel { color : red; }");
            return;
        }
        if (!author_widget()->get_writer()->isChecked()
            && !author_widget()->get_comic_book_writer()->isChecked()
            && !author_widget()->get_illustrator()->isChecked()) {
            message->setText("Error: all boxes unchecked");
            message->setStyleSheet("QLabel { color : red; }");
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
    });
    message->clear();
    table_view->setVisible(false);
}

void AddWidget::book_added(const Book& book) const {
    message->setText("Added book \"" + book.get_title() + "\"");
    message->setStyleSheet("QLabel { color : blue; }");
    // data_model->setFilter("");
    data_model->select();
}

void AddWidget::book_exists(const Book& book) const {
    message->setText(
        "Book \"" + book.get_title() + "\" is already in the database");
    message->setStyleSheet("QLabel { color : red; }");
}

void AddWidget::author_added(const Author* author) const {
    // qDebug() << "Author " + author.get_name()
    //         + " added";  // TODO: remove or add everywhere
    QString added_author = "Added ";
    if (dynamic_cast<const Writer*>(author)) {
        added_author += "writer";
    } else if (dynamic_cast<const ComicBookWriter*>(author)) {
        added_author += "comic book writer";
    } else {
        added_author += "illustrator";
    }
    added_author += " \"" + author->get_name() + "\"";
    message->setText(
        message->text().isEmpty() ? added_author
                                  : message->text() + "\n" + added_author);
    message->setStyleSheet("QLabel { color : blue; }");
    // data_model->setFilter("");
    data_model->select();
}

void AddWidget::author_exists(const Author& author) const {
    if (message->text().isEmpty()) {
        message->setText(
            "Author \"" + author.get_name() + "\" is already in the database");
        message->setStyleSheet("QLabel { color : red; }");
    }
}
