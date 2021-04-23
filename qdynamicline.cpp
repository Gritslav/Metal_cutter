#include "qdynamicline.h"

qdynamicline::qdynamicline(QWidget *parent) : QLineEdit(parent)
{
    ResID++;            // Увеличение счетчика на единицу
    lineID = ResID;   /* Присвоение линии номера, по которому будет производиться
                         * дальнейшая работа с ней
                         * */
}
qdynamicline::~qdynamicline()
{

}
/* Метод для возврата значения номера линии*/
int qdynamicline::getID()
{
    return lineID;
}

/* Инициализация статической переменной класса.
Статическая переменная класса должна инициализироваться в обязательном порядке*/
int qdynamicline::ResID = 0;






