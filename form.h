#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <iostream>
#include <QGraphicsView>
#include <QTextStream>
#include <QProcess>
#include"avl.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Form *ui;
    QGraphicsScene scene;
    QGraphicsView *view;
    AVL* a ;
};

#endif // FORM_H
