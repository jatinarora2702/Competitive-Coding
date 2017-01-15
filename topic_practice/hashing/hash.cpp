#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define NDEPT 23
#define DELETED -2.0
#define EMPTY -1.0
#define DELTA 0.2
#define LAMDA 0.5

/*
3
08QD82110 5.02
09AE52345 7.61
11ME82353 7.81
2 08QD82110
1 08MT61908 6.17
2 09AE52345
1 00BT10044 5.17
1 11BT30825 5.98
3 00BT10044
3 07IE66982

*/

const char DEPT[NDEPT][3] =
   { "AE", "AG", "AR", "BT", "CE", "CH", "CS", "CY", "EC", "EE", "EX", "GG",
     "HS", "IE", "IM", "MA", "ME", "MF", "MI", "MT", "NA", "PH", "QD" };

typedef struct {
	char *roll;
	float cg;
}record;

typedef struct {
	record *arr;
	int ins, del, sz;
}hashtab;

hashtab *hinsert(hashtab *h, record &r);

int getnextprime(int n) {
	int i, m, k, f;
	if(n < 2) {
		return 2;
	}
	m = (n % 2 == 0) ? n-1 : n;
	while(1) {
		m += 2;
		f = 1;
		k = sqrt(m);
		for(i = 3 ; i <= k ; i+=2) {
			if(m % i == 0) {
				f = 0;
				break;
			}
		}
		if(f == 1) {
			break;
		}
	}
	return m;
}

hashtab *createEmptyHashTable(int k) {
	int i;
	hashtab *h;
	h = new hashtab();
	h->sz = k;
	h->arr = new record[h->sz];
	h->ins = h->del = 0;
	for(i = 0 ; i < h->sz ; i++) {
		h->arr[i].roll = NULL;
		h->arr[i].cg = EMPTY;
	}
	return h;
}

int getindex(char *s) {
	int i;
	char stemp[3];
	stemp[0] = s[2];
	stemp[1] = s[3];
	stemp[2] = '\0';
	for(i = 0 ; i < NDEPT ; i++) {
		if(strcmp(stemp, DEPT[i]) == 0) {
			return i;
		}
	}
	return -1;
}

int getbaseval(char *s, int n) {
	int k, i;
	k = 0;
	for(i = 0 ; i < 2 ; i++) {
		k = 10*k + (s[i]-'0');
	}
	for(i = 4 ; i < 9 ; i++) {
		k = 10*k + (s[i]-'0');
	}
	k += getindex(s);
	k %= n;
	return k;
}

int gethash(int b, int k, int n) {
	b = b + k * k;
	b %= n;
	return b;
}

int isempty(record &r) {
	if(r.cg == EMPTY)
		return 1;
	return 0;
}

int isdeleted(record &r) {
	if(r.cg == DELETED)
		return 1;
	return 0;
}

void cleantab(hashtab *h) {
	int i;
	if(h->arr != NULL) {
		delete(h->arr);
	}
	delete(h);
}

void makeentry(record *pr, record &r) {
	int n;
	n = strlen(r.roll);
	pr->roll = new char[n+1];
	strcpy(pr->roll, r.roll);
	pr->cg = r.cg;
}

void printTab(hashtab *h) {
	int i;
	printf("s = %d, n = %d, d = %d\n", h->sz, h->ins, h->del);
	for(i = 0 ; i < h->sz ; i++) {
		printf("Entry %d: ", i);
		if(isempty(h->arr[i])) {
			printf("EMPTY\n");
		}
		else if(isdeleted(h->arr[i])) {
			printf("DELETED\n");
		}
		else {
			printf("%s, %.2f\n", h->arr[i].roll, h->arr[i].cg);
		}
	}
}

