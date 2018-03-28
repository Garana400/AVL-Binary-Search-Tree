#include "form.h"
#include "ui_form.h"
#include "avl.h"
#include <QGraphicsView>
#include <QTextStream>
#include <QProcess>
#include <QTextEdit>
#include <QMessageBox>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    view = new QGraphicsView(&scene) ;
    view->setRenderHints(QPainter::SmoothPixmapTransform);
    a = new AVL () ;
    a->init(&scene , view) ;
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    a->insert(ui->lineEdit->text().toInt());

    a->show();
}



void Form::on_pushButton_2_clicked()
{
    a->deleteNode(ui->lineEdit_2->text().toInt());
    a->show();
}



void Form::on_pushButton_3_clicked()
{
    bool temp = a->findElem(ui->lineEdit_3->text().toInt()) ;
    if (temp == true)
    {
       QMessageBox::information(this,tr("AVL"),tr("Found"));

    }else
    {
        QMessageBox::information(this,tr("AVL"),tr(" not Found"));
    }
}
