// #include <qsqldatabase.h>

#include <QApplication>

#include "main_window.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    app.setStyleSheet(
        "* { selection-background-color: blue; color: black }"
        // "QMainWindow::menu-bar { color: darkgray }"
        // "* { background-color: darkgray }"
        "QTabWidget { background-color: lightgray }"
        "QTabBar { color: blue }"
        // "QTabBar::tab:selected { background-color: lightgray; border-top-left-radius: 5px; border-top-right-radius: 5px; padding: 5px; border-bottom: 2px solid red }"
        // "QTabBar::tab:!selected { background-color: rgb(240, 240, 240); border-top-left-radius: 5px; border-top-right-radius: 5px; padding: 5px; border: 1px solid black }"
        "QComboBox { selection-color: white; color: blue }"
        "QLineEdit { placeholder-text-color: gray }"
        "QPushButton { max-width: 250; max-height: 50; color: blue }"
        "QPushButton:focus { background-color: lightblue }");
    // "QPushButton { max-width: 300; max-height: 50; color: blue }"
    // "QTableView { selection-background-color: blue }");
    // setStyleSheet("QPushButton { color: blue };");
    // setStyleSheet("QLineEdit { placeholder-text-color: gray }");
    // setStyleSheet(styleSheet() + "QPushButton { color: blue }");
    // tab_widget->tabBar()->setStyleSheet("color: blue");
    // search_widget->setStyleSheet("QPushButton { color: blue }");
    // "QMainWindow::central_widget {width: 100; background-color: blue}");
    // centralWidget()->setStyleSheet("background-color: silver");

    // QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    // db.setDatabaseName("../bookstore.db");
    // // db.setDatabaseName(":memory:");
    // if (!db.open()) {
    //     std::cout << "Cannot open database" << std::endl;
    // }
    MainWindow main_window;
    main_window.resize(640, 720);
    // MainWindow main_window(db_);

    main_window.show();
    return QApplication::exec();
}
