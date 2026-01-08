# 🏗️ Estruturas de Dados Dinâmicas em C

Este repositório contém as implementações fundamentais desenvolvidas durante a disciplina de **Estrutura de Dados 1** no curso de Ciência da Computação do **IFSP**. 

O foco principal deste laboratório foi o domínio da **alocação dinâmica de memória** e a manipulação de **ponteiros para ponteiros**, garantindo eficiência e controle total sobre a estrutura dos dados.

---

## 🛠️ Conceitos Aplicados

Diferente de estruturas estáticas (vetores), estas implementações utilizam:
* **Gerenciamento de Memória**: Uso rigoroso de `malloc()` para criação de nós e `free()` para evitar *memory leaks*.
* **Encadeamento**: Uso de campos `next` dentro de `structs` para criar sequências lógicas na memória.
* **Ponteiros de Segunda Ordem**: Passagem de parâmetros por referência (`**`) para modificação direta dos endereços de início e fim nas funções.

---

## 📂 Estruturas Implementadas

### 1. Fila (Queue - FIFO)
Implementada no arquivo `Fila.c`. Segue o princípio *First-In, First-Out* (o primeiro que entra é o primeiro que sai).

* **Funções**: `enfileirar`, `desenfileirar`, `vazia` e `apresentar`.

### 2. Pilha (Stack - LIFO)
Implementada no arquivo `Pilha.c`. Segue o princípio *Last-In, First-Out* (o último que entra é o primeiro que sai).

* **Funções**: `push`, `pop`, `topo` e `vazia`.

### 3. Lista Encadeada (Linked List)
Implementada no arquivo `Lista.c`. Permite a inserção e remoção flexível de elementos em uma sequência lógica.


---

## 🚀 Como Executar

Para testar as implementações, você precisará de um compilador C (como o `gcc`).

1. **Clone o repositório:**
   ```bash
   git clone [https://github.com/feliipenevesnow/Estrutura-de-Dados-1.git](https://github.com/feliipenevesnow/Estrutura-de-Dados-1.git)
