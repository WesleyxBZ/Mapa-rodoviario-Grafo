#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

struct cidade{
    char nome[15];
    int grau; // Número de "vizinhos" da cidade
    struct caminho *vizinhos[10];// ponteiro que contém um vetor para até 10 cidades vizinhas
    int visitado;
};
typedef struct cidade Cidade;

struct caminho{
    struct cidade *vizinho; // aponta para vizinho
    int distancia; // distancia da cidade origem a cidade destino
};
typedef struct caminho Caminho;

#endif // STRUCT_H_INCLUDED
