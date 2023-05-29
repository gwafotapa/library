#include "add_widget.h"

#include <qboxlayout.h>
#include <qcombobox.h>
#include <qstackedwidget.h>

// #include <qformlayout.h>
// #include <qlineedit.h>
// #include <qnamespace.h>

#include "ui_add_widget.h"

AddWidget::AddWidget(QWidget* parent) : QWidget(parent), ui(new Ui::AddWidget) {
    ui->setupUi(this);

    // combo_box = new QComboBox;
    // stacked_widget = new QStackedWidget;
    // add_std_book_widget = new AddStdBookWidget;
    // add_comic_book_widget = new AddComicBookWidget;
    // add_author_widget = new AddAuthorWidget;

    // stacked_widget->addWidget(add_std_book_widget);
    // stacked_widget->addWidget(add_comic_book_widget);
    // stacked_widget->addWidget(add_author_widget);

    // QVBoxLayout* layout = new QVBoxLayout;
    // layout->addWidget(stacked_widget);
    // setLayout(layout);
}

AddWidget::~AddWidget() {
    delete ui;
}
