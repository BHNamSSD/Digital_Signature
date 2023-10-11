#include "digital_signature.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DIGITAL_SIGNATURE w;
    w.show();
    return a.exec();
}
