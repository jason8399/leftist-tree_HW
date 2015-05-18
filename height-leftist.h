//height-leftist.h
#define SWAP(a, b, t) a = t; a = b ; b = t;

typedef struct leftist *leftistTree;
struct leftist{
	leftistTree leftChild;
	int data;
	leftistTree rightChild;
	int shortest;
};
typedef struct leftist leftist;

void insertNode(int N, leftistTree *root);
void deleteNode(leftistTree *root);
void minMeld(leftistTree *a, leftistTree *b);
void minUnion(leftistTree *a, leftistTree *b);
