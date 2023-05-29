#ifndef ADD_COMIC_BOOK_WIDGET_H
#define ADD_COMIC_BOOK_WIDGET_H

#include <QCheckBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QWidget>

namespace Ui {
class AddComicBookWidget;
}

class AddComicBookWidget: public QWidget {
    Q_OBJECT

  public:
    explicit AddComicBookWidget(QWidget* parent = nullptr);
    ~AddComicBookWidget();

  private:
    Ui::AddComicBookWidget* ui;
    QFormLayout* form_layout;
    QLineEdit* title_line;
    QLineEdit* writers_line;
    QLineEdit* illustrators_line;
    QCheckBox* check_box;

  private slots:
    void writer_illustrator(int state);
    void copy_writer_to_illustrator();
};

#endif  // ADD_COMIC_BOOK_WIDGET_H
