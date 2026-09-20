#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura do nosso nó (assento no carrossel)
typedef struct Passageiro {
  char nome[50];
  struct Passageiro *proximo;
} Passageiro;

// --- Protótipos das Funções ---
Passageiro *invocar_passageiro(Passageiro *inicio, char *nome);
Passageiro *buscar_passageiro(Passageiro *inicio, char *nome);
int contar_passageiros(Passageiro *inicio);
Passageiro *banir_passageiro(Passageiro *inicio, char *nome);
void observar_carrossel(Passageiro *inicio);

// 1 e 5. Função para alocar memória e adicionar um novo espírito ao carrossel
Passageiro *invocar_passageiro(Passageiro *inicio, char *nome) {
  // Passo A: Alocação dinâmica de memória para o novo nó
  Passageiro *novo_espirito = (Passageiro *)malloc(sizeof(Passageiro));

  // Verificando se a memória foi alocada corretamente
  if (novo_espirito == NULL) {
    printf("Erro das trevas: Sem memoria para mais assombracoes!\n");
    return inicio;
  }

  // Copiando o nome para o nosso novo nó
  strcpy(novo_espirito->nome, nome);

  // Passo B: E se o carrossel estiver vazio?
  if (inicio == NULL) {
    // O novo espírito é o primeiro!
    // A regra de ouro da lista circular: se só tem um, ele aponta para ele
    // mesmo.
    novo_espirito->proximo = novo_espirito;
    printf("A alma de %s ligou o carrossel!\n", nome);
    return novo_espirito; // Ele agora é o novo início
  }

  // Passo C: O carrossel já tem gente girando.
  // Precisamos achar o ÚLTIMO passageiro para colocar o novo depois dele.
  Passageiro *atual = inicio;

  // Como achamos o último em uma lista circular?
  // É aquele cujo ponteiro "proximo" aponta de volta para o "inicio".
  while (atual->proximo != inicio) {
    atual = atual->proximo;
  }

  // Agora a variável "atual" é o último passageiro. Vamos fazer a conexão:
  atual->proximo =
      novo_espirito; // O antigo último agora aponta para o novo passageiro
  novo_espirito->proximo =
      inicio; // O novo passageiro aponta para o início (fechando o círculo!)

  printf("A alma de %s subiu no carrossel!\n", nome);
  return inicio; // O início da roda continua sendo o mesmo
}

// 2. Função para procurar se uma alma específica está rodando no carrossel
Passageiro *buscar_passageiro(Passageiro *inicio, char *nome) {
  if (inicio == NULL) {
    printf("Busca: O carrossel esta vazio. Nem um fantasma sequer...\n");
    return NULL;
  }

  Passageiro *atual = inicio;

  // A regra de ouro para percorrer lista circular:
  // Usamos um loop do...while para garantir que vamos processar o primeiro
  // elemento, e paramos quando o "atual" der a volta e chegar no "inicio"
  // novamente.
  do {
    // A função strcmp compara duas strings (retorna 0 se forem iguais)
    if (strcmp(atual->nome, nome) == 0) {
      printf("Busca: Encontramos! A alma de %s esta rodando no carrossel.\n",
             nome);
      return atual; // Achou! Retorna o ponteiro para a assombração
    }
    atual = atual->proximo; // Pula para o próximo cavalinho
  } while (atual != inicio);

  // Se o loop terminou, demos a volta completa e não encontramos.
  printf("Busca: A alma de %s nao esta neste carrossel.\n", nome);
  return NULL;
}

// 3. Função para contar quantas assombrações estão no brinquedo
int contar_passageiros(Passageiro *inicio) {
  if (inicio == NULL) {
    return 0; // Carrossel vazio
  }

  int contador = 0;
  Passageiro *atual = inicio;

  do {
    contador++;
    atual = atual->proximo;
  } while (atual != inicio); // Para de contar quando der a volta completa

  return contador;
}

