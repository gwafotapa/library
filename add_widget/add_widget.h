#ifndef ADD_WIDGET_H
#define ADD_WIDGET_H

/* #include <QFormLayout> */
/* #include <QLineEdit> */
#include <QComboBox>
#include <QStackedWidget>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class AddWidget;
}
QT_END_NAMESPACE

class AddWidget: public QWidget {
    Q_OBJECT

  public:
    explicit AddWidget(QWidget* parent = nullptr);
    ~AddWidget() override;

  private:
    Ui::AddWidget* ui;
    QComboBox* combo_box;
    QStackedWidget* stacked_widget;
    /* AddStdBookWidget* add_std_book_widget; */
    /* AddComicBookWidget* add_comic_book_widget; */
    /* AddAuthorWidget* add_author_widget; */
};

#endif  // ADD_WIDGET_H
