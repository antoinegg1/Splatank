#include "introduce.h"
#include "ui_introduce.h"
#include "widget.h"

introduce::introduce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::introduce)
{
    ui->setupUi(this);
}

introduce::~introduce()
{
    delete ui;
}




void introduce::on_pushButton_clicked()
{
    emit mySignal();
}

