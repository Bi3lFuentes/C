#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaAR{
    char corLinha[20];
    int dest;
    struct listaAR* prox;
}Aresta;

typedef struct NoGrafo
{
    char nome[50];
    Aresta* listaADJ; 
} NoGrafo;

typedef struct GrafoLA
{
    NoGrafo** vertices;
    int tamanho;
}GrafoLA;

GrafoLA* criaGrafo(int tamanho){
    GrafoLA* grafo = (GrafoLA*)malloc(sizeof(GrafoLA));
    grafo->vertices = (NoGrafo**)malloc(sizeof(NoGrafo *) * tamanho);
    grafo->tamanho = tamanho;
    for(int i = 0; i < tamanho; i++){
        grafo->vertices[i] = NULL;
    }
    return grafo;
}

void imprimeGrafo(GrafoLA* head){
    for(int i = 0; i < head->tamanho; i++){
        if(head->vertices[i] != NULL){
            printf("(%s id: %d) ", head->vertices[i]->nome, i); 
            if(head->vertices[i]->listaADJ != NULL){
                Aresta* curr = head->vertices[i]->listaADJ;
                printf("Arestas de %d :", i);
                while(curr != NULL){
                    Aresta* temp = curr->prox;
                    printf("%d ", curr->dest);
                    curr = temp;
                }
            }
            printf("\n");
        }else{
            //printf("nulo");
        }
    }
    
}

void inserirGrafo(GrafoLA* head, char* nome){
    NoGrafo* novo = (NoGrafo*)malloc(sizeof(NoGrafo));
    for(int i = 0; i < head->tamanho; i++){
        if(head->vertices[i] == NULL){
            head->vertices[i] = novo;
            strcpy(head->vertices[i]->nome, nome);
            head->vertices[i]->listaADJ = NULL;
            break;
        }
    }
}

void deletaAresta(NoGrafo* no){
    Aresta* curr = no->listaADJ;
    while(curr != NULL){
        Aresta* temp = curr->prox;
        free(curr);
        curr = temp;
    }
}

Aresta * inserirAresta(Aresta* node, int dest, char* corLinha){
    if(node == NULL){
        Aresta* novo = (Aresta*)malloc(sizeof(Aresta));
        novo->dest = dest;
        strcpy(novo->corLinha, corLinha);
        novo->prox = NULL;
        return novo;
    }else{
        node->prox = inserirAresta(node->prox, dest, corLinha);
        return node;
    }
}

void adicionarConx(GrafoLA* head, int chave1, int chave2, char* corLinha){
    head->vertices[chave1]->listaADJ = inserirAresta(head->vertices[chave1]->listaADJ, chave2, corLinha);
}

void adicionarConxDupla(GrafoLA* head, int chave1, int chave2, char* corLinha){
    adicionarConx(head, chave1, chave2, corLinha);
    adicionarConx(head, chave2, chave1, corLinha);
}

void deletaGrafo(GrafoLA* head){
    for(int i = 0; i < head->tamanho; i++){
        if(head->vertices[i] != NULL){
            deletaAresta(head->vertices[i]);
            free(head->vertices[i]);
        }
    }
    free(head);
}

