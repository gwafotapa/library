// #include <qsqldatabase.h>

#include <QApplication>

#include "main_window.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    app.setStyleSheet(
        "* { color: black }"
        "QTabWidget { background-color: lightgray }"
        "QTabBar { color: blue }"
        "QComboBox { selection-background-color: blue; selection-color: white; color: blue }"
        "QLineEdit { placeholder-text-color: gray; selection-background-color: blue }");
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
