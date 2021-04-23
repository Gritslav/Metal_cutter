#ifndef QDYNAMICLINE_H
#define QDYNAMICLINE_H

#include <QLineEdit>

class qdynamicline : public QLineEdit
{
     Q_OBJECT
public:
    explicit qdynamicline(QWidget *parent = 0);
    ~qdynamicline();
    static int ResID;   // Статическая переменная, счетчик номеров линий
    int getID();        // Функция для возврата локального номера линии

public slots:

private:
    int lineID = 0;   // Локальная переменная, номер линии
};


#endif // QDYNAMICLINE_H




