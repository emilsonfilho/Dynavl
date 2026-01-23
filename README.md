# Dynavl - Conjuntos Dinâmicos com Árvores AVL 🌳

**Dynavl** é uma implementação robusta de conjuntos dinâmicos de inteiros utilizando **Árvores AVL** (Adelson-Velsky and Landis) em C++. 

O projeto oferece uma interface de linha de comando (CLI) para realizar operações de conjuntos (como união, interseção e diferença) com garantia de eficiência logarítmica, graças ao balanceamento automático da árvore.

Desenvolvido como parte da avaliação da disciplina de **Estrutura de Dados Avançada** na **Universidade Federal do Ceará (UFC) - Campus Quixadá**.

## 🚀 Funcionalidades

O sistema permite gerenciar múltiplos conjuntos simultaneamente através de comandos no terminal:

### Gerenciamento de Conjuntos
* `create`: Cria um novo conjunto (vazio ou com valores iniciais).
* `show`: Exibe os elementos de todos os conjuntos cadastrados.
* `list`: Lista a origem/detalhes dos conjuntos.
* `swap`: Troca o conteúdo de dois conjuntos.
* `clear`: Limpa todos os elementos de um conjunto.

### Operações de Conjunto (Set Operations)
* `union`: Cria um novo conjunto a partir da união de outros dois ($A \cup B$).
* `intersection`: Cria um novo conjunto com a interseção de outros dois ($A \cap B$).
* `difference`: Cria um novo conjunto com a diferença entre dois conjuntos ($A - B$).

### Manipulação e Consulta de Dados
* `insert`: Insere um número inteiro em um conjunto (mantendo o balanceamento AVL).
* `erase`: Remove um número específico do conjunto.
* `contains`: Verifica se um valor pertence ao conjunto.
* `minimum` / `maximum`: Retorna o menor/maior valor armazenado.
* `predecessor` / `successor`: Encontra o antecessor ou sucessor de um valor na ordem in-order.
* `size`: Exibe a cardinalidade (tamanho) do conjunto.
* `empty`: Verifica se o conjunto está vazio.

## 🛠️ Tecnologias e Conceitos

* **Linguagem:** C++
* **Estrutura de Dados:** Árvore AVL (Binary Search Tree auto-balanceável).
    * *Complexidade:* $O(\log n)$ para inserção, remoção e busca no pior caso.
* **Padrão de Projeto:** Command Pattern (para desacoplamento e extensibilidade dos comandos da CLI).
* **Build System:** CMake.

## 📦 Como Compilar e Rodar

### Pré-requisitos
* Compilador C++ compatível com C++17 ou superior.
* CMake (versão 3.10+ recomendada).

### Passo a passo

1. **Clone o repositório:**
   ```bash
   git clone [https://github.com/emilsonfilho/dynavl.git](https://github.com/emilsonfilho/dynavl.git)
   cd dynavl
   ```
2. **Gere os arquivos de build com o CMake**
   ```bash
    mkdir build
    cd build
    cmake ..
   ```
3. **Compile o projeto**
  ```bash
  make
  ```
4. **Execute**
  ```bash
  ./Dynavl
  ```

## 📚 Estrutura do Projeto

- `include/Set/`: Contém a definição da classe Set e lógica da Árvore AVL.
- `include/Commander/`: Implementação do padrão Command (Invoker, Interfaces).
- `src/`: Implementação dos arquivos fonte .cpp.
- `def/`: Definições globais e validadores de entrada.

**Autor**: Francisco Emilson Santos Souza Filho

**Disciplina**: Estrutura de Dados Avançada

Universidade Federal do Ceará (UFC)
