#include "fenetre.h"

Fenetre::Fenetre(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("ConvertDist");
    setWindowFlags(Qt::WindowStaysOnTopHint);
    resize(250,150);

    valeurMetre = new QDoubleSpinBox(this);
    valeurFoot = new QDoubleSpinBox(this);
    valeurInch = new QDoubleSpinBox(this);
}

Fenetre::~Fenetre() {}
