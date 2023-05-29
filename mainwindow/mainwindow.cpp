#include "mainwindow.h"

#include <qboxlayout.h>
#include <qsqlrecord.h>

#include <QDebug>
#include <QKeyEvent>
#include <QPushButton>
#include <QSqlRecord>
#include <QVBoxLayout>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // form_widget = new FormWidget;
    // buttons_widget = new ButtonsWidget;
    // // search_widget = new SearchWidget;
    // table_widget = new TableWidget;

    // v_box_layout = new QVBoxLayout(central_widget);
    // v_box_layout->addWidget(form_widget);
    // v_box_layout->addWidget(buttons_widget);
    // // v_box_layout->addWidget(search_widget);
    // v_box_layout->addWidget(table_widget);

    // data_model = new DataModel(this);
    // // data_model->select();
    // table_widget->get_table_view()->setModel(data_model);

    search_widget = new SearchWidget;
    add_widget = new AddWidget;

    tab_widget = new QTabWidget;
    // tab_widget->setStyleSheet("QTabBar::tab { width: 80px; }");
    tab_widget->addTab(search_widget, "Search");
    tab_widget->addTab(add_widget, "Add");
    // tab_widget->addTab(buttons_widget, "Add");

    // main_layout = new QVBoxLayout;
    // main_layout->addWidget(tab_widget);
    // setLayout(main_layout);

    // connect(
    //     buttons_widget->get_add_button(),
    //     &QPushButton::clicked,
    //     this,
    //     &MainWindow::add_data);

    // connect(
    //     buttons_widget->get_search_button(),
    //     &QPushButton::clicked,
    //     this,
    //     &MainWindow::search_data);

    // connect(
    //     search_widget->get_search_button(),
    //     &QPushButton::clicked,
    //     this,
    //     &MainWindow::filter_search_data);
    setCentralWidget(tab_widget);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
        case Qt::Key_Escape:
            close();
            break;
        default:
            QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::add_author(QString& author) const {
    // author = author.simplified();
    // if (author.isEmpty()) {
    //     return;
    // }

    // data_model->setFilter("\"Authors\" = '" + author + "'");
    // data_model->select();
    // if (data_model->rowCount() == 0) {
    //     QSqlRecord record = data_model->record();
    //     record.setValue("Authors", author);
    //     data_model->insertRecord(-1, record);
    //     // data_model->submit();
    // }
}

void MainWindow::add_authors(QStringList& authors) const {
    for (QString& author : authors) {
        add_author(author);
    }
}

void MainWindow::add_book(QString& title, QString& authors) const {
    // title = title.simplified();
    // authors = authors.simplified();
    // if (title.isEmpty() || authors.isEmpty()) {
    //     return;
    // }

    // data_model->setFilter(
    //     "\"Title\" = '" + title + "' AND \"Authors\" = '" + authors + "'");
    // data_model->select();
    // if (data_model->rowCount() == 0) {
    //     QSqlRecord record = data_model->record();
    //     record.setValue("Title", title);
    //     record.setValue("Authors", authors);
    //     data_model->insertRecord(-1, record);
    //     // data_model->submit();
    // }
}

void MainWindow::add_data2() {
    // QString title = form_widget->title();
    // QString authors = form_widget->authors();

    // if (authors.isEmpty()) {
    //     qDebug() << "Field 'Authors' is empty";
    //     return;
    // }

    // QSqlRecord record = data_model->record();

    // // Add naked authors if not present in the database
    // QStringList authors_list = form_widget->authors().split(u',');
    // add_authors(authors_list);

    // // Add book
    // if (!form_widget->title().isEmpty()) {
    //     record.setValue("Title", form_widget->title());
    //     record.setValue("Authors", form_widget->authors());
    //     data_model->insertRecord(-1, record);
    // }

    // // data_model->submitAll();
}

void MainWindow::add_data() {
    // if (form_widget->authors().isEmpty()) {
    //     qDebug() << "Field 'Authors' is empty";
    //     return;
    // }

    // QSqlRecord record = data_model->record();

    // // Add naked authors if not present in the database
    // QStringList authors = form_widget->authors().split(u',');
    // for (QString& author : authors) {
    //     author = author.simplified();
    //     if (author.isEmpty()) {
    //         continue;
    //     }
    //     data_model->setFilter("\"Authors\" = '" + author + "'");
    //     data_model->select();
    //     if (data_model->rowCount() == 0) {
    //         record.setValue("Authors", author);
    //         data_model->insertRecord(-1, record);
    //     }
    // }

    // // Add book
    // if (!form_widget->title().isEmpty()) {
    //     record.setValue("Title", form_widget->title());
    //     record.setValue("Authors", form_widget->authors());
    //     data_model->insertRecord(-1, record);
    // }

    // data_model->submitAll();
}

// void MainWindow::search_data() {
//     QString title = form_widget->title();
//     QString authors = form_widget->authors();

//     if (title.isEmpty()) {
//         data_model->setTable("Authors");
//         data_model->setFilter("\"name\" LIKE '%" + authors + "%'");
//         data_model->select();

//         qDebug() << data_model->query().lastQuery();
//         for (int i = 0; i < data_model->rowCount(); ++i) {
//             qDebug() << data_model->record(i);
//         }
//     } else {
//         data_model->setTable("Books");
//         data_model->setFilter(
//             "\"title\" LIKE '%" + title + "%' AND \"authors\" LIKE '%" + authors
//             + "%'");
//         data_model->select();

//         qDebug() << data_model->query().lastQuery();
//         for (int i = 0; i < data_model->rowCount(); ++i) {
//             qDebug() << data_model->record(i);
//         }
//     }

//     // data_model->setTable(title.isEmpty() ? "Authors" : "Books");
// }

void MainWindow::search_data() {
    // // data_model->setTable("Books");
    // bool first_condition = true;
    // QString title = form_widget->title();
    // QString authors = form_widget->authors();
    // QString filter;

    // if (!title.isEmpty()) {
    //     first_condition = false;
    //     filter = "\"Title\" LIKE '%" + title + "%'";
    // }
    // if (!authors.isEmpty()) {
    //     if (!first_condition) {
    //         filter += " AND ";
    //     }
    //     filter += "\"Authors\" LIKE '%" + authors + "%'";
    // }
    // data_model->setFilter(filter);
    // data_model->select();

    // qDebug() << data_model->query().lastQuery();
    // for (int i = 0; i < data_model->rowCount(); ++i) {
    //     qDebug() << data_model->record(i);
    // }

    // // data_model->setTable(title.isEmpty() ? "Authors" : "Books");
}
