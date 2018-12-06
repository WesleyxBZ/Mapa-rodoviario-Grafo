#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "struct.h"
#include "subMenus.h"
#include "funcoes.h"

#define MAX_CIDADES 20

int main(){

    setlocale(LC_ALL,"Portuguese");

    int opc, numCid, numCid2;
    Cidade *lista[MAX_CIDADES];

    insereDefault(lista); // Insere as cidades
    ligaDefault(lista);   // definidas e faz as ligações

    do{
        printf("\n\t==================\n");
        printf("\t| Menu Principal |\n");
        printf("\t==================\n\n");

        printf("<1> - Inserir nova cidade\n");
        printf("<2> - Visualizar cidades vizinhas\n");
        printf("<3> - Remover cidade ou caminho\n");
        printf("<4> - Alterar dados de cidade\n");
        printf("<5> - Visualizar todas as cidades\n");
        printf("<6> - Inserir ligação entre cidades\n");
        printf("<7> - Visualizar rotas entre duas cidades\n\n");
        printf("<0> - Sair do programa\n\n:");
        scanf("%d", &opc);

        switch(opc){
            case 1:
                subMenuCriarCid(lista);
                break;
            case 2:
                subMenuImprimirCidAdj(lista);
                break;
            case 3:
                subMenuRemoverCidCaminho(lista);
                break;
            case 4:
                subMenuAltDados(lista);
                break;
            case 5:
                system("cls");
                imprimirCidades(lista);
                system("pause");
                system("cls");
                break;
            case 6:
                subMenuInserirLigacaoCid(lista);
                break;
            case 7:
                subMenuVerRotas(lista);
                break;
            default:
                system("cls");
                printf("Erro: Opção inválida!\n");
                break;
        }

    }while(opc != 0);

    sair(lista);
    system("cls");
    return 0;
}
