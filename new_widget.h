#ifndef NEW_WIDGET_H
#define NEW_WIDGET_H

#include <QDebug>
#include <QMap>
#include <QObject>
#include <QWidget>
#include <QtWidgets>

class New_widget : public QWidget
{
    Q_OBJECT
private:
    quint16 col_elem;
    void createQtWidgets();
    void createQtConnections();
    //    void showData_map(const QMap<QPushButton*, int>&,const size_t
    //    &,void(New_widget::*)());

    // QPushButton* createButton(const QString&);

    // привязка кнопки к слоту при создании
    QPushButton* createButton(const QString& text, void (New_widget::*)());
    QMap<QPushButton*, int> buttonMap;
    QLabel* lbl; // поле вывода

public:
//    New_widget(QWidget* parent = nullptr);
    New_widget(quint16 col_elem = 0, QWidget* parent = nullptr); // конструктор для кол-ва кнопок

private slots:
    void buttonClicked();
//    void sendData();

signals:
    void setLabel();
};

#endif // NEW_WIDGET_H
