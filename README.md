# Algoritmos e Estruturas de Dados II #

### INSTRUNÇÕES - PROJETO 02###
-----------------------

#### - Execução do Projeto ####

O arquivo de testes para o *Projeto 02* é o arquivo `GrafosApp.cpp`. Todos os algoritmos serão testados dentro deste arquivo, de modo que cada algoritmo será adicionado 
incrementalmente ao `GrafosApp.cpp` (o andamento dos incrementos poderá ser visto no item **2.2**).

Sendo assim, **o comando ` make ` deverá ser executado dentro da pasta ` Project02 `.**

Após a execução do comando `make`, o arquivo para execução será o `GrafosApp<.EXTENSÃO>`.

(Antes da execuçao, veja as informações abaixo).

#### - Visualização dos Grafos - Web Browser ####

*(A execução da aplicação [console] não é afetada sem esta configuração)*

O *Projeto 02* possui um método de visualização grafica desenvolvido com HTML5 e D3. Logo ao fim da execução da aplicação console, você terá a opção de escolher visualizar os 
grafos graficamente através do seu web browser. Para que seja possível a execução desse método, é necessário realizar uma pequena configuração:

* Abra o arquivo `Graph.hpp` em `Project02/Graph/` 
* Edite a linha abaixo, trocando `<CAMINHO>` pelo caminho completo em que o repositório foi clonado:

```
#!c++

// Caminho para o arquivo que será usado para exibir o grafo
#define GRAPHVIEW "<CAMINHO>/aedii/Project02/view/index.html"

```

As arestas dos grafos são salvos em arquivos .csv, mesmo após o fim da execução da aplicação esses dados permanecerão 
salvos até a próxima execução da aplicação. O arquivo para visualização (`index.html`) está contido dentro da pasta `Project02/view`.

### INFO. GERAIS ###
-----------------------

### 1. Repo ###

* Repósitorio para o projeto da disciplina "Algoritmo e Estruturas de Dados II" (AED II) do curso de BCC na UFRPE UAG.

* Professor: Rian Gabriel

### 2. Algoritmos/Estruturas

**2.1 Projeto 01 (1ª VA - Concluído)**

* Árvore AVL (Concluída)
* Árvore Rubro-Negra (RedBlack) (Concluida) (Remoção -> Algoritmo não necessário para a implementação)
* Heap (Concluída) (Heaps: MIN e MAX, escolha feita em tempo de execução)
+ Hash
    *  Encadeada (Concluída) (Inserção, busca e remoção)
    *  Endereçamento Aberto (Concluída)(Inserção e busca. Remoção -> Algoritmo não necessário para a implementação)
* Árvore B (Não implementado)

**2.2 Projeto 02 (2ª VA)**

* Dijkstra
* Prim
+ Kruskal 
	* Status: concluído.
* Floyd-Warshall
* Ford-Fulkerson
+ ***Adicionais***
    * Classes: Graph e Edge (necessárias para a implementação dos algoritmos)
    + Visualização dos grafos através do web browser.
         * Habilitado para: Graph/Edge, Algoritmos[Kruskal].

### 3. Proprietário ###

* Nome: José Kellison de A. Silva
* Email:  kellisonjk@gmail.com