void setupEstacoes(GrafoLA* head){
    //linha amarela
    inserirGrafo(head, "Odivelas");
    inserirGrafo(head, "Senhor Roubado");
    inserirGrafo(head, "Ameixoeira");
    inserirGrafo(head, "Campo Grande");
    inserirGrafo(head, "Telheiras");
    adicionarConxDupla(head, 0, 1, "AMARELA");
    adicionarConxDupla(head, 1, 2, "AMARELA");
    adicionarConxDupla(head, 2, 3, "AMARELA");
    adicionarConxDupla(head, 3, 4, "AMARELA");

    //linha verde
    inserirGrafo(head, "Estrela");
    inserirGrafo(head, "Masques do Pombal");
    inserirGrafo(head, "Saldanha");
    inserirGrafo(head, "Campo Pequeno");
    inserirGrafo(head, "Entre Campos");
    inserirGrafo(head, "Cidade Universitaria");
    inserirGrafo(head, "Roma");
    inserirGrafo(head, "Almeda");
    inserirGrafo(head, "Intendente");
    inserirGrafo(head, "Rossio");
    inserirGrafo(head, "Baixa-Chiado");
    inserirGrafo(head, "Cais do Sondre");
    adicionarConxDupla(head, 5, 6, "VERDE");
    adicionarConxDupla(head, 6, 7, "VERDE");
    adicionarConxDupla(head, 7, 8, "VERDE");
    adicionarConxDupla(head, 8, 9, "VERDE");
    adicionarConxDupla(head, 9, 10, "VERDE");
    adicionarConxDupla(head, 10, 3, "VERDE");
    adicionarConxDupla(head, 3, 11, "VERDE");
    adicionarConxDupla(head, 11, 12, "VERDE");
    adicionarConxDupla(head, 12, 13, "VERDE");
    adicionarConxDupla(head, 13, 14, "VERDE");
    adicionarConxDupla(head, 14, 15, "VERDE");
    adicionarConxDupla(head, 15, 16, "VERDE");

    //linha vermelha
    inserirGrafo(head, "Aeroporto");
    inserirGrafo(head, "Encarnacao");
    inserirGrafo(head, "Oriente");
    inserirGrafo(head, "Olivais");
    inserirGrafo(head, "Olaias");
    inserirGrafo(head, "S. Sebastiao");
    adicionarConxDupla(head, 17, 18, "VERMELHA");
    adicionarConxDupla(head, 18, 19, "VERMELHA");
    adicionarConxDupla(head, 19, 20, "VERMELHA");
    adicionarConxDupla(head, 20, 21, "VERMELHA");
    adicionarConxDupla(head, 21, 12, "VERMELHA");
    adicionarConxDupla(head, 12, 7, "VERMELHA");
    adicionarConxDupla(head, 7, 22, "VERMELHA");

    //linha azul
    inserirGrafo(head, "Santa Apolonia");
    inserirGrafo(head, "Terreiro do Paco");
    inserirGrafo(head, "Restauradores");
    inserirGrafo(head, "Praca da Espanha");
    inserirGrafo(head, "Jardim Zoologico");
    inserirGrafo(head, "Colegio Militar/Luz");
    inserirGrafo(head, "Reboleira");
    adicionarConxDupla(head, 23, 24, "AZUL");
    adicionarConxDupla(head, 24, 15, "AZUL");
    adicionarConxDupla(head, 15, 25, "AZUL");
    adicionarConxDupla(head, 25, 6, "AZUL");
    adicionarConxDupla(head, 6, 22, "AZUL");
    adicionarConxDupla(head, 22, 26, "AZUL");
    adicionarConxDupla(head, 26, 27, "AZUL");
    adicionarConxDupla(head, 27, 28, "AZUL");
    adicionarConxDupla(head, 28, 29, "AZUL");
}

void printOptions(void){
    printf("1. Relatorio das estacoes. \n"); // V
    printf("2. Imprimir rota de uma linha. \n"); // V
    printf("3. Adicionar estacao. \n");// V
    printf("4. Fechar estacao permanentemente. \n"); // V
    printf("5. Fechar estacao temporariamente. \n"); // V
    printf("6. Adicionar linha entre estacoes. \n"); // V
    printf("7. Remover linha entre estacoes. \n"); // V
    printf("8. Editar nome de uma estacao. \n"); //V
    printf("9. Renomear uma linha. \n"); // V
    printf("10. Trajeto ate uma estacao. \n"); //V
    printf("11. Trajeto ate uma linha. \n"); //V
    printf("12. Reabrir estacao. \n"); // V
    printf("13. Estacao com maior quantidade de linhas. \n"); //V
    printf("14. Sair. \n"); //V
}

int seenColor(char* cor, Aresta* seen){
    if(seen == NULL)return 0;
    //printf("! %s %s !    ", cor, seen->corLinha);
    if(!strcmp(cor, seen->corLinha)){
        return 1;
    }else{
        return seenColor(cor, seen->prox);
    }
}

