#include <QApplication>

#include "main_window.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    app.setStyleSheet(
        "* { selection-background-color: blue; color: black }"
        "QTabWidget { background-color: lightgray }"
        "QTabBar { color: blue }"
        "QComboBox { selection-color: white; color: blue }"
        "QLineEdit { placeholder-text-color: gray }"
        "QPushButton { max-width: 250; max-height: 50; color: blue }"
        "QPushButton:focus { background-color: lightblue }");

    MainWindow main_window;
    main_window.resize(640, 720);
    main_window.show();

    return QApplication::exec();
}
