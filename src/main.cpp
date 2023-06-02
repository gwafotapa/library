#include <qsqldatabase.h>

#include <QApplication>

#include "main_window.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    // QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    // db.setDatabaseName("../bookstore.db");
    // // db.setDatabaseName(":memory:");
    // if (!db.open()) {
    //     std::cout << "Cannot open database" << std::endl;
    // }
    MainWindow main_window;
    // MainWindow main_window(db_);
    main_window.show();
    return QApplication::exec();
}
