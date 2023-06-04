#include "main_window.h"

#include <QKeyEvent>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "add_widget.h"
#include "search_widget.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    tab_widget = new QTabWidget;
    search_widget = new SearchWidget;
    add_widget = new AddWidget;
    tab_widget->addTab(search_widget, "Search");
    tab_widget->addTab(add_widget, "Add");

    main_layout = new QVBoxLayout;
    main_layout->addWidget(tab_widget);

    central_widget = new QWidget;
    central_widget->setLayout(main_layout);
    setCentralWidget(central_widget);
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
