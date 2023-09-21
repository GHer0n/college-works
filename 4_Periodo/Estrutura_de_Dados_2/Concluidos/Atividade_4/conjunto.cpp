#include "conjunto.h"

namespace gft {

Conjunto::Conjunto(int tamanho)
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
    for (int step = 0; step < tamanho - 1; ++step) {
        int min_idx = step;
        for (int i = step + 1; i < tamanho; ++i) {
            if (arraySelectionSort[i] < arraySelectionSort[min_idx]) { // Condição corrigida
                min_idx = i;
            }
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

int Conjunto::buscarNumMelhorado(int aux) const
{
    for (int i = 0; i < tamanho; ++i) {
        if(aux == arraySelectionSort[i])
            return i;
        if(aux < arraySelectionSort[i])
            throw QString("Percorri todo o vetor e nao encontrei o valor desejado");
    }
    throw QString ("O numero desejado nao existe");
}

int Conjunto::buscaBinaria(int x) const
{
    int inicio = 0, fim = tamanho -1;
    while(inicio <= fim){
        int meio = (inicio + fim)/2;
        if(arraySelectionSort[meio] == x) return meio;
        if(arraySelectionSort[meio] < x) inicio = meio + 1;
        else {
            fim = meio - 1;
        }
    }
    throw QString ("O numero desejado nao existe - buscaBinaria");
}

}
