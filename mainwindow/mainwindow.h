#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>

#include "../buttonswidget/buttonswidget.h"
#include "../formwidget/formwidget.h"

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
    QWidget* central_widget;
    QVBoxLayout* v_box_layout;
    // QHBoxLayout* qHBoxLayout;
    FormWidget* form_widget;
    ButtonsWidget* buttons_widget;
    // ListWidget* listWidget;
};

#endif  // MAINWINDOW_H
