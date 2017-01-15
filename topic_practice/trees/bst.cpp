#include <cstdio>
using namespace std;

typedef struct _bst {
	struct _bst *l, *r;
	int val;
}bst;

bst *bst_insert(bst *root, int v) {
	bst *x, *y, *py;
	x = new bst();
	x->val = v;
	x->l = x->r = NULL;
	if(root == NULL) {
		root = x;
		return root;
	}
	y = root;
	py = root;
	while(y != NULL) {
		py = y;
		if(v < y->val) {
			y = y->l;
		}
		else if(v > y->val) {
			y = y->r;
		}
		else {
			return root;
		}
	}
	y = py;
	if(v < y->val) {
		y->l = x;
	}
	else {
		y->r = x;
	}
	return root;
}

bst *successor(bst *node) {
	bst *y, *py;
	if(node == NULL || node->r == NULL) {
		return NULL;
	}
	y = node->r;
	py = node;
	while(y->l != NULL) {
		py = y;
		y = y->l;
	}
	return py;
}

bst *bst_delete(bst *root, int v) {
	bst *y, *py, *z;
	py = y = root;
	while(y->val != v && y != NULL) {
		py = y;
		if(v < y->val) {
			y = y->l;
		}
		else {
			y = y->r;
		}
	}
	if(y == NULL) {
		return root;
	}
	if(y->l != NULL && y->r != NULL) {
		z = successor(y);
		if(z != NULL) {
			if(z == y) {
				y->val = y->r->val;
				py = y;
				y = y->r;
			}
			else {
				y->val = z->l->val;
				py = z;
				y = z->l;
			}
		}
		else {
			return root;
		}
	}
	if(y == py->l) {
		if(y->l != NULL) {
			py->l = y->l;
		}
		else {
			py->l = y->r;
		}
	}
	else {
		if(y->l != NULL) {
			py->r = y->l;
		}
		else {
			py->r = y->r;
		}
	}
	y->l = y->r = NULL;
	if(y == root) {
		if(y->l != NULL) {
			root = y->l;
		}
		else {
			root = y->r;
		}
		return root;
	}
	delete(y);
	return root;
}

void printbst(bst *root) {
	if(root != NULL) {
		printf("%d -> ", root->val);
		if(root->l == NULL) {
			printf("NULL ");
		}
		else {
			printf("%d ", root->l->val);
		}
		if(root->r == NULL) {
			printf("NULL\n");
		}
		else {
			printf("%d\n", root->r->val);
		}
		printbst(root->l);
		printbst(root->r);
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