#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

struct cidade{
    char nome[15];
    int grau; // N�mero de "vizinhos" da cidade
    struct caminho *vizinhos[10];// ponteiro que cont�m um vetor para at� 10 cidades vizinhas
    int visitado;
};
typedef struct cidade Cidade;

struct caminho{
    struct cidade *vizinho; // aponta para vizinho
    int distancia; // distancia da cidade origem a cidade destino
};
typedef struct caminho Caminho;

#endif // STRUCT_H_INCLUDED
