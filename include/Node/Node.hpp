#ifndef NODE_HPP
#define NODE_HPP

/**
 * @class Node
 * 
 * Esta estrutura representa um nó qualquer da árvore
 * */
struct Node {
	int key;
	int height;
	Node* left;
	Node* right;

	/**
	 * @brief Construtor do nó
	 * 
	 * Cria um nó com uma valor `key` e uma altura especificada, se necessário
	 * 
	 * @param key O valor do nó
	 * @param height A altura do nó
	 * */
	Node(int key, int height = 1);
};

#endif