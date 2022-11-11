#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    double compute_result() const;

public slots :
    void number_clicked();
    void operator_clicked();
    void equal_clicked();
    void clear_clicked();
};

#endif // WIDGET_H
