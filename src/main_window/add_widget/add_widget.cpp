#include "add_widget.h"

#include <qboxlayout.h>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qstackedwidget.h>

// #include <qformlayout.h>
// #include <qlineedit.h>
// #include <qnamespace.h>

#include "ui_add_widget.h"

AddWidget::AddWidget(DataModel* data_model, QWidget* parent) :
    QWidget(parent),
    ui(new Ui::AddWidget) {
    ui->setupUi(this);

    combo_box = new QComboBox;
    combo_box->addItem("Book");
    combo_box->addItem("Comic book");
    combo_box->addItem("Author");

    add_book_widget = new AddBookWidget(data_model);
    add_author_widget = new AddAuthorWidget;

    stacked_widget = new QStackedWidget;
    stacked_widget->addWidget(add_book_widget);
    stacked_widget->addWidget(add_author_widget);

    // QHBoxLayout* stacked_widget_layout = new QHBoxLayout;
    // stacked_widget->setLayout(stacked_widget_layout);

    main_layout = new QVBoxLayout;
    main_layout->addWidget(combo_box);
    main_layout->addWidget(stacked_widget);
    // main_layout->addStretch();
    // main_layout->addLayout(buttons_layout);
    setLayout(main_layout);

    // connect(combo_box, &QComboBox::currentIndexChanged, [&](int index) {
    //     stacked_widget->setFixedHeight(
    //         stacked_widget->currentWidget()->sizeHint().height());
    // });

    connect(combo_box, &QComboBox::currentIndexChanged, [&](int index) {
        stacked_widget->setCurrentIndex(index <= 1 ? 0 : 1);
    });

    connect(
        combo_box,
        &QComboBox::currentIndexChanged,
        add_book_widget,
        &AddBookWidget::select_book_type);
}

AddWidget::~AddWidget() {
    delete ui;
}

AddBookWidget* AddWidget::book() const {
    return add_book_widget;
}

AddAuthorWidget* AddWidget::author() const {
    return add_author_widget;
}
