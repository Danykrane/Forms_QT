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
    New_widget wid(26);
    wid.show();




    //    QObject::connect(&cmd, SIGNAL(clicked()),
    //                     &counter, SLOT(slotInc())
    //
    //    );

    //    QObject::connect(&cmd, &QPushButton::clicked, &counter,
    //    &Counter::slotInc);

    //    QObject::connect(&counter,
    //                     &Counter::counterChanged,
    //                     &lbl,
    //                     func);

    //    QObject::connect(&counter, SIGNAL(goodbye()), &app, SLOT(quit()));

    return app.exec();
}
