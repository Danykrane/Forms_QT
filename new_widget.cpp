#include "new_widget.h"

New_widget::New_widget(QWidget* parent)
    : QWidget(parent)
{
    createQtWidgets();
}

// конструктор для одного аргумента (кол-ва кнопок)
New_widget::New_widget(quint16 col_elem)
    : col_elem(col_elem)
{
    createQtWidgets();
}

void New_widget::buttonClicked()
{

    // узнаю текст кнопки
    QPushButton* clicked_button = qobject_cast<QPushButton*>(sender());
    QString rez_str = clicked_button->text() + " clicked!";

    // qDebug() <<rez_str;

    // передаю на QLabel
    lbl->setText(rez_str);
}

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

    QWidget* window = new QWidget;

    // создаем группу вертикальных кнопок
    QVBoxLayout* col_layout = new QVBoxLayout(window);
    QHBoxLayout* row_layout = new QHBoxLayout(window);
    for (int i = 0; i < col_elem; ++i)
    {
        // вынес как отдельную переменную
        QString num_elem = "Btn " + QString::number(i + 1);

        // создаем кнопку и обрабатываем сигнал на слоте buttonClicked()
        QPushButton* ptr = createButton(num_elem, &New_widget::buttonClicked);

        buttonMap.insert(ptr, i); // убрал дублирование i + 1

        row_layout->addWidget(ptr);

        // Добавление нового горизонтального layout с кнопками, если добавили 5
        // кнопок
        if ((i + 1) % 5 == 0)
        {
            col_layout->addLayout(row_layout);
            row_layout = new QHBoxLayout;
        }
    }

    // Если кнопок не кратно 5
    if (row_layout->count() > 0)
    {
        col_layout->addLayout(row_layout);
    }

    col_layout->addStretch(5);
    col_layout->addWidget(lbl, 0, Qt::AlignBottom | Qt::AlignHCenter);
    col_layout->addStretch(1);

    setLayout(col_layout);

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
