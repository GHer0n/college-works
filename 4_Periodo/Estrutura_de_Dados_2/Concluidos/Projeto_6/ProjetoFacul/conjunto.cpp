#include "conjunto.h"

namespace gft {

Conjunto::Conjunto(int tamanho):
    execucoes(0)
{
    if(tamanho < 0) throw QString("valor do tamanho do vetor tem de ser maior que 0");
    try {
        array = new int [tamanho];
        arraySelectionSort = new int [tamanho];
        this->tamanho = tamanho;
    } catch (std::bad_alloc) {
    }
    // Obtém os segundos atuais do relógio do sistema
    std::time_t currentTime = std::time(nullptr);

    // Usa os segundos atuais como semente para o gerador de números aleatórios
    std::default_random_engine randomEngine(currentTime);

    // Cria a distribuição de números aleatórios entre 0 e 100
    std::uniform_int_distribution<int> distribution(0, 1000);

    // Gera números aleatórios e os insere no vetor
    for (int i = 0; i < tamanho; ++i) {
        int randomNumber = distribution(randomEngine);
        array[i] = randomNumber;
        arraySelectionSort[i] = randomNumber;
    }

}

Conjunto::~Conjunto()
{
    delete array;
    delete arraySelectionSort;
}

int Conjunto::getExecucoes() const
{
    return execucoes;
}

int Conjunto::getTamanho() const
{
    return tamanho;
}

QString Conjunto::obterVetor() const
{
    QString resultado = "|";
    for(int pos = 0; pos < tamanho; pos++){
        resultado += QString::number(array[pos]);
        if(pos < tamanho -1)
            resultado += "|->|";
    }
    resultado += "|";
    return resultado;
}


void Conjunto::selectionSort()
{
    this->execucoes=0;
    for (int step = 0; step < tamanho - 1; ++step) {
        int min_idx = step;
        for (int i = step + 1; i < tamanho; ++i) {
            if (arraySelectionSort[i] < arraySelectionSort[min_idx]) { // Condição corrigida
                min_idx = i;
            }
            execucoes++;
        }
        int aux = arraySelectionSort[step];
        arraySelectionSort[step] = arraySelectionSort[min_idx];
        arraySelectionSort[min_idx] = aux;
    }
}


QString Conjunto::obterVetorSelectionSort()
{
    // Chama o método selectionSort para ordenar o vetor
    selectionSort();

    QString resultado = "|";
    for (int pos = 0; pos < tamanho; pos++) {
        resultado += QString::number(arraySelectionSort[pos]);
        if (pos < tamanho - 1)
            resultado += "|->|";
    }
    resultado += "|";
    return resultado;
}

int Conjunto::buscarNumMelhorado(int aux)
{
    this->execucoes=0;
    for (int i = 0; i < tamanho; ++i) {
        execucoes++;
        if(aux == arraySelectionSort[i])
            return i;
        if(aux < arraySelectionSort[i]){
            return -1;
        }
    }
    return -1;
}

int Conjunto::buscaBinaria(int x)
{
    this->execucoes=0;
    int inicio = 0, fim = tamanho -1;

    while(inicio <= fim){
        execucoes++;
        int meio = (inicio + fim)/2;
        if(arraySelectionSort[meio] == x) return meio;
        if(arraySelectionSort[meio] < x) inicio = meio + 1;
        else {
            fim = meio - 1;
        }
    }
    return -1;
}

int Conjunto::BuscarNum(int aux)
{
    this->execucoes=0;
    QString resultado = "[";
    for (int i = 0; i < tamanho; ++i) {
        execucoes++;
        if(aux == array[i])
            return i;
    }
    execucoes++;
    return -1;
}

}
