#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <QString>
#include <ctime>
#include <random>
#include <QMessageBox>
#include <list>
namespace gft{

class Conjunto
{
private:
    int tamanho = 0;
    int *array = 0;
    int *arraySelectionSort = 0;
    int execucoes;

public:
    Conjunto(int tamanho);
    ~Conjunto();
    int getConjunto();
    int getExecucoes() const;

    int getTamanho() const;
    void setTamanho(int newTamanho);
    QString obterVetor() const;

    void selectionSort();
    QString obterVetorSelectionSort();
    int buscarNumMelhorado(int aux);
    int buscaBinaria(int x);
    int BuscarNum(int aux);

};
}
#endif // CONJUNTO_H
