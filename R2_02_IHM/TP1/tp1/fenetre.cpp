#include "fenetre.h"

Fenetre::Fenetre(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("ConvertDist");
    setWindowFlags(Qt::WindowStaysOnTopHint);
    resize(250,150);
}

Fenetre::~Fenetre() {}
