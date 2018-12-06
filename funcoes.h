int numCidades=0; // Número de cidades cadastradas

/* Cria nova cidade */
void criarCidade(Cidade *lista[], char nome[]){
    Cidade *novo = (Cidade*) malloc(sizeof(Cidade));
    strcpy(novo->nome, nome);
    novo->grau = 0;
    lista[numCidades] = novo;
    numCidades++;
}

/* Criar caminho */
Caminho *criarCaminho(Cidade *lista[], int destino, int distancia){
    Caminho *nova = (Caminho*)malloc(sizeof(Caminho));
    nova->vizinho = lista[destino];
    nova->distancia = distancia;
    return nova;
}

/* Verifica um determinado caminho destino com origem e retorna sua distancia ou retorna se o mesmo existe */
int calcDistancia(Cidade *lista[], int origem, int destino, int opc){
    for(int i=0; i<lista[origem]->grau; i++){
        if(strcmp(lista[origem]->vizinhos[i]->vizinho->nome, lista[destino]->nome) == 0){
            if(opc == 0) return 1;
            return lista[origem]->vizinhos[i]->distancia;
        }
    }
}

/* Liga caminhos entre duas cidades */
void ligarCaminhos(Cidade *lista[], int origem, int destino, int distancia){

    system("cls");

    lista[origem]->vizinhos[lista[origem]->grau] = criarCaminho(lista, destino, distancia);
    lista[origem]->grau++;

    lista[destino]->vizinhos[lista[destino]->grau] = criarCaminho(lista, origem, distancia);
    lista[destino]->grau++;
}

/* Inserção e ligação de cidades definidas no trabalho */
void insereDefault(Cidade *lista[]){
    criarCidade(lista, "Alegrete");
    criarCidade(lista, "Bagé");
    criarCidade(lista, "Cruz Alta");
    criarCidade(lista, "Passo Fundo");
    criarCidade(lista, "Pelotas");
    criarCidade(lista, "Porto Alegre");
    criarCidade(lista, "Santiago");
    criarCidade(lista, "Santa Maria");
    criarCidade(lista, "São Borja");
    criarCidade(lista, "São Gabriel");
}

void ligaDefault(Cidade *lista[]){
    ligarCaminhos(lista, 3, 5, 289);
    ligarCaminhos(lista, 5, 4, 261);
    ligarCaminhos(lista, 4, 1, 189);
    ligarCaminhos(lista, 1, 9, 268);
    ligarCaminhos(lista, 9, 0, 204);
    ligarCaminhos(lista, 0, 8, 315);
    ligarCaminhos(lista, 8, 6, 141);
    ligarCaminhos(lista, 6, 2, 242);
    ligarCaminhos(lista, 2, 3, 149);
    ligarCaminhos(lista, 2, 7, 134);
    ligarCaminhos(lista, 7, 6, 152);
    ligarCaminhos(lista, 7, 0, 258);
    ligarCaminhos(lista, 7, 9, 182);
    ligarCaminhos(lista, 7, 1, 239);
    ligarCaminhos(lista, 7, 5, 291);
    ligarCaminhos(lista, 5, 1, 377);
}

/* Imprime as cidades existentes */
void imprimirCidades(Cidade *lista[]){
    printf("\nID \t%-15s\t%-15s\n", "Nome", "Grau");
    for(int i=0; i<numCidades; i++){
        printf("%d\t%-15s\t%d\n", i, lista[i]->nome, lista[i]->grau);
    }
    printf("\n");
}

/* Imprime os caminhos de uma dada cidade */
void imprimirCidadesAdj(Cidade *lista[], int numCid){

    system("cls");
    printf("Cidades vizinhas de %s...\n", lista[numCid]->nome);

    printf("\nID\t%-20s\t%s\n", "Destino", "Distância(KM)");
    for(int i=0; i<lista[numCid]->grau; i++){
        printf("%i\t%-20s\t%d\n", i, lista[numCid]->vizinhos[i]->vizinho->nome, lista[numCid]->vizinhos[i]->distancia);
    }
    printf("\n");
}

/* Remove caminho de uma cidade e reordena seus caminhos */
void removerCaminho(Cidade *lista[], int cidOrigem, char nomeRemove[20]){

    int i, j;

    for(i=0; i<lista[cidOrigem]->grau; i++){
        if(strcmp(nomeRemove, lista[cidOrigem]->vizinhos[i]->vizinho->nome) == 0){
            j = i;
            while(j < lista[cidOrigem]->grau){
                lista[cidOrigem]->vizinhos[j] = lista[cidOrigem]->vizinhos[j+1];
                j++;
            }
            lista[cidOrigem]->grau--;
        }
    }
}

/* Dado um nome, procura o ID da cidade */
int buscaCidade(Cidade *lista[], char nome[20]){
    for(int i=0; i<numCidades; i++){
        if(strcmp(nome, lista[i]->nome) == 0){
            return i;
        }
    }
}

/* Chama função para remover caminhos entre duas cidades */
void caminhos(Cidade *lista[], int cidOrigem, int cidRemove){

    char nome[20], nome2[20];

    strcpy(nome, lista[cidOrigem]->nome);
    strcpy(nome2, lista[cidOrigem]->vizinhos[cidRemove]->vizinho->nome);

    removerCaminho(lista, cidOrigem, nome2);
    cidRemove = buscaCidade(lista, nome2);
    removerCaminho(lista, cidRemove, nome);

    system("cls");
    printf("Caminhos removidos com sucesso!\n");
}

