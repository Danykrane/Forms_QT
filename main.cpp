#include "new_widget.h"
#include <QtGlobal>
#include <QtWidgets>

#include <QDebug>

// void func(int value) { qDebug() << __FUNCTION__ << value; }

int main(int argc, char** argv)
{

    //    auto ukaz = &func;
    //    void (*funcPtr)(int) = func;

    //    funcPtr(123);

    QApplication app(argc, argv);
    New_widget wid(54);
    wid.show();

    return app.exec();
}
