#ifndef SEARCH_WIDGET_H
#define SEARCH_WIDGET_H

#include <qboxlayout.h>

#include <QBoxLayout>
#include <QComboBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QWidget>

#include "data_model.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class SearchWidget;
}
QT_END_NAMESPACE

// class LabelLineEdit: public QWidget {
//   public:
//     LabelLineEdit(const QString& label_text, QWidget* parent = nullptr) :
//         QWidget(parent) {
//         label = new QLabel(label_text);
//         linedit = new QLineEdit;
//         layout = new QHBoxLayout;
//         layout->addWidget(label);
//         layout->addWidget(linedit);
//         setLayout(layout);
//     }
//     ~LabelLineEdit() {}

//   private:
//     QLabel* label;
//     QLineEdit* linedit;
//     QHBoxLayout* layout;
// };

class SearchWidget: public QWidget {
    Q_OBJECT

  public:
    explicit SearchWidget(QWidget* parent = nullptr);
    ~SearchWidget() override;
    // QComboBox* get_combo_box() const;

  signals:
    // void select_table(const QString& table);
    void search_standard_books(const QString& title, const QString& writers);
    void search_comic_books(
        const QString& title,
        const QString& writers,
        const QString& illustrators);

  private:
    Ui::SearchWidget* ui;
    QVBoxLayout* main_layout;
    QFormLayout* form_layout;
    QHBoxLayout* buttons_layout;

    QComboBox* combo_box;
    QLineEdit* title_line;
    QLineEdit* writers_line;
    QLineEdit* illustrators_line;
    // LabelLineEdit* illustrators_widget;
    QPushButton* search_button;
    QPushButton* clear_button;
    QLabel* results_label;
    DataModel* data_model;
    QTableView* table_view;

  private slots:
    void select_search(int book_type);
    void clear();
    void set_results_label();
};

#endif  // SEARCH_WIDGET_H
