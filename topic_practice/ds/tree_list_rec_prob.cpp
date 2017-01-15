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
void toList(node *t, node **first, node **last) {
	if(t == NULL){
		*first = NULL;
		*last = NULL;
		return;
	}
	node *temp_left, *temp_right;
	toList(t->l, first, &temp_left);
	if(temp_left != NULL)
		temp_left->r = t;
	t->l = temp_left;
	toList(t->r, &temp_right, last);
	if(temp_right != NULL)
		temp_right->l = t;
	t->r = temp_right;
	if(temp_left == NULL)
		*first = t;
	if(temp_right == NULL)
		*last = t;
}
void print(node *first, node *last) {
	node *temp;
	temp = first;
	cout << endl << "in order :\n";
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->r;
	}
	cout << endl << "rev order :\n";
	temp = last;
	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->l;
	}
	cout << endl << "done\n";
}
int main() {
	int n, val;
	node *t, *first, *last;
	t = NULL;
	printf("Enter the no. of elements in the tree : ");
	scanf("%d", &n);
	for(int i  = 0 ; i < n ; i++){
		printf("Enter value : ");
		scanf("%d", &val);
		t = insert(t, val);
	}
	toList(t, &first, &last);
	print(first, last);
	first->l = last;
	last->r = first;
	return 0;
}