#ifndef FORMWIDGET_H
#define FORMWIDGET_H

#include <QFormLayout>
#include <QLineEdit>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class FormWidget;
}
QT_END_NAMESPACE

class FormWidget: public QWidget {
    Q_OBJECT

  public:
    explicit FormWidget(QWidget* parent = nullptr);
    ~FormWidget() override;

    QString title() const;
    QString authors() const;
    // public slots:
    //   void addButtonClicked() const;

    // signals:
    //   void addBook(Book& book) const;
    //   // void bookAdded(Book& book);

  private:
    Ui::FormWidget* ui;
    QFormLayout* form_layout;
    QLineEdit* title_line;
    QLineEdit* authors_line;

    // void createContent();
};

#endif  // FORMWIDGET_H