// 4. Função para remover (banir) um espírito específico do carrossel
Passageiro *banir_passageiro(Passageiro *inicio, char *nome) {
  // Cenário 1: O carrossel está vazio
  if (inicio == NULL) {
    printf("Banimento: Nao ha ninguem para banir. O carrossel esta vazio!\n");
    return NULL;
  }

  Passageiro *atual = inicio;
  Passageiro *anterior = NULL;

  // Precisamos saber quem é o último passageiro para lidar com o primeiro nó
  Passageiro *ultimo = inicio;
  while (ultimo->proximo != inicio) {
    ultimo = ultimo->proximo;
  }

  // Vamos girar o carrossel procurando o fantasma
  do {
    if (strcmp(atual->nome, nome) == 0) {
      // ACHAMOS! Agora precisamos removê-lo.

      // Cenário 2: É o ÚNICO passageiro no carrossel
      if (atual == inicio && atual->proximo == inicio) {
        free(atual); // Libera a memória
        printf("Banimento: A alma de %s foi banida. O carrossel agora esta "
               "vazio.\n",
               nome);
        return NULL; // A roda ficou vazia
      }

      // Cenário 3: É o PRIMEIRO passageiro (mas tem outras pessoas na roda)
      if (atual == inicio) {
        inicio = atual->proximo;  // O segundo passa a ser o novo primeiro
        ultimo->proximo = inicio; // O último agora aponta para o novo primeiro,
                                  // fechando o círculo!
        free(atual);
        printf(
            "Banimento: A primeira alma (%s) foi banida. A roda continua...\n",
            nome);
        return inicio;
      }

      // Cenário 4: É um passageiro no MEIO ou no FIM do carrossel
      // A mágica acontece aqui: o passageiro 'anterior' ignora o 'atual'
      // e liga sua corrente direto no 'proximo' do 'atual'.
      anterior->proximo = atual->proximo;
      free(atual);
      printf("Banimento: A alma de %s foi banida com sucesso!\n", nome);
      return inicio;
    }

    // Não era esse fantasma, vamos andar com os dois ponteiros
    anterior = atual;
    atual = atual->proximo;

  } while (atual != inicio); // Dá a volta inteira

  // Se saiu do loop, significa que deu a volta e não achou
  printf("Banimento: A alma de %s nao foi encontrada para ser banida.\n", nome);
  return inicio;
}

// Extra: Função para visualizar o carrossel (ajuda muito a testar se tudo está
// ligado certo)
void observar_carrossel(Passageiro *inicio) {
  if (inicio == NULL) {
    printf("\n   [ O carrossel esta completamente vazio e silencioso... ]\n");
    return;
  }

  Passageiro *atual = inicio;
  printf("\n--- Espiritos rodando no Carrossel ---\n");
  do {
    printf(" -> [ %s ] ", atual->nome);
    atual = atual->proximo;
  } while (atual != inicio);
  printf("-> (Volta ao inicio)\n--------------------------------------\n");
}

// 5. Menu interativo no main para testar tudo
int main() {
  Passageiro *carrossel = NULL; // Todo carrossel começa vazio
  int opcao;
  char nome[50];

  do {
    printf("\n=== O CARROSSEL ASSOMBRADO ===\n");
    printf("1. Invocar alma (Adicionar)\n");
    printf("2. Buscar alma\n");
    printf("3. Contar almas\n");
    printf("4. Banir alma (Remover)\n");
    printf("5. Observar carrossel\n");
    printf("0. Fechar o parque (Sair)\n");
    printf("Escolha sua acao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Digite o nome da alma para invocar: ");
      scanf(" %[^\n]",
            nome); // O espaço antes do % limpa o buffer, o [^\n] lê até o enter
      carrossel = invocar_passageiro(carrossel, nome);
      break;
    case 2:
      printf("Digite o nome da alma que procura: ");
      scanf(" %[^\n]", nome);
      buscar_passageiro(carrossel, nome);
      break;
    case 3:
      printf("Total de almas girando agora: %d\n",
             contar_passageiros(carrossel));
      break;
    case 4:
      printf("Digite o nome da alma para banir: ");
      scanf(" %[^\n]", nome);
      carrossel = banir_passageiro(carrossel, nome);
      break;
    case 5:
      observar_carrossel(carrossel);
      break;
    case 0:
      printf("O carrossel parou. As almas descansam em paz. Encerrando...\n");
      // Em um sistema perfeitamente limpo, faríamos um loop com 'free'
      // em todos os nós restantes aqui antes de fechar o programa.
      break;
    default:
      printf("Opcao invalida. As almas estao confusas.\n");
    }
  } while (opcao != 0);

  return 0;
}
