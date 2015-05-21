#ifndef CONTROL
#define CONTROL
#include <QObject>
#include <QTimer>
#include <QDebug>

class control : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool A READ getA WRITE setA NOTIFY AChanged)
    Q_PROPERTY(bool B READ getB WRITE setB NOTIFY BChanged)
    Q_PROPERTY(bool C READ getC WRITE setC NOTIFY CChanged)
    bool A;
    bool B;
    bool C;
public slots:
    void plasticReady(bool ready);
    void event1();
    void event2();
    void event3();
private slots:
    void setA(bool change);
    void setB(bool change);
    void setC(bool change);
public:
    control();
    bool getA() const;
    bool getB() const;
    bool getC() const;
signals:
    void AChanged(bool A);
    void BChanged(bool B);
    void CChanged(bool C);
};

#endif // CONTROL

