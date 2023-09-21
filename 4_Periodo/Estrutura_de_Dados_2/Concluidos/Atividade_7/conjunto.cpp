#include "conjunto.h"

namespace gft {

Conjunto::Conjunto(int tamanho):
    execucoesSS(0),
    execucoesIS(0)
{
    if(tamanho < 0) throw QString("valor do tamanho do vetor tem de ser maior que 0");
    try {
        array = new int [tamanho];
        arraySelectionSort = new int [tamanho];
        arrayInsertionSort = new int [tamanho];
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
        arrayInsertionSort[i] = randomNumber;
    }

}

Conjunto::~Conjunto()
{
    delete array;
    delete arraySelectionSort;
    delete arrayInsertionSort;
}

int Conjunto::getExecucoesSS() const
{
    return execucoesSS;
}

int Conjunto::getExecucoesIS() const
{
    return execucoesIS;
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
    this->execucoesSS=0;
    for (int step = 0; step < tamanho - 1; ++step) {
        int min_idx = step;
        for (int i = step + 1; i < tamanho; ++i) {
            if (arraySelectionSort[i] < arraySelectionSort[min_idx]) { // Condição corrigida
                min_idx = i;
            }
            execucoesSS++;
        }
        int aux = arraySelectionSort[step];
        arraySelectionSort[step] = arraySelectionSort[min_idx];
        arraySelectionSort[min_idx] = aux;
    }
}

void Conjunto::insertionSort()
{
    this->execucoesIS = 0;
    for (int step = 1; step < tamanho; step++) {
        int key = arrayInsertionSort[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < arrayInsertionSort[j] && j >= 0) {
          arrayInsertionSort[j + 1] = arrayInsertionSort[j];
          --j;
          execucoesIS++;
        }
        arrayInsertionSort[j + 1] = key;
      }
}

double Conjunto::TempoSelectionSort()
{
    // Registre o tempo de início para o selectionSort
    auto start_timeSS = std::chrono::high_resolution_clock::now();

    // Chame o método selectionSort
    selectionSort();

    // Registre o tempo de término para o selectionSort
    auto end_timeSS = std::chrono::high_resolution_clock::now();

    // Calcule a diferença de tempo para o selectionSort em milissegundos
    auto durationSS = std::chrono::duration_cast<std::chrono::microseconds>(end_timeSS - start_timeSS);

    double resultadoSS;
    resultadoSS = durationSS.count();

    return resultadoSS;
}
double Conjunto::TempoInserctionSort()
{
    // Registre o tempo de início para o insertionSort
    auto start_timeIS = std::chrono::high_resolution_clock::now();

    // Chame o método insertionSort
    insertionSort();

    // Registre o tempo de término para o insertionSort
    auto end_timeIS = std::chrono::high_resolution_clock::now();

    // Calcule a diferença de tempo para o insertionSort em milissegundos
    auto durationIS = std::chrono::duration_cast<std::chrono::microseconds>(end_timeIS - start_timeIS);

    double resultadoIS;
    resultadoIS = durationIS.count();

    return resultadoIS;
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

QString Conjunto::obterVetorInsertionSort()
{
    // Chama o método insectionSort para ordenar o vetor
    insertionSort();

    QString resultado = "|";
    for (int pos = 0; pos < tamanho; pos++) {
        resultado += QString::number(arrayInsertionSort[pos]);
        if (pos < tamanho - 1)
            resultado += "|->|";
    }
    resultado += "|";
    return resultado;
}

//int Conjunto::buscarNumMelhorado(int aux)
//{
//    this->execucoes=0;
//    for (int i = 0; i < tamanho; ++i) {
//        execucoes++;
//        if(aux == arraySelectionSort[i])
//            return i;
//        if(aux < arraySelectionSort[i]){
//            return -1;
//        }
//    }
//    return -1;
//}

//int Conjunto::buscaBinaria(int x)
//{
//    this->execucoes=0;
//    int inicio = 0, fim = tamanho -1;

//    while(inicio <= fim){
//        execucoes++;
//        int meio = (inicio + fim)/2;
//        if(arraySelectionSort[meio] == x) return meio;
//        if(arraySelectionSort[meio] < x) inicio = meio + 1;
//        else {
//            fim = meio - 1;
//        }
//    }
//    return -1;
//}

//int Conjunto::BuscarNum(int aux)
//{
//    this->execucoes=0;
//    QString resultado = "[";
//    for (int i = 0; i < tamanho; ++i) {
//        execucoes++;
//        if(aux == array[i])
//            return i;
//    }
//    execucoes++;
//    return -1;
//}

}
