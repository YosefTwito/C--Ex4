#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "freq.h"

#define NUM_LETTERS 26

typedef struct Node{
	char letter;
	long unsigned int count;
	struct Node* children[NUM_LETTERS];
	char isDefine[26];
	}Node;


Node* newNode(char c){
	int i;
	Node *n = (Node*)malloc(sizeof(Node));
	n->count=0;
	n->letter=c; 
	for (i=0; i<26; i++)	
		n->isDefine[i] = 0;
	return n;
}

Node* insert(Node *node, char letter){
	if(node->isDefine[letter-'a'] == 0)
	{
			Node *newN = newNode(letter);
			node->isDefine[letter-'a'] = 1;
			node->children[letter-'a'] = newN;
			return newN;
	}
	return (node->children[letter-'a']);
}

void incremental(Node* n){
	n->count++;
}

int noChilds(Node* n){
	int i;
	for (i=0; i<NUM_LETTERS; i++){
		if (n->isDefine[i]==1) { return 0; }
	}
	return 1;
}

void freeTree(Node* root){
	int i;
	if (root==NULL)
		return;
	
	if (noChilds(root)){ 
		free(root);
		return;
	}
	else
	{
	for (i=0; i<NUM_LETTERS; i++){
		if (root->isDefine[i]==1){
			freeTree(root->children[i]);

		}
		}
	free(root);
	}
}

void printTree(Node* root, char *str, int j){
	if (noChilds(root)){
		str[j] = '\0';
		printf("%s\t%ld\n", str, root->count);
		return;
	}
	if (root->count > 0){
		str[j] = '\0';
		printf("%s\t%ld\n", str, root->count);
	}
	int i;
	for (i=0; i<NUM_LETTERS; i++){
		if (root->isDefine[i]==1){
			str[j] = root->children[i]->letter;
			printTree(root->children[i], str, j+1);
		}
	}
}

void printTreeR(Node* root, char *str, int j){
	if (noChilds(root)){
		str[j] = '\0';
		printf("%s\t%ld\n", str, root->count);
		return;
	}
	if (root->count > 0){
		str[j] = '\0';
		printf("%s\t%ld\n", str, root->count);
	}
	int i;
	for (i=NUM_LETTERS-1; i>=0; i--){
		if (root->isDefine[i]==1){
			str[j] = root->children[i]->letter;
			printTree(root->children[i], str, j+1);
		}
	}
}
    


