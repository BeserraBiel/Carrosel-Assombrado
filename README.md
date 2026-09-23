<div align="center">
  
# 🎡 O Carrossel Assombrado 
**Estrutura de Dados: Lista Encadeada Circular em C**

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Estrutura de Dados](https://img.shields.io/badge/Estrutura%20de%20Dados-Listas-8A2BE2?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Conclu%C3%ADdo-success?style=for-the-badge)

</div>

<br>

## 📜 Sobre o Projeto

Este repositório contém uma atividade acadêmica da disciplina de **Desenvolvimento em Linguagem C**, focada na implementação prática e lúdica do conceito de **Listas Encadeadas Circulares**.

Para tornar o aprendizado mais divertido, o sistema gerencia um *"Carrossel Assombrado"*, onde os nós da lista são os **espíritos (passageiros)** ocupando os assentos do brinquedo giratório. 👻🎠

---

## ✨ Funcionalidades Implementadas

O projeto possui um menu interativo rodando direto no terminal com as seguintes funções (operações clássicas de lista circular):

| Opção | Ação | Descrição Técnica |
| :---: | :--- | :--- |
| **1** | 🟢 **Invocar Alma** | **Adicionar/Alocar:** Insere um novo nó dinamicamente. Se o carrossel estiver vazio, o nó aponta para si mesmo. |
| **2** | 🔍 **Buscar Alma** | **Busca:** Percorre a roda procurando por um nome específico usando `strcmp()`. |
| **3** | 📊 **Contar Almas** | **Contagem:** Conta o total de nós interligados no anel. |
| **4** | 🔴 **Banir Alma** | **Remoção:** Remove um nó tratando todos os 4 cenários críticos (vazia, único, primeiro nó, meio/fim). |
| **5** | 👁️ **Observar** | **Impressão:** Exibe visualmente as almas girando e a interligação dos ponteiros. |

---

## 🧠 A "Regra de Ouro" da Lista Circular

O principal aprendizado desta implementação foi como evitar o clássico bug de *loop infinito* ao percorrer uma lista que não possui um fim (`NULL`). 

A solução aplicada no código (para as funções de busca e contagem) foi o uso estruturado do laço `do...while`:

```c
Passageiro* atual = inicio;

// Apenas quebra o laço após dar a volta completa!
do {
    // ⚙️ Lógica para o nó atual aqui...
    atual = atual->proximo; 
} while (atual != inicio); 
```

Isso garante que o **primeiro elemento sempre será lido** e que a roda irá parar de girar exatamente quando o ponteiro alcançar o seu ponto de origem.

---

## 🛠️ Tecnologias e Conceitos

* **Linguagem C** 
* **Estruturas de Dados:** `struct`
* **Alocação Dinâmica de Memória:** `malloc`, `free`, `sizeof`
* **Ponteiros:** Manipulação e rastreio de nós
* **I/O Seguro:** Tratamento de buffer de teclado (`scanf(" %[^\n]", nome)`)

---

## 🚀 Como testar na sua máquina

Para compilar e executar o projeto, você precisará de um compilador C (como o **GCC**) instalado em sua máquina.

**1. Clone o repositório ou baixe o arquivo:**
```bash
git clone https://github.com/seu-usuario/carrossel-assombrado.git
```
*(Ou simplesmente baixe o `carrossel.c`)*

**2. Compile o código:**
```bash
gcc carrossel.c -o carrossel
```

**3. Execute o programa:**
```bash
# No Linux ou macOS
./carrossel

# No Windows
carrossel.exe
```

<br>

<div align="center">
  <i>Projeto desenvolvido como parte de um relatório acadêmico prático sobre ponteiros e estruturas dinâmicas.</i>
</div>
