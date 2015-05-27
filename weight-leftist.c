//weight-leftist.c

#include <stdio.h>
#include <stdlib.h>
#include "weight-leftist.h"

void WinsertNode(int N, leftistTree *root){
	leftistTree node = (leftistTree)malloc(sizeof(leftist));
	if(node){
		node->data = N;
		node->weight = 1;
		node->leftChild = node->rightChild = NULL;
		WminMeld(root, &node);
	}
}

void WdeleteNode(leftistTree *root){
	if(*root){
		leftistTree remove = *root;
		WminMeld(&(*root)->leftChild, &(*root)->rightChild);
		*root = (*root)->leftChild;
		printf("%d\n", remove->data);
		free(remove);
	}
}

void WminMeld(leftistTree *a, leftistTree *b){
	if(!*a) *a = *b;
	else if(*b) WminUnion(a, b);
	*b = NULL;
}

void WminUnion(leftistTree *a, leftistTree *b){
	leftistTree temp = NULL;
	/* set a to be the tree with smaller root */

	leftistTree *nowA, *nowB;
	for(nowA = a, nowB = b;; ){
		if((*nowA)->data > (*nowB)->data){
			SWAP(*nowA, *nowB, temp);
			(*nowA)->weight += (*nowB)->weight;
		}
		if(!(*nowA)->rightChild){
			(*nowA)->rightChild = *nowB;
			break;
		}
		else{
			nowA = &(*nowA)->rightChild;
		}
	}
	if(!(*nowA)->leftChild){
		(*nowA)->leftChild = (*nowA)->rightChild;
		(*nowA)->rightChild = NULL;
	}
	else if((*a)->leftChild->weight < (*a)->rightChild->weight)
		SWAP((*a)->leftChild, (*a)->rightChild, temp);
}

