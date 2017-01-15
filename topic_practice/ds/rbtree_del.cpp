#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct treenode{
	int val;
	char c;
	struct treenode *l, *r, *p;
}node;
node *lrotate(node **root, node *x){
	node *y = x->r;
	if(y != NULL){
		node *z = x->p;
		if(z != NULL){
			if(x == z->l)
				z->l = y;
			else
				z->r = y;
		}
		y->p = z;
		if(z == NULL)
			*root = y;
		x->r = y->l;
		if(y->l != NULL)
			y->l->p = x;
		y->l = x;
		x->p = y;
	}
	return y;
}
node *rrotate(node **root, node *x){
	node *y = x->l;
	if(y != NULL){
		node *z = x->p;
		if(z != NULL){
			if(x == z->l)
				z->l = y;
			else
				z->r = y;
		}
		y->p = z;
		if(z == NULL)
			*root = y;
		x->l = y->r;
		if(y->r != NULL)
			y->r->p = x;
		y->r = x;
		x->p = y;
	}
	return y;
}
void deletion(node **root, int value){
	node *x, *z, *y, *temp;
	x = *root;
	while(x != NULL){
		if(value > x->val)
			x = x->r;
		else if(value < x->val)
			x = x->l;
		else
			break;
	}
	if(x != NULL){
		if(x->l != NULL and x->r != NULL){
			z = get_pred(x);
			x->v = z->v;
			x = z;
		}
		if(x->l == NULL)
			y = x->r;
		else
			y = x->l;
		z = x->p;
		x->p = NULL;
		temp = x;
		if(z != NULL){
			if(z->l == x)
				z->l = y;
			else
				z->r = y;
		}
		if(y != NULL)
			y->p = z;
		if(y != NULL and temp->c != y->c){
			delete(temp);
			break;
		}
		else{
			if(y != NULL)
				y->c = 'D';
			if(z == NULL){
				*root = y;
				delete(temp);
				if(y != NULL)
					y->c = 'B';
				break;
			}
			else{
				if(z->l == y)
					s = z->r;
				else
					s = z->l;
				if(s != NULL and s->c == 'R'){
					if(z->p != NULL){
						if(s == z->r){
							if(z->p->l == z){
								z = z->p->l = lrotate(root, z);
							}
							else{
								z = z->p->r = lrotate(root, z);
							}
						}
						else{
							if(z->p->l == z){
								z = z->p->l = rrotate(root, z);
							}
							else{
								z = z->p->r = rrotate(root, z);
							}
						}
					}
					else{
						
					}
				}
			}
		}
	}
}