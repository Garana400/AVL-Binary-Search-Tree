#include "form.h"
#include <QApplication>

#include <iostream>
#include <QGraphicsView>
#include <QTextStream>
#include <QProcess>
#include"avl.h"

int main(int argc, char *argv[])
{
        QApplication app(argc, argv);
        Form F;
        F.show();
        return app.exec();
}
