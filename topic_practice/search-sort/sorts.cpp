#include <cstdio>
using namespace std;

typedef struct {
	int *arr, sz;
}heap;

void selection_sort(int *a, int n) {
	int i, j, k, temp;
	for(i = 0 ; i < n ; i++) {
		k = i;
		for(j = i+1 ; j < n ; j++) {
			if(a[k] > a[j]) {
				k = j;
			}
		}
		temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}
}

void bubble_sort(int *a, int n) {
	int i, j, temp, f;
	f = 1;
	i = 0;
	while(f == 1 && i < n) {
		f = 0;
		for(j = 0 ; j < n-i-1 ; j++) {
			if(a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				f = 1;
			}
		}
	}
}

void insertion_sort(int *a, int n) {
	int i, j, temp;
	for(i = 1 ; i < n ; i++) {
		temp = a[i];
		for(j = i-1 ; j >= 0 ; j--) {
			if(a[j] > temp) {
				a[j+1] = a[j];
			}
			else {
				break;
			}
		}
		a[j+1] = temp;
	}
}

void mymerge(int *a, int m, int *b, int n, int *c) {
	int i, j, k;
	i = j = k = 0;
	while(i < m && j < n) {
		if(a[i] < b[j]) {
			c[k++] = a[i++];
		}
		else {
			c[k++] = b[j++];
		}
	}
	while(i < m) {
		c[k++] = a[i++];
	}
	while(j < n) {
		c[k++] = b[j++];
	}
}

void merge_sort(int *a, int n) {
	int *b, m, i;
	if(n == 1)
		return;
	m = n / 2;
	merge_sort(a, m);
	merge_sort(a+m, n-m);
	b = new int[n];
	mymerge(a, m, a+m, n-m, b);
	for(i = 0 ; i < n ; i++) {
		a[i] = b[i];
	}
	delete(b);
}

int getpartition(int *a, int n) {
	int i, j, temp;
	i = 1;
	j = n-1;
	while(1) {
		while(a[i] <= a[0] && i < n) {
			i++;
		}
		while(a[j] > a[0] && j >= 1) {
			j--;
		}
		if(i < j && i < n && j >= 1) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			j--;
		}
		else {
			break;
		}
	}
	temp = a[0];
	a[0] = a[j];
	a[j] = temp;
	return j;
}

int new_getpartition(int *a, int n) {
	int i, j, temp;
	j = -1;
	for(i = 0 ; i < n-1 ; i++) {
		if(a[i] <= a[n-1]) {
			j++;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	j++;
	temp = a[n-1];
	a[n-1] = a[j];
	a[j] = temp;
	return j;
}

heap *initheap(int sz) {
	heap *h;
	h = new heap();
	h->sz = 0;
	h->arr = new int[sz];
	return h;
}

void remheap(heap *h) {
	delete(h->arr);
	delete(h);
}

void quick_sort(int *a, int n) {
	int k;
	if(n <= 1)
		return;
	k = new_getpartition(a, n);
	quick_sort(a, k);
	quick_sort(a+k+1, n-k-1);
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

void heap_sort(int *a, int n) {
	int i, k, f;
	heap *h = makeheap(a, n);
	for(i = 0 ; i < n ; i++) {
		a[i] = htop(h);
		hdel(h, 0);
	}
	remheap(h);
}

int main() {
	int n, *a, i, k;
	scanf("%d", &n);
	a = new int[n];
	for(i = 0 ; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);
	switch(k) {
		case 0: selection_sort(a, n);
				break;
		case 1: bubble_sort(a, n);
				break;
		case 2: insertion_sort(a, n);
				break;
		case 3: quick_sort(a, n);
				break;
		case 4: merge_sort(a, n);
				break;
		case 5: heap_sort(a, n);
				break;
		default: merge_sort(a, n);
	}
	for(i = 0 ; i < n ; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	delete(a);
	return 0;
}