#ifndef NEW_WIDGET_H
#define NEW_WIDGET_H

#include <QDebug>
#include <QObject>
#include <QWidget>
#include <QtWidgets>

class New_widget : public QWidget
{
public:
    New_widget(QWidget* parent = nullptr);
    New_widget(quint16 col_elem = 0); // конструктор для кол-ва кнопок

private:
    quint16 col_elem;
    void createQtWidgets();
    void createQtConnections();

    QPushButton* createButton(const QString& text);
    QLabel* createlabel(const QString& text);

    QMap<QPushButton*, int> buttonMap;
};

#endif // NEW_WIDGET_H
