#include "add_widget.h"

#include <qpushbutton.h>

#include <QBoxLayout>
#include <QComboBox>
#include <QHeaderView>
#include <QPushButton>
#include <QStackedWidget>

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

    add_book_widget = new AddBookWidget;
    add_author_widget = new AddAuthorWidget;

    stacked_widget = new QStackedWidget;
    stacked_widget->addWidget(add_book_widget);
    stacked_widget->addWidget(add_author_widget);

    table_view = new QTableView;
    table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table_view->setModel(data_model);
    this->data_model = data_model;
    data_model->setTable(
        "Standard Books");  // TODO: replace all table strings with constants
    data_model->select();

    main_layout = new QVBoxLayout;
    main_layout->addWidget(combo_box);
    main_layout->addWidget(stacked_widget);
    main_layout->addWidget(table_view);
    main_layout->addStretch();

    // TODO: put message here for both add_book_widget and add_author_widget

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

    connect(combo_box, &QComboBox::currentIndexChanged, [&](int i) {
        switch (i) {
            case 0:
                table_view->setVisible(true);
                this->data_model->setTable("Standard Books");
                this->data_model->select();
                break;
            case 1:
                table_view->setVisible(true);
                this->data_model->setTable("Comic Books");
                this->data_model->select();
                break;
            case 2:
                table_view->setVisible(false);
                break;
        }
    });
}

AddWidget::~AddWidget() {
    delete ui;
}

// QComboBox* AddWidget::get_combo_box() const {
//     return combo_box;
// }

AddBookWidget* AddWidget::book() const {
    return add_book_widget;
}

AddAuthorWidget* AddWidget::author() const {
    return add_author_widget;
}
