#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int *arr, sz;
}heap;

heap *initheap(int sz) {
	heap *h;
	h = new heap();
	h->sz = 0;
	h->arr = new int[sz];
	return h;
}

void printheap(heap *h) {
	int i;
	printf("sz: %d\n", h->sz);
	printf("heap: ");
	for(i = 0 ; i < h->sz ; i++) {
		printf("(%d, %d) ", i, h->arr[i]);
	}
	printf("\n");
}

void heapify(heap *h, int k) {
	int i, j, temp;
	i = k;
	while(1) {
		j = i;
		if(2*i+1 < h->sz && h->arr[j] > h->arr[2*i+1]) {
			j = 2*i+1;
		}
		if(2*i+2 < h->sz && h->arr[j] > h->arr[2*i+2]) {
			j = 2*i+2;
		}
		if(i != j) {
			temp = h->arr[i];
			h->arr[i] = h->arr[j];
			h->arr[j] = temp;
			i = j;
		}
		else {
			break;
		}
	}
}

void hadd(heap *h, int k) {
	int i, temp;
	h->arr[h->sz] = k;
	i = h->sz;
	h->sz++;
	while(i > 0 && h->arr[i] < h->arr[(i-1)/2]) {
		temp = h->arr[i];
		h->arr[i] = h->arr[(i-1)/2];
		h->arr[(i-1)/2] = temp;
		i = (i-1)/2;
	}
}

void hdel(heap *h, int k) {
	h->arr[k] = h->arr[h->sz-1];
	h->sz -= 1;
	heapify(h, k);
}

int htop(heap *h) {
	return h->arr[0];
}

heap *makeheap(int *a, int n) {
	int i;
	heap *h;
	h = new heap();
	h->sz = n;
	h->arr = new int[n];
	for(i = 0 ; i < n ; i++) {
		h->arr[i] = a[i];
	}
	for(i = n/2 - 1 ; i >= 0 ; i--) {
		heapify(h, i);
	}
	return h;
}

void remheap(heap *h) {
	delete(h->arr);
	delete(h);
}

int main() {
	int f, v, k, max_heap_size;
	heap *h;
	printf("Enter max-heap size:\n");
	scanf("%d\n", &max_heap_size);
	h = initheap(max_heap_size);
	while(f) {
		printf("Enter choice:\n");
		scanf("%d", &k);
		switch(k) {
			case 1: printf("Adding:\n");
					scanf("%d", &v);
					hadd(h, v);
					break;
			case 2: printf("Deleting:\n");
					scanf("%d", &v);
					hdel(h, v);
					break;
			case 3: printf("---------------------\n");
					printheap(h);
					printf("---------------------\n");
					break;
			default: printf("---------------------\n");
					printheap(h);
					printf("---------------------\n");
		}
		printf("More op? (0/1): ");
		scanf("%d", &f);
		printf("\n");
	}
	return 0;
}