#include "form.h"
#include "ui_form.h"
#include "widget.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    Widget w;
    w.show();
    w.StartGame();
}


void Form::on_pushButton_2_clicked()
{
    close();
}

