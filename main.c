#include <stdio.h> 
#include <ctype.h>
#include "freq.h"

int main(int argc, char const *argv[])
{
	char buf; // the input buffer
	char Do= 't'; // to choose if to print reverse or regular
	int i=0; // count word length
	int max=0; // save longest word length
	Node *root= newNode('\0');
	Node *temp = root; // pointer to root first, to any node needed afterthen

	//this loop read chars from standard input and inert it to the trie
	while ((buf=getc(stdin)) != EOF)
	{
		if ((buf >= 'a' && buf <= 'z') || (buf >= 'A' && buf <= 'Z'))
		{	
			temp = insert(temp, tolower(buf)); // insert the letter to the tree
			i++;
		}
		else if (buf == ' ' || buf == '\n' || buf == '\t')
		{
			incremental(temp); // increment the "end of word"-counter
			temp = root;
			if (i > max) max = i; // to save the longest word length
			i=0;
		}

	}
	
	char cmon[max+2]; // init an array of chars with the longest word length

	if(argc>1){ Do=*argv[1]; } 
	
	if(Do == 'r'){ printTreeR(root, cmon, 0); } // print the tree in reverse

	else{ printTree(root, cmon, 0); } // print the tree

	freeTree(root); // free all the allocated memory level-by-level from leafs to root 

	return 0;
}
