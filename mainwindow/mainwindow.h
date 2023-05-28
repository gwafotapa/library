#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>

#include "../buttonswidget/buttonswidget.h"
#include "../datamodel/datamodel.h"
#include "../formwidget/formwidget.h"
#include "../searchwidget/searchwidget.h"
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

    void add_author(QString& author) const;
    void add_authors(QStringList& authors) const;
    void add_book(QString& title, QString& authors) const;

  private:
    Ui::MainWindow* ui;
    QWidget* central_widget;
    QVBoxLayout* v_box_layout;
    FormWidget* form_widget;
    ButtonsWidget* buttons_widget;
    // SearchWidget* search_widget;
    TableWidget* table_widget;
    DataModel* data_model;

  private slots:
    void add_data();
    void add_data2();
    void search_data();
    // void filter_search_data();
};

#endif  // MAINWINDOW_H
