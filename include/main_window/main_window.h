#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QVBoxLayout>

#include "add_widget.h"
#include "search_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

  private:
    Ui::MainWindow* ui;

    QVBoxLayout* main_layout;

    QWidget* central_widget;
    QTabWidget* tab_widget;
    SearchWidget* search_widget;
    AddWidget* add_widget;

    void keyPressEvent(QKeyEvent* event) override;
};

#endif  // MAIN_WINDOW_H