int seenInt(int val, Aresta* seen){
    if(seen == NULL)return 0;
    if(val == seen->dest){
        return 1;
    }else{
        return seenInt(val, seen->prox);
    }
}

Aresta* addToSeen(char* cor, Aresta* seen){
    if(seen == NULL){
        Aresta* novo = (Aresta*)malloc(sizeof(Aresta));
        strcpy(novo->corLinha, cor);
        novo->prox = NULL;
        return novo;
    }else{
        seen->prox = addToSeen(cor, seen->prox);
        return seen;
    }
}

Aresta* addToSeenInt(int val, Aresta* seen){
    if(seen == NULL){
        Aresta* novo = (Aresta*)malloc(sizeof(Aresta));
        novo->dest = val;
        novo->prox = NULL;
        return novo;
    }else{
        seen->prox = addToSeenInt(val, seen->prox);
        return seen;
    }
}

void deletaSeen(Aresta* seen){
    if(seen == NULL)return;
    deletaSeen(seen->prox);
    free(seen);
}

void mostraLinhas(GrafoLA* head){
    Aresta* seen = NULL;
    int count = 0;
    for(int i = 0; i < head->tamanho; i++){
        if(head->vertices[i] == NULL)break;
        Aresta* curr = head->vertices[i]->listaADJ;
        while(curr != NULL){
            if(!seenColor(curr->corLinha, seen)){
                printf("%d . %s \n", count, curr->corLinha);
                count++;
                seen = addToSeen(curr->corLinha, seen);
            }
            curr = curr->prox;
        }
    }
    deletaSeen(seen);
}

int buscaEstacaoEdge(GrafoLA* head, char* linha){
    int result = -1;
    for(int i = 0; i < head->tamanho; i++){
        if(head->vertices[i] != NULL){
            Aresta* curr = head->vertices[i]->listaADJ;
            if(!strcmp(linha, curr->corLinha) && curr->prox == NULL){
                result = i;
                break;
            }
        }
    }
    return result;
}

void imprimeLinha(GrafoLA* head, char* linha, int start){
    int i = start;
    NoGrafo* curr = head->vertices[i];
    Aresta* seen = NULL;
    while(curr != NULL){
        Aresta* currAdj = curr->listaADJ;
        printf("%s <-> ", curr->nome);
        seen = addToSeenInt(i, seen);
        while(currAdj != NULL){
            if(!strcmp(currAdj->corLinha, linha) && !seenInt(currAdj->dest, seen)){
                i = currAdj->dest;
                break;
            }
            currAdj = currAdj->prox;
        }
        if(currAdj == NULL){
            printf("Fim da linha. \n");
            curr = NULL;
        }else{
            curr = head->vertices[i];
        }
    }
    deletaSeen(seen);
    printf("\n");
}

void buscaRota(GrafoLA* head, char* linha){
    int start = buscaEstacaoEdge(head, linha);
    if(start == -1){
        printf("A linha selecionada nao existe ou nao possui uma estacao edge. \n");
    }else{
        imprimeLinha(head, linha, start);
    }
}

void rotaLinhaMenu(GrafoLA* head){
    char rota[20];
    mostraLinhas(head);
    fflush(stdin);
    printf("Insira o nome da linha que voce deseja buscar: ");
    fgets(rota, 19, stdin);
    fflush(stdin);
    rota[strcspn(rota, "\n")] = 0;
    buscaRota(head, rota);
}

void inserirEstacaoMenu(GrafoLA* head){
    char nome[50];
    printf("Insira o nome da estacao: ");
    fflush(stdin);
    fgets(nome, 49, stdin);
    nome[strcspn(nome, "\n")] = 0;
    inserirGrafo(head, nome);
}