/* Remove cidade e ordena a lista com as cidaeds */
void removerCidade(Cidade *lista[], int numCidade){

    int i;
    char nome[20];

    strcpy(nome, lista[numCidade]->nome);

    for(i=0; i<numCidades; i++){
        removerCaminho(lista, i, nome);
    }

    i=numCidade;

    while(i < numCidades){
        lista[i] = lista[i+1];
        i++;
    }

    free(lista[numCidades]);
    numCidades--;

    system("cls");
    printf("Cidade removida com sucesso!\n");
}

/* Altera nome de uma cidade */
void alterarNomeCid(Cidade *lista[], int numCid){
    char nome[20];
    printf("Digite o novo nome: ");
    fflush(stdin);
    gets(nome);
    strcpy(lista[numCid]->nome, nome);
}

/* Altera a distância entre duas cidades (altera a distância das duas cidades) */
void alterarDistancia(Cidade *lista[], int numCid){
    int numCid2, distancia;
    char nome[20], nome2[20];

    printf("\nDigite o numero da cidade destino que deseja alterar a distância: ");
    scanf("%d", &numCid2);
    printf("\nDigite a nova distância: ");
    scanf("%d", &distancia);

    lista[numCid]->vizinhos[numCid2]->distancia = distancia; // Altera a distância da cidade origem à cidade destino

    strcpy(nome, lista[numCid]->nome); // Copia para 'nome', o nome da cidade origem
    strcpy(nome2, lista[numCid]->vizinhos[numCid2]->vizinho->nome); // Copia para 'nome2', o nome da cidade destino

    numCid2 = buscaCidade(lista, nome2); // Obtem o 'ID' da cidade destino

    for(int i=0; i<lista[numCid2]->grau; i++){ // For para percorrer os caminhos da cidade destino
        if(strcmp(nome, lista[numCid2]->vizinhos[i]->vizinho->nome) == 0){ // Compara o nome da cidade 'i' com o nome da cidade origem
            lista[numCid2]->vizinhos[i]->distancia = distancia; // Se achar a cidade origem, altera a distância da destino a origem
        }
    }
}

int vizAnt=0, totalDistancia=0, viz=0;

/* Procura rota de origem a destino */
int procurarRota(Cidade *lista[], int atual, int destino){

    printf("%s[%dKm]", lista[atual]->nome, calcDistancia(lista, atual, vizAnt, 1));
    viz = 0;

	if(strcmp(lista[destino]->nome, lista[atual]->nome) == 0){ // Compara se o  nome da cidade 'atual' == nome da cidade 'destino'
        totalDistancia += calcDistancia(lista, vizAnt, destino, 1);
        return 1;
	} else if((lista[atual]->visitado == 0) && (strcmp(lista[destino]->nome, lista[atual]->nome) != 0)) { // Compara se cidade atual != destino e se != visitada
        printf(" -> ");
        lista[atual]->visitado = 1; // Cidade atual vira visitada
        totalDistancia += calcDistancia(lista, vizAnt, atual, 1); // Soma a distância da atual a anterior
        if(lista[atual]->vizinhos[viz]->vizinho->visitado == 1) viz++;
        vizAnt = atual;
        atual = buscaCidade(lista, lista[atual]->vizinhos[viz]->vizinho->nome); // 'atual' recebe a primeira cidade vizinha que ela aponta
        procurarRota(lista, atual, destino);
	}
}

/* Procura se a cidade destino está no vetor da cidade origem */
int procurarRotaViz(Cidade *lista[], int origem, int destino){
    for(int i=0; i < lista[origem]->grau; i++){
		if(strcmp(lista[origem]->vizinhos[i]->vizinho->nome , lista[destino]->nome) == 0){
            return 1;
		}
	}
	return 0;
}

/* Chama função recursiva para buscar rota a rota destino */
void rota(Cidade *lista[], int origem, int destino){

    int enc=0;
    totalDistancia=0;

	for(int i=0; i < numCidades; i++){ // Definida todas as cidades como não vizitadas
		lista[i]->visitado = 0;
	}

    printf("Rota de %s a %s...\n\n%s -> ", lista[origem]->nome, lista[destino]->nome, lista[origem]->nome);

    if(procurarRotaViz(lista, origem, destino)== 0){
        lista[origem]->visitado = 1; // Cidade origem vira visitada
        vizAnt = origem; // 'vizAnt' recebe a cidade origem
        origem = buscaCidade(lista, lista[origem]->vizinhos[0]->vizinho->nome); // Origem recebe o primeiro vizinho que a cidade 'origem' tem no seu vetor 'vizinhos[]'

        if(procurarRota(lista, origem, destino) == 1){ // Chama função procurar rota e recebe valor de retorno
           printf("\nDistância total: %dKm\n\n", totalDistancia);
           system("pause");
           system("cls");
        }else{
            system("cls");
            printf("Erro!\n");
        }
    }else{
        totalDistancia = calcDistancia(lista, origem, destino, 1);
        printf("%s[%dKm]", lista[destino]->nome, totalDistancia);
        printf("\nDistância total: %dKm\n\n", totalDistancia);
        system("pause");
        system("cls");
    }


}

/* Dado um ID verifica se aquele ID existe na lista */
int verfExistCid(int nroCidade){

    if(nroCidade >= 0 && nroCidade < numCidades){
        return 1;
    }else{
        system("cls");
        return printf("Erro: Cidade não encontrada!\n");
    }
}

void sair(Cidade *lista[]){

    for(int i=0; i<numCidades; i++){
        free(lista[i]);
    }
}
