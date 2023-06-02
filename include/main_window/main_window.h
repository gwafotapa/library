#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QWidget>

#include "add_widget.h"
#include "data_model.h"
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

    void add_author(QString& author) const;
    void add_authors(QStringList& authors) const;
    void add_book(QString& title, QString& authors) const;

  private:
    Ui::MainWindow* ui;
    // QVBoxLayout* main_layout;
    QTabWidget* tab_widget;
    SearchWidget* search_widget;
    AddWidget* add_widget;
    // FormWidget* form_widget;
    // ButtonsWidget* buttons_widget;
    // // SearchWidget* search_widget;
    DataModel* data_model;

    void keyPressEvent(QKeyEvent* event);

  private slots:
    void add_data();
    void add_data2();
    void search_data();
    // void filter_search_data();
};

#endif  // MAIN_WINDOW_H
