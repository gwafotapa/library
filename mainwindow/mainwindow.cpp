#include "mainwindow.h"

#include <QDebug>
#include <QPushButton>
#include <QSqlRecord>
#include <QVBoxLayout>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    central_widget = new QWidget;
    setCentralWidget(central_widget);

    form_widget = new FormWidget;
    buttons_widget = new ButtonsWidget;
    table_widget = new TableWidget;

    v_box_layout = new QVBoxLayout(central_widget);
    v_box_layout->addWidget(form_widget);
    v_box_layout->addWidget(buttons_widget);
    v_box_layout->addWidget(table_widget);

    data_model = new DataModel(this);
    // data_model->select();
    table_widget->get_table_view()->setModel(data_model);

    connect(
        buttons_widget->get_add_button(),
        &QPushButton::clicked,
        this,
        &MainWindow::add_data);

    connect(
        buttons_widget->get_search_button(),
        &QPushButton::clicked,
        this,
        &MainWindow::search_data);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::add_data() {
    QString title = form_widget->title();
    QString authors = form_widget->authors();

    if (authors.isEmpty()) {
        qDebug() << "Field 'Authors' is empty";
        return;
    }

    data_model->setTable("Authors");
    QSqlRecord record = data_model->record();
    record.setValue("name", authors);
    data_model->insertRecord(-1, record);
    data_model->submit();

    if (title.isEmpty()) {
        qDebug() << "Field 'Title' is empty";
        return;
    }

    data_model->setTable("Books");
    record = data_model->record();
    record.setValue("title", title);
    record.setValue("authors", authors);
    data_model->insertRecord(-1, record);
    data_model->submit();
}

void MainWindow::search_data() {
    QString title = form_widget->title();
    QString authors = form_widget->authors();

    if (title.isEmpty()) {
        data_model->setTable("Authors");
        data_model->setFilter("\"name\" LIKE '%" + authors + "%'");
        data_model->select();

        qDebug() << data_model->query().lastQuery();
        for (int i = 0; i < data_model->rowCount(); ++i) {
            qDebug() << data_model->record(i);
        }
    } else {
        data_model->setTable("Books");
        data_model->setFilter(
            "\"title\" LIKE '%" + title + "%' AND \"authors\" LIKE '%" + authors
            + "%'");
        data_model->select();

        qDebug() << data_model->query().lastQuery();
        for (int i = 0; i < data_model->rowCount(); ++i) {
            qDebug() << data_model->record(i);
        }
    }

    // data_model->setTable(title.isEmpty() ? "Authors" : "Books");
}
