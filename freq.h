#ifndef _FREQ_H_
#define _FREQ_H_

#define WORDLEN 30

#define NUM_LETTERS 26

	typedef struct Node Node;

	Node* newNode(char c);

	Node* insert(Node *n ,char letter);

	void incremental(Node* n);

	void freeTree(Node *root);

	void printTree(Node* root, char *str, int j);

	void printTreeR(Node* root, char *str, int j);	

#endif
