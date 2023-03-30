#ifndef NEW_WIDGET_H
#define NEW_WIDGET_H

#include <QDebug>
#include <QObject>
#include <QWidget>
#include <QtWidgets>

class New_widget : public QWidget
{
private:
    quint16 col_elem;
    void createQtWidgets();
    void createQtConnections();

    //QPushButton* createButton(const QString&);

    // привязка кнопки к слоту при создании
    QPushButton* createButton(const QString& text, void(New_widget::*)());
    QMap<QPushButton*, int> buttonMap;
    QLabel* lbl; // поле вывода

public:
    New_widget(QWidget* parent = nullptr);
    New_widget(quint16 col_elem = 0); // конструктор для кол-ва кнопок

private slots:
    void buttonClicked();


signals:
    void setlabel();

};

#endif // NEW_WIDGET_H
