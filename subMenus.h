void subMenuCriarCid(Cidade *lista[]){
    system("cls");
    char nome[20];

    printf("Digite o nome da cidade: ");
    fflush(stdin);
    gets(nome);
    criarCidade(lista, nome);

    system("cls");
    printf("Cidade criada!\n");
}

void subMenuImprimirCidAdj(Cidade *lista[]){
    system("cls");
    int numCid;

    imprimirCidades(lista);

    printf("\nDigite o número da cidade para saber suas vizinhas: ");
    scanf("%d", &numCid);

    if(verfExistCid(numCid) == 1){
        imprimirCidadesAdj(lista, numCid);
        system("pause");
        system("cls");
    }
}

void subMenuRemoverCidCaminho(Cidade *lista[]){
    system("cls");
    int numCid, numCid2, opc;

    printf("<1> - Remover cidade\n");
    printf("<2> - Remover caminho\n\n:");
    scanf("%d", &opc);

    system("cls");
    switch(opc){
        case 1:
            imprimirCidades(lista);
            printf("\nDigite o número da cidade que deseja remover: ");
            scanf("%d", &numCid);
            if(verfExistCid(numCid) == 1){
                removerCidade(lista, numCid);
            }
            break;
        case 2:
            imprimirCidades(lista);
            printf("\nDigite o número da cidade para visualizar seus caminhos: ");
            scanf("%d", &numCid);
            if(verfExistCid(numCid) == 1){
                imprimirCidadesAdj(lista, numCid);
                printf("\nDigite o número do caminho que deseja excluir: ");
                scanf("%d", &numCid2);
                caminhos(lista, numCid, numCid2);
            }
            break;
        default:
            system("cls");
            printf("Erro: Opção inválida!\n");
            break;
    }
}

void subMenuAltDados(Cidade *lista[]){
    system("cls");
    imprimirCidades(lista);

    int numCid, opc;

    printf("Digite o número da cidade que deseja alterar os dados: ");
    scanf("%d", &numCid);

    if(verfExistCid(numCid) == 1){
        system("cls");

        printf("\tAlterar dados de %s...\n", lista[numCid]->nome);
        printf("\n<1> - Alterar nome\n");
        printf("<2> - Alterar distâncias entre duas cidade\n");
        printf("<3> - Alterar tudo\n\n:");
        scanf("%d", &opc);

        system("cls");

        switch(opc){
            case 1:
                alterarNomeCid(lista, numCid);
                break;
            case 2:
                imprimirCidadesAdj(lista, numCid);
                alterarDistancia(lista, numCid);
                break;
            case 3:
                alterarNomeCid(lista, numCid);
                imprimirCidadesAdj(lista, numCid);
                alterarDistancia(lista, numCid);
                break;
        }

        system("cls");
        printf("Dados alterados!\n");
    }
}

void subMenuInserirLigacaoCid(Cidade *lista[]){
    system("cls");
    int origem, destino, dist;

    imprimirCidades(lista);

    printf("Digite o número da cidade de origem: ");
    scanf("%d", &origem);

    if(verfExistCid(origem) == 1){
        printf("\nDigite o número da cidade de destino: ");
        scanf("%d", &destino);
        if(verfExistCid(destino) == 1 && strcmp(lista[origem]->nome, lista[destino]->nome) != 0){
            if(calcDistancia(lista, origem, destino, 0) != 1){
                printf("\nDigite a distancia: ");
                scanf("%d", &dist);
                ligarCaminhos(lista, origem, destino, dist);
                printf("Caminho inserido com sucesso!\n");
            }else{
                system("cls");
                printf("Erro: Caminho já existe!\n");
            }
        }else{
            system("cls");
            printf("Erro: Cidade não existe ou não se pode ligar a mesma cidade!\n");
        }
    }
}

void subMenuVerRotas(Cidade *lista[]){
    system("cls");
    int origem, destino;

    imprimirCidades(lista);

    printf("Digite o número da cidade de origem: ");
    scanf("%d", &origem);

    if(verfExistCid(origem) == 1){
        printf("\nDigite o número da cidade de destino: ");
        scanf("%d", &destino);
        if(verfExistCid(destino) == 1 && strcmp(lista[origem]->nome, lista[destino]->nome) != 0){
            system("cls");
            rota(lista, origem, destino);
        }else{
            system("cls");
            printf("Erro: Cidade destino não existe ou não se pode ver rota para a mesma cidade!\n");
        }
    }
}
