#include "new_widget.h"

void printQObjectTree(QObject* root, size_t coltab = 0)
{
    QString tabs;
    tabs.fill('\t', coltab);
    qDebug().noquote() << tabs << root;
    // QObject next = (root->children());
    for (auto& it : root->children())
    {
        printQObjectTree(it, coltab + 1);
    }
}

// New_widget::New_widget(QWidget* parent)
//     : QWidget(parent)
//{
//     createQtWidgets();
// }

// конструктор для одного аргумента (кол-ва кнопок)
New_widget::New_widget(quint16 col_elem, QWidget* parent)
    : QWidget(parent)
    , col_elem(col_elem)
{
    setObjectName("MainWidget");
    createQtWidgets();
    printQObjectTree(this);
}

void New_widget::buttonClicked()
{

    // узнаю текст кнопки
    QPushButton* clicked_button = qobject_cast<QPushButton*>(sender());
    QString rez_str = "кнопка " + clicked_button->text() + " имеет значение: ";

    //    if (buttonMap.values(buttonMap[clicked_button]))
    //    qDebug() <<"Значение по ключу"<<buttonMap.value();
    // rez_str = QString::number(buttonMap.values())

    rez_str += QString::number(buttonMap[clicked_button]);
    // передаю на QLabel
    lbl->setText(rez_str);
}
const int KR = 5;
void New_widget::createQtWidgets()
{
    lbl = new QLabel(tr("0"));
    lbl->setFixedHeight(lbl->fontMetrics().height() * 5);

    QLineEdit* display = new QLineEdit("0");

    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

    // создаем группу вертикальных кнопок
    QVBoxLayout* col_layout = new QVBoxLayout(this);
    QHBoxLayout* row_layout;
    QWidget* hWidget;
    int ind = 0;
    int col_ost = col_elem % KR;
    int col_str = (col_elem - col_ost) / KR;
    bool flag = false;
    if (col_ost)
    {
        col_str++;
        flag = true;
    }
    for (int j = 0; j < col_str; j++)
    {

        hWidget = new QWidget;
        hWidget->setObjectName("Hwid" + QString::number(ind));
        row_layout = new QHBoxLayout(hWidget);
        row_layout->setContentsMargins(0, 0, 0, 0);
        col_layout->addWidget(hWidget,1);

        int cols = KR;

        if (col_elem - KR * j < KR)
        {
            cols = col_ost;
        }
        for (int i = 0; i < cols; ++i)
        {

            QString num_elem = "Btn " + QString::number(++ind);
            QPushButton* ptr
                = createButton(num_elem, &New_widget::buttonClicked);
            ptr->setObjectName(num_elem);

            buttonMap.insert(ptr, ind); // убрал дублирование i + 1
            if (flag)
            {
                row_layout->addWidget(ptr,1, Qt::AlignLeft);
            }
            else
            {
                row_layout->addWidget(ptr);
            }
        }
        if (flag){
            row_layout->addStretch(KR-col_ost);
        }
    }

    if (row_layout->count() > 0)
    {
        col_layout->addLayout(row_layout);
    }

    col_layout->addStretch(5);
    col_layout->addWidget(lbl, 0, Qt::AlignBottom | Qt::AlignHCenter);
    col_layout->addStretch(1);

    // по строке
    setWindowTitle(tr("test"));
}

// QPushButton* New_widget::createButton(const QString& text)
//{
//     QPushButton* button = new QPushButton(text);

//    return button;
//}

QPushButton* New_widget::createButton(const QString& text,
                                      void (New_widget::*slot)())
{
    QPushButton* button = new QPushButton(text);
    connect(button, &QPushButton::clicked, this, slot);
    // connect(button, SIGNAL(clicked()), this, slot_ic);
    return button;
}
