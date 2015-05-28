//height-leftist.c
#include <stdio.h>
#include <stdlib.h>
#include "leftist.h"

void insertNode(int N, leftistTree *root){
	leftistTree node = (leftistTree)malloc(sizeof(leftist));
	if(node){
		node->data = N;
		node->weight = 1;
		node->shortest = 1;
		node->leftChild = node->rightChild = NULL;
		minMeld(root, &node);
	}
}

void deleteNode(leftistTree *root){
	if(*root){
		leftistTree remove = *root;
		minMeld(&(*root)->leftChild, &(*root)->rightChild);
		*root = (*root)->leftChild;
		printf("%d\n", remove->data);
		free(remove);
	}
	else{
		printf("tree empty\n");
	}
}

void minMeld(leftistTree *a, leftistTree *b){
	/*
	 * meld the two min leftist trees *a amd *b. The resulting
	 * min leftist tree is returned in *a, and *b is set to NULL
	 */
	if(!*a) *a = *b;
	else if(*b) minUnion(a, b);
	*b = NULL;
}

void minUnion(leftistTree *a, leftistTree *b){
	/*
	 * recursively combine two nonempty min leftist trees
	 */
	leftistTree temp = NULL;
	/* set a to be the tree with smaller root */
	if((*a)->data > (*b)->data) SWAP(*a, *b, temp);

	/* create binary tree such that the smallest key in each
	 * subtree is in the root */
	if(!(*a)->rightChild) (*a)->rightChild = *b;
	else minUnion(&(*a)->rightChild, b);

	/* leftist tree property */
	if(!(*a)->leftChild){
		(*a)->leftChild = (*a)->rightChild;
		(*a)->rightChild = NULL;
	}
	else if((*a)->leftChild->shortest < (*a)->rightChild->shortest)
		SWAP((*a)->leftChild, (*a)->rightChild, temp);
	(*a)->shortest = (!(*a)->rightChild) ? 1 : (*a)->rightChild->shortest + 1;
}

//weight-leftist

void WinsertNode(int N, leftistTree *root){
	leftistTree node = (leftistTree)malloc(sizeof(leftist));
	if(node){
		node->data = N;
		node->weight = 1;
		node->shortest = 1;
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

	leftistTree *nowA, *nowB, *hisA;
	for(nowA = hisA =a, nowB = b;; ){
		if((*nowA)->data > (*nowB)->data){
			SWAP(*nowA, *nowB, temp);
		}
		(*nowA)->weight += (*nowB)->weight;
		if(!(*nowA)->rightChild){
			if(!(*nowA)->leftChild){
				(*nowA)->leftChild = *nowB;
			}
			else{
				(*nowA)->rightChild = *nowB;
				if((*nowA)->leftChild->weight < (*nowA)->rightChild->weight)
					SWAP((*nowA)->leftChild, (*nowA)->rightChild, temp);
			}
			if(!(*hisA)->leftChild ){
				SWAP((*hisA)->leftChild, (*hisA)->rightChild, temp);
			}
			else if (!(*hisA)->rightChild){
			}
			else if((*hisA)->leftChild->weight < (*hisA)->rightChild->weight){
				SWAP((*hisA)->leftChild, (*hisA)->rightChild, temp);
			}
			break;
		}
		else{
			if(!(*hisA)->leftChild ){
				SWAP((*hisA)->leftChild, (*hisA)->rightChild, temp);
				nowA = &(*hisA)->leftChild;
			}
			else if (!(*hisA)->rightChild){
			}
			else if((*hisA)->leftChild->weight < (*hisA)->rightChild->weight){
				SWAP((*hisA)->leftChild, (*hisA)->rightChild, temp);
				nowA = &(*hisA)->leftChild;
			}
			hisA = nowA;
			nowA = &(*nowA)->rightChild;
		}
	}
}
