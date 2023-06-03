#ifndef SUBFORM_H
#define SUBFORM_H

#include <QWidget>

namespace Ui {
class subForm;
}

class subForm : public QWidget
{
    Q_OBJECT

public:
    explicit subForm(QWidget *parent = nullptr);
    ~subForm();

private:
    Ui::subForm *ui;
};

#endif // SUBFORM_H
