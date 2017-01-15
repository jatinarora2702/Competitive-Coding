#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct treenode{
	int v;
	char c;
	struct treenode *l, *r, *p;
}node;
void inorder(node *root){
	if(root != NULL){
		inorder(root->l);
		printf("[%d %c]", root->v, root->c);
		inorder(root->r);
	}
}
void print(node *root){
	if(root == NULL)
		return;
	printf("[%d %c] -> ", root->v, root->c);
	if(root->l != NULL)
		printf("[%d %c]", root->l->v, root->l->c);
	else if(root->l == NULL)
		printf("[-1 B]");
	if(root->r != NULL)
		printf("[%d %c]", root->r->v, root->r->c);
	else if(root->r == NULL)
		printf("[-1 B]");
	printf("\n");
	print(root->l);
	print(root->r);
}
node* rrotate(node **root, node *x){
	if(x->l != NULL){
		node *y = x->l;
		y->r = x->l;
		if(y->r != NULL)
			y->r->p = x;
		y->p = x->p;
		if(x->p != NULL){
			if(x->p->l == x)
				x->p->l = y;
			else
				x->p->r = y;
		}
		if(x->p == NULL)
			*root = y;
		x->p = y;
		y->r = x;
		return y;
	}
	return x;
}
node *lrotate(node **root, node *x){
	if(x->r != NULL){
		node *y = x->r;
		x->r = y->l;
		if(y->l != NULL)
			y->l->p = x;
		y->l = x;
		y->p = x->p;
		if(x->p != NULL){
			if(x->p->l == x)
				x->p->l = y;
			else
				x->p->r = y;
		}
		else
			*root = y;
		x->p = y;
		return y;
	}
	return x;
}
void rb_insert(node **root, int val){
	node *x = new node;
	x->v = val;
	x->c = 'R';
	x->l = x->r = NULL;
	if(*root == NULL){
		x->p = NULL;
		x->c = 'B';
		*root = x;
	}
	else{
		node *y, *z, *g;
		y = z = *root;
		while(y != NULL){
			z = y;
			if(val < y->v)
				y = y->l;
			else
				y = y->r;
		}
		x->p = z;
		if(val < z->v)
			z->l = x;
		else if(val >= z->v)
			z->r = x;
		while(x->p != NULL){
			z = x->p;
			g = NULL;
			if(z->p != NULL){
				g = z->p;
				node *u;
				if(g->l == z)
					u = g->r;
				else if(g->r == z)
					u = g->l;
				if(u->c == 'R'){
					u->c = 'B';
					z->c = (z->c == 'B') ? 'R' : 'B';
					g->c = 'R';
					if(g->p == NULL)
						g->c = 'B';
				}
				else if(u->c == 'B'){
					if(g->r == z and z->l == x){
						z = g->r = rrotate(root, z);
						z->p = g;
						x = z->r;
					}
					if(g->r == z and z->r == x){
						if(g->p != NULL){
							y = g->p;
							if(y->l == g){
								g = y->l = lrotate(root, g);
								g->p = y;
							}
							else{
								g = y->r = lrotate(root, g);
								g->p = y;
							}
						}
						z = g->l;
						z->p = g;
						g->c = (g->c == 'B') ? 'R' : 'B';
						z->c = (z->c == 'B') ? 'R' : 'B';
					}
					if(g->l == z and z->r == x){
						z = g->l = lrotate(root, z);
						z->p = g;
						x = z->l;
					}
					if(g->l == z and z->l == x){
						if(g->p != NULL){
							y = g->p;
							if(y->l == g){
								g = y->l = rrotate(root, g);
								g->p = y;
							}
							else{
								g = y->r = rrotate(root, g);
								g->p = y;
							}
						}
						z = g->r;
						z->p = g;
						g->c = (g->c == 'B') ? 'R' : 'B';
						z->c = (z->c == 'B') ? 'R' : 'B';
					}
				}
			}
			if(g == NULL)
				x = z;
			else
				x = g;
		}
		if(x->c == 'R')
			x->c = 'B';
	}
}
int main() {
	int n, val;
	node *root = NULL;
	printf("Enter the no. of elements to be entered : ");
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &val);
		rb_insert(&root, val);
		printf("Tree after insertion :\n");
		print(root);
		printf("Inorder Traversal :\n");
		inorder(root);
		printf("Done\n");
	}
	return 0;
}