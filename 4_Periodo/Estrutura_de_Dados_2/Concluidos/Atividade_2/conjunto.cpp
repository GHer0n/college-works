#include "conjunto.h"

namespace gft {

Conjunto::Conjunto(int tamanho)
{
    if(tamanho < 0) throw QString("valor do tamanho do vetor tem de ser maior que 0");
    try {
        array = new int [tamanho];
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
    }

}

Conjunto::~Conjunto()
{
    delete array;
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

int Conjunto::BuscarNum(int aux) const
{
    QString resultado = "[";
    for (int i = 0; i < tamanho; ++i) {
        if(aux == array[i])
            return i;
    }
    throw QString ("O numero desejado nao existe");
}

}
