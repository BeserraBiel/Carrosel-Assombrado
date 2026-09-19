# 🎡 O Carrossel Assombrado (Lista Circular em C)

Este repositório contém uma atividade acadêmica da disciplina de **Desenvolvimento em Linguagem C**, focada na implementação prática do conceito de **Listas Encadeadas Circulares**.

Para tornar o aprendizado mais lúdico, o sistema gerencia um "Carrossel Assombrado", onde os nós da lista são os espíritos (passageiros) ocupando os assentos do brinquedo. 👻

## 📋 Funcionalidades Implementadas

O projeto possui um menu interativo pelo terminal com as seguintes funções (operações clássicas de lista):

1. **Invocar Alma (Adicionar/Alocar):** Insere um novo nó dinamicamente. Se o carrossel estiver vazio, o nó aponta para si mesmo.
2. **Buscar Alma:** Percorre a roda procurando por um nome específico usando `strcmp()`.
3. **Contar Almas:** Conta o total de elementos interligados na roda.
4. **Banir Alma (Remover):** O desafio principal! Remove um nó tratando todos os 4 cenários críticos:
   - Lista vazia
   - Único elemento na lista (liberando a memória e zerando a lista)
   - Remoção do primeiro nó (ajustando o ponteiro final para fechar o ciclo corretamente)
   - Remoção de um elemento no meio/fim da lista.

## 🧠 Aprendizado em Destaque: A "Regra de Ouro" da Lista Circular

O principal aprendizado desta implementação foi como evitar o clássico bug de *loop infinito* ao percorrer uma lista que não possui um fim (`NULL`). 

A solução aplicada no código (para as funções de busca e contagem) foi o uso estruturado do laço `do...while`:

```c
Passageiro* atual = inicio;
do {
    // Lógica para o nó atual aqui...
    atual = atual->proximo;
} while (atual != inicio); // Apenas quebra o laço após dar a volta completa
```

Isso garante que o primeiro elemento sempre será lido e que a roda irá parar de girar exatamente quando o ponteiro alcançar o seu ponto de origem.

## 🛠️ Tecnologias Utilizadas
* **Linguagem C** 
* Estruturas de Dados (`struct`)
* Alocação Dinâmica de Memória (`malloc`, `free`, `sizeof`)
* Manipulação e rastreio de Ponteiros
* Tratamento de buffer de teclado (`scanf(" %[^\n]", nome)`)

## 🚀 Como testar na sua máquina

Para compilar e executar o projeto, você precisará de um compilador C (como o GCC) instalado.

1. Clone o repositório ou baixe o arquivo `carrossel.c`.
2. Abra o terminal na pasta do arquivo e rode:
   ```bash
   gcc carrossel.c -o carrossel
   ./carrossel
   ```
3. O menu interativo se abrirá no próprio terminal.

---
*Projeto desenvolvido como parte de um relatório acadêmico prático sobre ponteiros e estruturas dinâmicas.*
