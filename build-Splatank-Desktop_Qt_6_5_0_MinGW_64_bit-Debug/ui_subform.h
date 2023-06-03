/********************************************************************************
** Form generated from reading UI file 'subform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBFORM_H
#define UI_SUBFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_subForm
{
public:

    void setupUi(QWidget *subForm)
    {
        if (subForm->objectName().isEmpty())
            subForm->setObjectName("subForm");
        subForm->resize(927, 621);

        retranslateUi(subForm);

        QMetaObject::connectSlotsByName(subForm);
    } // setupUi

    void retranslateUi(QWidget *subForm)
    {
        subForm->setWindowTitle(QCoreApplication::translate("subForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class subForm: public Ui_subForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBFORM_H
