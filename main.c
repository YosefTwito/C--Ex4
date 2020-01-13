#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include "freq.h"

int main(int argc, char const *argv[])
{
	char buf;
	char Do= 't';
	int i=0;
	//char *word ="it was the best of times, it was the worst of times. ";
	Node *root= newNode('\0');
	Node *temp = root;
	char cmon[1024];

	while ((buf=getc(stdin)) != EOF)
	//while (word[i] != '\0')
	{
		//buf = word[i];
		if ((buf >= 'a' && buf <= 'z') || (buf >= 'A' && buf <= 'Z'))
		{
			temp = insert(temp, tolower(buf));
		}
		else if (buf == ' ' || buf == '\n')
		{
			incremental(temp);
			temp = root;
		}
		i++;
	}

	//printf("%d\n", argc);
	if(argc>1){ Do=*argv[1]; }	
	//printf("%c\n", Do);

	if(Do == 'r'){ printTreeR(root, cmon, 0); }
	else{ printTree(root, cmon, 0); }
	freeTree(root);
	return 0;
}
