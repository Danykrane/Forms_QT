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

void New_widget::createQtWidgets()
{
    QLabel* lbl = new QLabel(tr("0"));
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
        QString num_elem
            = QString::number(i + 1); // вынес как отдельную переменную
        QPushButton* ptr = createButton(("Btn " + num_elem));
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

QPushButton* New_widget::createButton(const QString& text)
{
    QPushButton* button = new QPushButton(text);

    return button;
}
