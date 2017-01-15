#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct NODE{
	int v;
	struct NODE *l, *r;
	int cnt;
}node;
int LISS(node *h){
	if(h == NULL)
		return 0;
	int s1,s2;
	s1 = s2 = 0;
	if(h -> l){
		if(h -> l -> cnt == -1)
			h -> l -> cnt = LISS(h -> l);
		s1 += h->l->cnt;
	}
	if(h -> r){
		if(h -> r -> cnt == -1)
			h -> r -> cnt = LISS(h -> r);
		s1 += h->r->cnt;
	}	
	if(h -> l and h -> l -> l){
		if(h -> l -> l -> cnt == -1)
			h -> l -> l -> cnt = LISS(h -> l -> l);
		s2 += h->l->l->cnt;
	}
	if(h -> l and h -> l -> r){
		if(h -> l -> r -> cnt == -1)
			h -> l -> r -> cnt = LISS(h -> l -> r);
		s2 += h->l->r->cnt;
	}
	if(h -> r and h -> r -> l){
		if(h -> r -> l -> cnt == -1)
			h -> r -> l -> cnt = LISS(h -> r -> l);
		s2 += h->r->l->cnt;
	}
	if(h -> r and h -> r -> r){
		if(h -> r -> r -> cnt == -1)
			h -> r -> r -> cnt = LISS(h -> r -> r);
		s2 += h->r->r->cnt;
	}
	s2++;
	return (s1 > s2) ? s1 : s2;
}
int main() {
	int n, *a, x;
	node *h, *p;
	h = new node;
	h -> v = 10;
	h -> cnt = -1;
	h -> l = new node;
	h -> r = new node;
	h -> l -> v = 20;
	h -> r -> v = 30;
	h -> l -> cnt = -1;
	h -> r -> cnt = -1;
	h -> l -> l = new node;
	h -> l -> r = new node;
	h -> l -> l -> v = 40;
	h -> l -> r -> v = 50;
	h -> l -> l -> cnt = -1;
	h -> l -> r -> cnt = -1;
	h -> l -> l -> l = NULL;
	h -> l -> l -> r = NULL;
	h -> l -> r -> l = new node;
	h -> l -> r -> r = new node;
	h -> l -> r -> l -> v = 70;
	h -> l -> r -> r -> v = 80;
	h -> l -> r -> l -> cnt = -1;
	h -> l -> r -> r -> cnt = -1;
	h -> l -> r -> l -> l = NULL;
	h -> l -> r -> l -> r = NULL;
	h -> l -> r -> r -> l = NULL;
	h -> l -> r -> r -> r = NULL;
	h -> r -> l = NULL;
	h -> r -> r = new node;
	h -> r -> r -> v = 60;
	h -> r -> r -> cnt = -1;
	h -> r -> r -> l = NULL;
	h -> r -> r -> r = NULL;
	h -> cnt = LISS(h);
	printf("The largest independent set has size : %d\n", h -> cnt);
	return 0;
}