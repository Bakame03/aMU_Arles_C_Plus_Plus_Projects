#ifndef FENETRE_H
#define FENETRE_H

#include <QWidget>

class Fenetre : public QWidget
{
    Q_OBJECT

public:
    Fenetre(QWidget *parent = nullptr);
    ~Fenetre();
};
#endif // FENETRE_H
