//main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "leftist.h"
#define CONSOLEX 80
#define CONSOLEY 24

int maxHeight(leftistTree p)
{
    if (!p) return 0;
    int left_height = maxHeight(p->leftChild);
    int right_height = maxHeight(p->rightChild);
    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}

int _print_t(leftistTree *parent, int is_left, int offset, int depth, char s[80][1024]){
	char b[80];
	int i ,width = 5;

	if (!*parent) return 0;

	sprintf(b, "%03d:%d", (*parent)->data, (*parent)->weight);

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
	char s[80][1024];
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
	clock_t t;
	long time;
	leftistTree root = NULL;
	if((inputStream = fopen("leftist tree.txt", "r")) == NULL){
		fclose(inputStream);
		exit(1);
	}
	t = clock();
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
	time = clock() - t;
	print_tree(&root);
	printf("height time: %lu ms\n", time);

	//weight
	root = NULL;
	rewind(inputStream);
	t = clock();
	while(fgets(inputString, 100, inputStream)){
		switch(inputString[0]){
		case'i':
			WinsertNode(atoi(&inputString[2]), &root);
			//print_tree(&root);
			break;
		case'd':
			WdeleteNode(&root);
			//print_tree(&root);
			break;
		default:
			puts("command not found.");
		}
	}
	time = clock() - t;
	print_tree(&root);
	printf("wight time: %lu ms\n", time);
	return 0;
}
