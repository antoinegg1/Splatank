#ifndef INTRODUCE_H
#define INTRODUCE_H

#include <QWidget>
#include <QObject>
namespace Ui {
class introduce;
}

class introduce : public QWidget
{
    Q_OBJECT

public:
    explicit introduce(QWidget *parent = nullptr);
    ~introduce();



private:
    Ui::introduce *ui;
signals:
    void mySignal();
private slots:
    void on_pushButton_clicked();
};

#endif // INTRODUCE_H
