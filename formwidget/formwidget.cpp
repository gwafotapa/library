#include "formwidget.h"

#include <qformlayout.h>
#include <qlineedit.h>
#include <qnamespace.h>

#include "ui_formwidget.h"

FormWidget::FormWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::FormWidget) {
    ui->setupUi(this);

    title_line = new QLineEdit;
    // title_line->setReadOnly(true);
    QPalette palette;
    palette.setColor(QPalette::Base, Qt::lightGray);
    palette.setColor(QPalette::Text, Qt::darkGray);
    title_line->setPalette(palette);

    authors_line = new QLineEdit;
    authors_line->setPlaceholderText("Author1, Author2, ...");

    form_layout = new QFormLayout(this);
    form_layout->addRow("Title", title_line);
    form_layout->addRow("Authors", authors_line);
}

QString FormWidget::title() const {
    return title_line->text();
}

QString FormWidget::authors() const {
    return authors_line->text();
}

FormWidget::~FormWidget() {
    delete ui;
}
