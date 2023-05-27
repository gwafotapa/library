//
// Created by Administrateur on 26/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"

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

    v_box_layout = new QVBoxLayout(central_widget);
    v_box_layout->addWidget(form_widget);
    v_box_layout->addWidget(buttons_widget);
    // qVBoxLayout->addWidget(listWidget);

    data_model = new DataModel(this);
    // data_model->select();

    connect(
        buttons_widget->get_add_button(),
        &QPushButton::clicked,
        this,
        &MainWindow::add_data);
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
