//main.c
#include <stdio.h>
#include <stdlib.h>
#include "height-leftist.h"

int _print_t(leftistTree *parent, int is_left, int offset, int depth, char s[20][255]){
	char b[20];
	int i ,width = 5;

	if (!*parent) return 0;

	sprintf(b, " %03d ", (*parent)->data);

	int left  = _print_t(&(*parent)->leftChild,  1, offset, depth + 1, s);
	int right = _print_t(&(*parent)->rightChild, 0, offset + left + width, depth + 1, s);

	for (i = 0; i < width; i++)
		s[2 * depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (i = 0; i < width + right; i++)
			s[2 * depth - 1][offset + left + width/2 + i] = '=';

		s[2 * depth - 1][offset + left + width/2] = '|';
		s[2 * depth - 1][offset + left + width + right + width/2] = '|';

	} else if (depth && !is_left) {

		for (i = 0; i < left + width; i++)
			s[2 * depth - 1][offset - width/2 + i] = '=';

		s[2 * depth - 1][offset + left + width/2] = '|';
		s[2 * depth - 1][offset - width / 2 - 1] = '|';
	}
	return left + width + right;
}

void print_tree(leftistTree *parent){
	char s[20][255];
	int i;
	for (i = 0; i < 20; i++)
		sprintf(s[i], "%80s", " ");

	_print_t(parent, 0, 0, 0, s);

	for (i = 0; i < 20; i++)
		printf("%s\n", s[i]);
}

int main(int argc, const char *argv[])
{
	FILE* inputStream;
	char inputString[100] = {0};
	leftistTree root = NULL;
	if((inputStream = fopen("left tree.txt", "r")) == NULL){
		fclose(inputStream);
		exit(1);
	}
	while(fgets(inputString, 100, inputStream)){
		switch(inputString[0]){
		case'i':
			insertNode(atoi(&inputString[2]), &root);
			break;
		case'd':
			deleteNode(&root);
			break;
		default:
			puts("command not found.");
		}
	}
	print_tree(&root);

	return 0;
}
