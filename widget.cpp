#include "widget.h"

Widget::Widget(QWidget* parent)
    : QWidget { parent }
{

    QLabel* lbl = new QLabel("0");
    QPushButton* cmd = new QPushButton("ADD");
    QGridLayout* mainLayout = new QGridLayout;
    //! [5] //! [6]


    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(lbl, 0, 0, 1, 6);
    mainLayout->addWidget(cmd, 1, 0, 1, 2);

    //    for (int i = 1; i < NumDigitButtons; ++i) {
    //        int row = ((9 - i) / 3) + 2;
    //        int column = ((i - 1) % 3) + 1;
    //        mainLayout->addWidget(digitButtons[i], row, column);
    //    }

    //    mainLayout->addWidget(digitButtons[0], 5, 1);
    //    mainLayout->addWidget(pointButton, 5, 2);
    //    mainLayout->addWidget(changeSignButton, 5, 3);

    //    mainLayout->addWidget(divisionButton, 2, 4);
    //    mainLayout->addWidget(timesButton, 3, 4);
    //    mainLayout->addWidget(minusButton, 4, 4);
    //    mainLayout->addWidget(plusButton, 5, 4);

    //    mainLayout->addWidget(squareRootButton, 2, 5);
    //    mainLayout->addWidget(powerButton, 3, 5);
    //    mainLayout->addWidget(reciprocalButton, 4, 5);
    //    mainLayout->addWidget(equalButton, 5, 5);
    setLayout(mainLayout);
}
