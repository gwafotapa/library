//
// Created by Administrateur on 26/05/2023.
//

#ifndef LIBRARY_MAINWINDOW_H
#define LIBRARY_MAINWINDOW_H

#include <QMainWindow>

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
};

#endif  //LIBRARY_MAINWINDOW_H