void inserirLinhaMenu(GrafoLA* head){
    int id1, id2;
    char nome[20];

    printf("Insira o id da primeira estacao: ");
    scanf("%d", &id1);
    printf("Insira o id da segunda estacao: ");
    scanf("%d", &id2);
    printf("Insira o nome da linha: ");
    fflush(stdin);
    fgets(nome, 19, stdin);
    nome[strcspn(nome, "\n")] = 0;

    if(head->vertices[id1] == NULL || head->vertices[id1] == NULL){
        printf("ERRO! ID NAO ENCONTRADO! \n");
        return;
    }

    adicionarConxDupla(head, id1, id2, nome);
}

Aresta* deletaLinha(Aresta* linha, int id){
    if(linha == NULL)return NULL;
    if(linha->dest == id)return linha->prox;

    linha->prox = deletaLinha(linha->prox, id);
    return linha;
}

void removerLinhaMenu(GrafoLA* head){
    int id1, id2;

    printf("Insira o id da primeira estacao: ");
    scanf("%d", &id1);
    printf("Insira o id da segunda estacao: ");
    scanf("%d", &id2);

    if(head->vertices[id1] == NULL || head->vertices[id1] == NULL){
        printf("ERRO! ID NAO ENCONTRADO! \n");
        return;
    }

    head->vertices[id1]->listaADJ = deletaLinha(head->vertices[id1]->listaADJ, id2);
    head->vertices[id2]->listaADJ = deletaLinha(head->vertices[id2]->listaADJ, id1);
}

void editarNomeMenu(GrafoLA* head){
    int id;
    char nome[50];

    printf("Inserir o id da estacao: ");
    scanf("%d", &id);
    if(head->vertices[id] == NULL){
        printf(" ERRO ESTACAO NAO ENCONTRADA!. \n");
        return;
    }

    printf("Inserir o novo nome da estacao: ");
    fflush(stdin);
    fgets(nome, 49, stdin);
    nome[strcspn(nome, "\n")] = 0;

    strcpy(head->vertices[id]->nome, nome);
}

void renomearLinhaMenu(GrafoLA* head){
    char linha[20];
    char nome[20];

    mostraLinhas(head);
    printf("Digite a linha que deseja renomear: ");
    fflush(stdin);
    fgets(linha, 19, stdin);
    linha[strcspn(linha, "\n")] = 0;

    printf("Digite o novo nome: ");
    fflush(stdin);
    fgets(nome, 19, stdin);
    nome[strcspn(nome, "\n")] = 0;

    for(int i = 0; i < head->tamanho; i++){
        if(head->vertices[i] != NULL){
            Aresta* curr = head->vertices[i]->listaADJ;
            while(curr != NULL){
                if(!strcmp(curr->corLinha, linha)){
                    strcpy(curr->corLinha, nome);
                }
                curr = curr->prox;
            }
        }
    }
}

void arrumaLinha(GrafoLA* head, int origem, int id1, int id2, char* corLinha){
    if(id2 == -1){
        head->vertices[id1]->listaADJ = deletaLinha(head->vertices[id1]->listaADJ, origem);
    }else{
        head->vertices[id1]->listaADJ = deletaLinha(head->vertices[id1]->listaADJ, origem);
        head->vertices[id2]->listaADJ = deletaLinha(head->vertices[id2]->listaADJ, origem);
        adicionarConxDupla(head, id1, id2, corLinha);
    }
}

void fecharEstMenu(GrafoLA* head, int op){
    int id;

    printf("Insira o id da estacao que sera fechada temporariamente: ");
    scanf("%d", &id);
    if(head->vertices[id] == NULL){
        printf("Estacao nao existente! \n");
        return;
    }

    Aresta* adjs = head->vertices[id]->listaADJ;
    Aresta* seen = NULL;
    while(adjs != NULL){
        if(!seenColor(adjs->corLinha, seen)){
            seen = addToSeen(adjs->corLinha, seen);
            int id1, id2 = -1;
            Aresta* curr = adjs->prox;
            id1 = adjs->dest;
            while(curr != NULL){
                if(!strcmp(curr->corLinha, adjs->corLinha)){
                    id2 = curr->dest;
                    break;
                }
                curr = curr->prox;
            }
            arrumaLinha(head, id, id1, id2, adjs->corLinha);
        }
        adjs = adjs->prox;   
    }
    deletaSeen(seen);

    if(op == 0){
        deletaAresta(head->vertices[id]);
        free(head->vertices[id]);
        head->vertices[id] = NULL;
    }
}

