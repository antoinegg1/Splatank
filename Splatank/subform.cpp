#include "subform.h"
#include "ui_subform.h"

subForm::subForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subForm)
{
    ui->setupUi(this);
}

subForm::~subForm()
{
    delete ui;
}
