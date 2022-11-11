#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

double Widget::compute_result() const
{
    const QString operator_text = ui->label_operator->text();
    const double old_content = ui->lcdMemo->value();
    const double new_content = ui->lcdResult->value();
    double result = 0;
    if (operator_text=="+"){
        result = old_content + new_content;
    }
    else if (operator_text=="-"){
        result = old_content - new_content;
    }
    else if (operator_text=="*"){
        result = old_content * new_content;
    }
    else if (operator_text=="/"){
        if (new_content==0){
            result = 12;
        }
        else {
            result = old_content / new_content;
        }
    }
    return result;
}

void Widget::number_clicked()
{
    const double sender_content = static_cast<QPushButton*>(sender())->text().toDouble();
    const double lcd_content = ui->lcdResult->value();
    ui->lcdResult->display(lcd_content*10+sender_content);
}

void Widget::operator_clicked()
{
    double result = 0;
    if (ui->label_operator->text().isEmpty()) {
        result = ui->lcdResult->value();
    } else {
        result = compute_result();
    }

    //transfer lcd_content to memo
    ui->lcdMemo->display(result);

    //display selected operator
    const QString operator_text = static_cast<QPushButton*>(sender())->text();
    ui->label_operator->setText(operator_text);

    //clear lcd_content
    ui->lcdResult->display(0);
}

void Widget::equal_clicked()
{
    if (ui->label_operator->text().isEmpty()){
        return;
    }
    double result = compute_result();
    ui->lcdResult->display(result);
    ui->label_operator->setText("");
    ui->lcdMemo->display(0);
}

void Widget::clear_clicked()
{
    ui->lcdResult->display(0);
    ui->label_operator->setText("");
    ui->lcdMemo->display(0);
}


