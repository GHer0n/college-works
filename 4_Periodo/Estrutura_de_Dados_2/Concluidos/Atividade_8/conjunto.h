#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <QString>
#include <ctime>
#include <random>
#include <QMessageBox>
#include <list>
#include <chrono>

namespace gft{

class Conjunto
{
private:
    int tamanho = 0;
    int *array = 0;
    int *arraySelectionSort = 0;
    int *arrayInsertionSort = 0;
    int *arrayBubbleSort = 0;
    int execucoesSS;
    int execucoesIS;
    int execucoesBS;

public:
    Conjunto(int tamanho);
    ~Conjunto();

    int getConjunto();
    int getExecucoesSS() const;
    int getExecucoesIS() const;
    int getExecucoesBS() const;

    int getTamanho() const;
    void setTamanho(int newTamanho);

    void selectionSort();
    void insertionSort();
    void bubbleSort();

    double TempoSelectionSort();
    double TempoInserctionSort();
    double TempoBubbleSort();

    QString obterVetor() const;
    QString obterVetorSelectionSort();
    QString obterVetorInsertionSort();
    QString obterVetorBubbleSort();

    //int buscarNumMelhorado(int aux);
    //int buscaBinaria(int x);
    //int BuscarNum(int aux);

};
}
#endif // CONJUNTO_H
