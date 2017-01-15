#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct NODE{
	int data;
	struct NODE *l, *r;
}node;
node* insert(node *t, int val) {
	node *x = new node;
	x->l = x->r = NULL;
	x->data = val;
	node *y, *z;
	y = z = t;
	if(z != NULL)
		cout << "z=" << z->data << endl;
	while(y != NULL) {
		if(val < y->data){
			z = y;
			y = y->l;
		}
		else{
			z = y;
			y = y->r;
		}
	}
	if(t == NULL){
		t = x;
		printf("here\n");
		return t;
	}
	if(z->data < val)
		z->r = x;
	else
		z->l = x;
	return t;
}
int ht(node *t){
	if(t == NULL)
		return 0;
	printf("val = %d\n", t->data);
	return 1 + max(ht(t->l), ht(t->r));
}
int main() {
	int n, val;
	node *t = NULL;
	printf("Enter the no. of elements in the tree : ");
	scanf("%d", &n);
	for(int i  = 0 ; i < n ; i++){
		printf("Enter value : ");
		scanf("%d", &val);
		t = insert(t, val);
	}
	printf("Ht. of tree is : %d\n", ht(t));
	return 0;
}