hashtab *rehash(hashtab *oldh) {
	int i, k;
	hashtab *h;
	printf("Rehashing... Please wait...%d\n", getnextprime(oldh->sz));
	if(oldh->ins / (1.0 * oldh->sz) >= LAMDA) {
		k = getnextprime(oldh->sz);
	}
	else if(oldh->del / (1.0 * oldh->sz) >= DELTA) {
		k = oldh->sz;
	}
	else {
		return oldh;
	}
	h = createEmptyHashTable(k);
	printTab(h);
	for(i = 0 ; i < oldh->sz ; i++) {
		printf("i=%d\n", i);
		if(!isempty(oldh->arr[i]) && !isdeleted(oldh->arr[i])) {
			h = hinsert(h, oldh->arr[i]);
			printTab(h);
		}
	}
	printf("done!\n");
	cleantab(oldh);
	printf("kool!\n");
	return h;
}

hashtab *hinsert(hashtab *h, record &r) {
	int k, b, i;
	b = getbaseval(r.roll, h->sz);
	printf("+++ Insert (%s, %.2f)\n", r.roll, r.cg);
	for(i = 0 ; i < h->sz ; i++) {
		k = gethash(b, i, h->sz);
		if(isempty(h->arr[k])) {
			makeentry(h->arr + k, r);
			(h->ins)++;
			break;
		}
		else if(isdeleted(h->arr[k])) {
			makeentry(h->arr + k, r);
			(h->ins)++;
			(h->del)--;
			break;
		}
	}
	if(h->ins / (1.0 * h->sz) >= LAMDA) {
		h = rehash(h);
	}
	return h;
}

hashtab *hdelete(hashtab *h, char *s) {
	int k, b, i;
	b = getbaseval(s, h->sz);
	printf("+++ Delete %s\n", s);
	for(i = 0 ; i < h->sz ; i++) {
		k = gethash(b, i, h->sz);
		if(isempty(h->arr[k])) {
			break;
		}
		else if(!isdeleted(h->arr[k])) {
			if(strcmp(s, (h->arr[k]).roll) == 0) {
				delete((h->arr[k]).roll);
				(h->arr[k]).cg = DELETED;
				(h->del)++;
				(h->ins)--;
				break;
			}
		}
	}
	if(h->del / (1.0 * h->sz) >= DELTA) {
		h = rehash(h);
	}
	return h;
}

float hsearch(hashtab *h, char *s) {
	int k, b, i;
	b = getbaseval(s, h->sz);
	printf("+++ Search(%s)\n", s);
	for(i = 0 ; i < h->sz ; i++) {
		k = gethash(b, i, h->sz);
		if(isempty(h->arr[k])) {
			return EMPTY;
		}
		else if(!isdeleted(h->arr[k])) {
			if(strcmp(s, (h->arr[k]).roll) == 0) {
				return h->arr[k].cg;
			}
		}
	}
	return EMPTY;
}

int main() {
	int k, f, i;
	record r;
	hashtab *h;
	scanf("%d", &k);
	h = createEmptyHashTable(getnextprime(2 * k));
	for(i = 0 ; i < k ; i++) {
		scanf("%s%f", r.roll, &(r.cg));
		h = hinsert(h, r);
	}
	printTab(h);
	while(1) {
		printf("1. Insert (R,C) | 2. Delete (R) | 3. Search (R) | 4. Exit\n");
		scanf("%d", &f);
		switch(f) {
			case 1: scanf("%s%f", r.roll, &(r.cg));
					h = hinsert(h, r);
					printTab(h);
					break;
			case 2: scanf("%s", r.roll);
					h = hdelete(h, r.roll);
					printTab(h);
					break;
			case 3: scanf("%s", r.roll);
					r.cg = hsearch(h, r.roll);
					if(r.cg < 0.0) {
						printf("Roll number %s does not exist\n", r.roll);
					}
					else {
						printf("The CGPA of %s is %.2f\n", r.roll, r.cg);
					}
					break;
			case 4: cleantab(h);
					return 0;
		}
	}
	return 1;
}