void imprimeMetro(GrafoLA* head){
    for(int i = 0; i < head->tamanho; i++){
        if(head->vertices[i] != NULL){
            printf("(%s id: %d) ", head->vertices[i]->nome, i); 
            if(head->vertices[i]->listaADJ != NULL){
                Aresta* curr = head->vertices[i]->listaADJ;
                printf("Arestas de %d :", i);
                while(curr != NULL){
                    Aresta* temp = curr->prox;
                    printf("%d ", curr->dest);
                    curr = temp;
                }
                printf("Linhas desta estacao: ");
                Aresta* seen = NULL;
                curr = head->vertices[i]->listaADJ;
                while (curr != NULL){
                    if(!seenColor(curr->corLinha, seen)){
                        printf("%s | ", curr->corLinha);
                        seen = addToSeen(curr->corLinha, seen);
                    }
                    curr = curr->prox;
                }
                deletaSeen(seen);
            }
            printf("\n");
        }else{
            //printf("nulo");
        }
    }
}

Aresta* popSeen(Aresta* seen){
    if(seen == NULL){
        return NULL;
    }
    if(seen->prox == NULL){
        free(seen);
        return NULL;
    }
    seen->prox = popSeen(seen->prox);
    return seen;
}

void printPath(GrafoLA* head, Aresta* seen){
    Aresta* curr = seen;
    while(curr != NULL){
        printf("%s <-> ", head->vertices[curr->dest]->nome);
        curr = curr->prox;
    }
}

void printTrajetos(GrafoLA* head, int idAtual, int idDestino, Aresta* seen, Aresta* path){
    if(idAtual == idDestino){
        path = addToSeenInt(idAtual, path);
        printPath(head, path);
        path = popSeen(path);
        printf("\n");
        return;
    }
    Aresta* curr = head->vertices[idAtual]->listaADJ;
    seen = addToSeenInt(idAtual, seen);
    path = addToSeenInt(idAtual, path);
    while(curr != NULL){
        if(!seenInt(curr->dest, seen))printTrajetos(head, curr->dest, idDestino, seen, path);
        curr = curr->prox;
    }
    path = popSeen(path);
    seen = popSeen(seen);
}

void trajetoParaEst(GrafoLA* head){
    int idOrigem, idDestino;

    printf("Insira o id da estacao de origem: ");
    scanf("%d", &idOrigem);
    printf("Insira o id da estacao de destino: ");
    scanf("%d", &idDestino);

    Aresta* seen = NULL;
    Aresta* path = NULL;

    printTrajetos(head, idOrigem, idDestino, seen, path);
    deletaSeen(seen);
    deletaSeen(path);
}

int hasLinha(GrafoLA* head, int idAtual, char* corLinha){
    Aresta* curr = head->vertices[idAtual]->listaADJ;
    while(curr != NULL){
        if(!strcmp(curr->corLinha, corLinha)){
            return 1;
        }
        curr = curr->prox;
    }
    return 0;
}

void printTrajetosLin(GrafoLA* head, int idAtual, char* destino, Aresta* seen, Aresta* path){
    if(hasLinha(head, idAtual, destino)){
        path = addToSeenInt(idAtual, path);
        printPath(head, path);
        path = popSeen(path);
        printf("\n");
        return;
    }
    Aresta* curr = head->vertices[idAtual]->listaADJ;
    seen = addToSeenInt(idAtual, seen);
    path = addToSeenInt(idAtual, path);
    while(curr != NULL){
        if(!seenInt(curr->dest, seen))printTrajetosLin(head, curr->dest, destino, seen, path);
        curr = curr->prox;
    }
    path = popSeen(path);
    seen = popSeen(seen);
}

