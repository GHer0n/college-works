#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <QString>
#include <ctime>
#include <random>
#include <QMessageBox>

namespace gft{

class Conjunto
{
private:
    int tamanho = 0;
    int *array = 0;
    int *arraySelectionSort = 0;

public:
    Conjunto(int tamanho);
    ~Conjunto();
    int getConjunto();

    int getTamanho() const;
    void setTamanho(int newTamanho);
    QString obterVetor() const;

    void selectionSort();
    QString obterVetorSelectionSort();
    int buscarNumMelhorado(int aux) const;
};
}
#endif // CONJUNTO_H
