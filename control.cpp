#include "control.h"

control::control() {
    this->A = this->A = false;
    this->B = true;
}
void control::plasticReady(bool ready) {
    if (ready) {
        event1();
    }
    else {
        qDebug() << "Error";
    }
}
void control::event1() {
    setA(true);
    qDebug() << "New Bottle";
    qDebug() << "Bottling Started";
    QTimer::singleShot(5000, this, SLOT(event2()));
}
void control::event2() {
    setA(false);
    setC(true);
    qDebug() << "Plastic Bottling Size Reached";
    qDebug() << "Molding Bottle";
    QTimer::singleShot(500, this, SLOT(event3()));
}
void control::event3() {
    setB(false);
    QTimer::singleShot(4000, this, SLOT(event1()));
    setB(true);
    setC(false);
    qDebug() << "Bottle Ready";
}
void control::setA(bool change) {
    if (getA() != change) {
        this->A = change;
        emit this->AChanged(change);
    }
}
void control::setB(bool change) {
    if (getB() != change) {
        this->B = change;
        emit this->BChanged(change);
    }
}
void control::setC(bool change) {
    if (getC() != change) {
        this->A = change;
        emit this->CChanged(change);
    }
}
bool control::getA() const {
    return this->A;
}
bool control::getB() const {
    return this->B;
}
bool control::getC() const {
    return this->A;
}