void trajetoParaLin(GrafoLA* head){
    int idOrigem;
    char linha[20];

    printf("Insira o id da estacao de origem: ");
    scanf("%d", &idOrigem);
    printf("Insira o nome da linha de destino: ");
    fflush(stdin);
    fgets(linha, 19, stdin);
    linha[strcspn(linha, "\n")] = 0;

    Aresta* seen = NULL;
    Aresta* path = NULL;

    printTrajetosLin(head, idOrigem, linha, seen, path);
    deletaSeen(seen);
    deletaSeen(path);
}

void reabreLinha(GrafoLA* head, int id, int id1, int id2, char* corLinha){
    if(id2 == -1){
        head->vertices[id1]->listaADJ = deletaLinha(head->vertices[id1]->listaADJ, id2);
        adicionarConx(head, id1, id, corLinha);
    }else{
        head->vertices[id1]->listaADJ = deletaLinha(head->vertices[id1]->listaADJ, id2);
        head->vertices[id2]->listaADJ = deletaLinha(head->vertices[id2]->listaADJ, id1);

        adicionarConx(head, id1, id, corLinha);
        adicionarConx(head, id2, id, corLinha);
    }
}
void reabrirEstMenu(GrafoLA* head){
    int id;

    printf("Insira o id da estacao que sera reaberta: ");
    scanf("%d", &id);
    if(head->vertices[id] == NULL){
        printf("Estacao nao existente! \n");
        return;
    }

    Aresta* adjs = head->vertices[id]->listaADJ;
    Aresta* seen = NULL;
    while(adjs != NULL){
        if(!seenColor(adjs->corLinha, seen)){
            seen = addToSeen(adjs->corLinha, seen);
            int id1, id2 = -1;
            Aresta* curr = adjs->prox;
            id1 = adjs->dest;
            while(curr != NULL){
                if(!strcmp(curr->corLinha, adjs->corLinha)){
                    id2 = curr->dest;
                    break;
                }
                curr = curr->prox;
            }
            reabreLinha(head, id, id1, id2, adjs->corLinha);
        }
        adjs = adjs->prox;   
    }
    deletaSeen(seen);
}

int contaLinhas(Aresta* lista){
    if(lista == NULL){
        return 0;
    }
    return 1 + contaLinhas(lista->prox);
}

void estacaoMaiorGrau(GrafoLA* head){
    int index = 0, size = 0;
    for(int i = 0; i < head->tamanho; i++){
        if(head->vertices[i] != NULL && contaLinhas(head->vertices[i]->listaADJ) > size){
            index = i;
            size = contaLinhas(head->vertices[i]->listaADJ);
        }
    }
    printf("Estacao com maior grau eh: %s \n", head->vertices[index]->nome);
}

void interface(GrafoLA* head){
    int option = 0;
    while(option != 14){
        printOptions();
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            imprimeMetro(head);
            break;
        case 2:
            rotaLinhaMenu(head);
            break;
        case 3:
            inserirEstacaoMenu(head);
            break;
        case 4:
            fecharEstMenu(head, 0); //PERMANENTE
            break;
        case 5:
            fecharEstMenu(head, 1);
            break;
        case 6:
            inserirLinhaMenu(head);
            break;
        case 7:
            removerLinhaMenu(head);
            break;
        case 8:
            editarNomeMenu(head);
            break;
        case 9:
            renomearLinhaMenu(head);
            break;
        case 10:
            trajetoParaEst(head);
            break;
        case 11:
            trajetoParaLin(head);
            break;
        case 12:
            reabrirEstMenu(head);
            break;
        case 13:
            estacaoMaiorGrau(head);
            break;
        case 14:
            printf("\nObrigado por usar o sistema de Metro de Lisboa!\n");
            break;
        default:
            printf("\nopcao invalida!\n\n");
            break;
        }
    }
    return;
}

int main(void){
    GrafoLA* metro = criaGrafo(60);
    setupEstacoes(metro);
    interface(metro);
    deletaGrafo(metro);
    return 0;
}
