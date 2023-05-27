//
// Created by Administrateur on 26/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"

#include <qboxlayout.h>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    central_widget = new QWidget;
    v_box_layout = new QVBoxLayout(central_widget);
    form_widget = new FormWidget;

    setCentralWidget(central_widget);

    v_box_layout->addWidget(form_widget);
    // qVBoxLayout->addWidget(buttonsWidget);
    // qVBoxLayout->addWidget(listWidget);
}

MainWindow::~MainWindow() {
    delete ui;
}
