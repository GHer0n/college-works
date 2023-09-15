#include "conjunto.h"

namespace gft {

Conjunto::Conjunto(int tamanho)
{
    if(tamanho < 0) throw QString("valor do tamanho do vetor tem de ser maior que 0");
    try {
        array = new int [tamanho];
        this->tamanho = tamanho;
        unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
        std::srand(seed);
        // Gera números aleatórios e os insere no vetor
        for (int i = 0; i < tamanho; ++i) {
            int randomNumber = std::rand() %1000 + 1;
            array[i] = randomNumber;
            //arraySelectionSort[i] = randomNumber;
        }
    } catch (std::bad_alloc &erro) {
        throw QString ("ERRo ao gerar numero!");
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

}
