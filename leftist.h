//height-leftist.h
#define SWAP(a, b, t) {t = a; a = b; b = t;}

typedef struct leftist *leftistTree;
struct leftist{
	leftistTree leftChild;
	int data;
	leftistTree rightChild;
	int shortest;
	int weight;
};
typedef struct leftist leftist;

void insertNode(int N, leftistTree *root);
void deleteNode(leftistTree *root);
void minMeld(leftistTree *a, leftistTree *b);
void minUnion(leftistTree *a, leftistTree *b);

void WinsertNode(int N, leftistTree *root);
void WdeleteNode(leftistTree *root);
void WminMeld(leftistTree *a, leftistTree *b);
void WminUnion(leftistTree *a, leftistTree *b);
