#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>

#include "../buttonswidget/buttonswidget.h"
#include "../datamodel/datamodel.h"
#include "../formwidget/formwidget.h"
#include "../tablewidget/tablewidget.h"

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
    TableWidget* table_widget;
    DataModel* data_model;

  private slots:
    void add_data();
    void search_data();
};

#endif  // MAINWINDOW_H
