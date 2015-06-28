# Algoritmos e Estruturas de Dados II #

### INSTRUNÇÕES - PROJETO 02###
-----------------------

#### - Execução do Projeto ####

*(UPDATE NA EXECUÇÃO DOS TESTES)*

Houve uma pequena mudança em relação ao planejado anteriormente, onde os algoritmo seriam testados em um único "Main" (no caso o GrafosApp.exe)
agora cada um posuirá o seu próprio "Main" para testes dentro de seus diretórios, sendo nomeados como "AppNome_do_Algoritmo.exe".

#### - Visualização dos Grafos - Web Browser ####

As arestas dos grafos são salvos em arquivos .csv, mesmo após o fim da execução da aplicação esses dados permanecerão 
salvos até a próxima execução da aplicação. O arquivo para visualização (`index.html`) está contido dentro da pasta `Project02/view`.

*(UPDATE TEMPORÁRIO) Não há a necessidade de realizar a configuração citada neta parte do README, pois a opção para a visualização 
direta a partir do console está desabilitada.
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

### INFO. GERAIS ###
-----------------------

### 1. Repo ###

* Repósitorio para o projeto da disciplina "Algoritmo e Estruturas de Dados II" (AED II) do curso de BCC na UFRPE UAG.

* Professor: Rian Gabriel Pinheiro

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
	* Status: concluído.
* Prim
	* Status: concluído.
+ Kruskal 
	* Status: concluído.
* Floyd-Warshall
	* Status: concluído.
* Ford-Fulkerson
+ ***Adicionais***
    * Classes: Graph e Edge (necessárias para a implementação dos algoritmos)
    + Visualização dos grafos através do web browser.
         * Habilitado para: Graph/Edge, Algoritmos[Kruskal, Prim].

### 3. Proprietário ###

* Nome: José Kellison de A. Silva
* Email:  kellisonjk@gmail.com