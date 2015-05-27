//weight-leftiest.h
#define SWAP(a, b, t) {t = a; a = b; b = t;}
#include "height-leftist.h"

void WinsertNode(int N, leftistTree *root);
void WdeleteNode(leftistTree *root);
void WminMeld(leftistTree *a, leftistTree *b);
void WminUnion(leftistTree *a, leftistTree *b);
