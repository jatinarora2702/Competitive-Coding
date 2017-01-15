#include <cstdio>
using namespace std;

// 0 9 0 5 0 10 0 0 0 6 0 11 0 -1 0 1

typedef struct _bst {
	struct _bst *l, *r;
	int val, h;
}bst;

int max(int a, int b) {
	return (a > b) ? a : b; 
}

int getht(bst *node) {
	if(node == NULL) {
		return 0;
	}
	return node->h;
}

void printnode(bst *node) {
	if(node == NULL) {
		printf("NULL(0)");
	}
	else {
		printf("%d(%d)", node->val, node->h);
	}
}

void printbst(bst *node) {
	if(node != NULL) {
		printnode(node); printf(" -> "); printnode(node->l); printf(" "); printnode(node->r); printf("\n");
		printbst(node->l);
		printbst(node->r);
	}
}

void inorder(bst *root) {
	if(root == NULL) {
		return;
	}
	inorder(root->l);
	printf("%d ", root->val);
	inorder(root->r);
}

void preorder(bst *root) {
	if(root == NULL) {
		return;
	}
	printf("%d ", root->val);
	preorder(root->l);
	preorder(root->r);
}

void postorder(bst *root) {
	if(root == NULL) {
		return;
	}
	postorder(root->l);
	postorder(root->r);
	printf("%d ", root->val);
}

bst *initnode(int v) {
	bst *node = new bst();
	node->l = node->r = NULL;
	node->val = v;
	node->h = 1;
	return node;
}

bst *left_rotate(bst *node) {
	bst *y;
	y = node->r;
	node->r = y->l;
	y->l = node;
	node->h = max(getht(node->l), getht(node->r)) + 1;
	y->h = max(getht(y->l), getht(y->r)) + 1;
	return y;
}

bst *right_rotate(bst *node) {
	bst *y;
	y = node->l;
	node->l = y->r;
	y->r = node;
	node->h = max(getht(node->l), getht(node->r)) + 1;
	y->h = max(getht(y->l), getht(y->r)) + 1;
	return y;
}

bst *ins_rebalance(bst *node, int v) {
	int balance = getht(node->l) - getht(node->r);
	if(balance > 1) {
		if(v > node->l->val) {
			node->l = left_rotate(node->l);
		}
		node = right_rotate(node);
	}
	else if(balance < -1) {
		if(v < node->r->val) {
			node->r = right_rotate(node->r);
		}
		node = left_rotate(node);
	}
	return node;
}

bst *del_rebalance(bst *node) {
	int htl, htr;
	htl = getht(node->l);
	htr = getht(node->r);
	if(htl - htr > 1) {
		htl = getht(node->l->l);
		htr = getht(node->l->r);
		if(htr > htl) {
			node->l = left_rotate(node->l);
		}
		node = right_rotate(node);
	}
	else if(htr - htl > 1) {
		htl = getht(node->r->l);
		htr = getht(node->r->r);
		if(htl > htr) {
			node->r = right_rotate(node->r);
		}
		node = left_rotate(node);
	}
	return node;
}

bst *successor(bst *node) {
	bst *y;
	if(node == NULL || node->r == NULL) {
		return NULL;
	}
	y = node->r;
	while(y->l != NULL) {
		y = y->l;
	}
	return y;
}

bst *bst_insert(bst *node, int v) {
	if(node == NULL) {
		return initnode(v);
	}
	if(v < node->val) {
		node->l = bst_insert(node->l, v);
	}
	else if(v > node->val) {
		node->r = bst_insert(node->r, v);
	}
	node->h = max(getht(node->l), getht(node->r)) + 1;
	printf("++++++++++++++++++++++++\n");
	printf("node: %d\n", node->val);
	printbst(node);
	printf("++++++++++++++++++++++++\n");
	ins_rebalance(node, v);
}

bst *bst_delete(bst *node, int v) {
	bst *y;
	if(node == NULL) {
		return node;
	}
	if(v < node->val) {
		node->l = bst_delete(node->l, v);
	}
	else if(v > node->val) {
		node->r = bst_delete(node->r, v);
	}
	else {
		if(node->l != NULL && node->r != NULL) {
			y = successor(node);
			node->val = y->val;
			node->r = bst_delete(node->r, node->val);
		}
		else {
			if(node->l != NULL) {
				y = node;
				node = node->l;
				y->l = NULL;
				delete(y);
			}
			else {
				y = node;
				node = node->r;
				y->r = NULL;
				delete(y);
			}
		}
		node->h = max(getht(node->l), getht(node->r)) + 1;
	}
	node = del_rebalance(node);
	return node;
}

int main() {
	int f, k, v;
	bst *root;
	f = 1;
	root = NULL;
	while(f) {
		printf("choice:\n");
		scanf("%d", &k);
		switch(k) {
			case 0: printf("Insert:\n");
					scanf("%d", &v);
					root = bst_insert(root, v);
					printbst(root);
					break;
			case 1: printf("Delete:\n");
					scanf("%d", &v);
					root = bst_delete(root, v);
					printbst(root);
					break;
			case 2: printf("Printing:\n");
					printf("Inorder: ");
					inorder(root);
					printf("\nPostorder: ");
					postorder(root);
					printf("\npreorder: ");
					preorder(root);
					printf("\nbst:\n");
					printbst(root);
					printf("\n");
					break;
			default: f = 0;
		}
	}
	return 0;
}