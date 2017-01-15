#include <iostream>
#include <stdio.h>
#define N 10
#define NDEPT 23
using namespace std;
const char DEPT[NDEPT][3] =
{ "AE", "AG", "AR", "BT", "CE", "CH", "CS", "CY", "EC", "EE", "EX", "GG",
"HS", "IE", "IM", "MA", "ME", "MF", "MI", "MT", "NA", "PH", "QD" };
typedef struct{
	int *a;
	int s, n, d;
}hashtable;
int nextPrime(int n){
	int flag, k;
	k = n+1;
	while(true){
		flag = 0;
		for(int i = 3 ; i <= sqrt(k) ; i+=2){
			if(k % i == 0){
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			return k;
	}
}
hashtable* createEmptyHashTable(int s){
	hashtable *table = new hashtable;
	table->a = new int[s];
	table->s = s;
	table->n = table->d = 0;
	for(int i = 0 ; i < s ; i++){
		table->a[i] = 0;
	}
	return table;
}
int hash_value(char *roll, int s){
	int k = (roll[0]-'0')*10 + (roll[1]-'0');
	for(int i = 4 ; i < 9 ; i++){
		k *= 10;
		k += (roll[i]-'0');
	}
	for(int i = 0 ; i < NDEPT ; i++){
		if(DEPT[i][0] == roll[2] && DEPT[i][1] == roll[3]){
			k += i;
			break;
		}
	}
	k %= s;
	return k;
}
float search(hashtable *h, char *roll){
	int key = hash_value(roll, h->s);
	int j = 0;
	float cg = 0;
	while(true){
		if(h->a[key] == -1){
			j++;
			key += (j*j);
			key %= s;
		}
		return h->a[key];
	}
}
void rehash(hashtable **h){
	int s = nextPrime((*h)->n * 2);
	hashtable *nh = new hashtable;
	nh->a = new rec[s];
	nh->n = h->n;
	nh->s = s;
	nh->d = 0;
	for(int i = 0 ; i < (*h)->s ; i++){
		if((*h)->a[i] > 0){
			hash_value; // INCOMPLETE CODE
		}
	}
}
void insert(hashtable **h, char *roll, float cg) {
	int key = hash_value(roll, (*h)->s);
	float lambda;
	if((*h)->a[key] > 0)
		return;
	if((*h)->a[key] == -1)
		(*h)->d -= 1;
	(*h)->a[key] = cg;
	(*h)->n += 1;
	lambda = (*h)->n / (float)(*h)->s;
	if(lambda >= 0.5)
		rehash(h);
}
int deleterec(hashtable **h, char *roll){
	int j = 0;
	int key = hash_value(roll, (*h)->s);
	float delta;
	while(true){
		if((*h)->a[key] == -1){
			j++;
			key += (j*j);
		}
		if((*h)->a[key] == 0)
			return 0;
		if((*h)->a[key] > 0){
			(*h)->a[key] = -1;
			(*h)->d += 1;
			delta = (*h)->d / (float)(*h)->s;
			if(delta >= 0.2)
				rehash(h);
			return 1;
		}
	}
}
void print(hashtable *h){
	for(int i = 0 ; i < h->s ; i++)
		if(h->a[i] == 0)
			printf("EMPTY\n");
		else if(h->a[i] == -1)
			printf("DELETED\n");
		else
			printf("%d\n", h->a[i]);
	}
}
int main() {
	int k, s, f, status;
	char *roll = new char[N];
	hashtable *h;
	printf("Enter the no. of records to be entered : ");
	scanf("%d", &k);
	s = nextPrime(2*k);
	h = createEmptyHashTable(s);
	printf("Enter the records :\n");
	for(int i = 0 ; i < k ; i++){
		scanf("%s%f", roll, &cg);
		insert(h, roll, cg);
	}
	while(true){
		printf("1) Search  2) Insert  3) Delete  4) Print  5) Exit | Enter option : ");
		scanf("%d", &f);
		if(f == 5)
			break;
		switch(f) {
			case 1: printf("Enter roll to be searched : ");
					scanf("%s", roll);
					cg = search(h, roll);
					if(cg > 0)
						printf("cgpa : %f\n", cg);
					break;
			case 2: printf("Enter roll and cg to insert : ");
					scanf("%s%f", roll, &cg);
					insert(h, roll, cg);
					break;
			case 3: printf("Enter roll to be deleted : ");
					scanf("%s", roll);
					status = deleterec(h, roll);
					if(status == true)
						printf("successfully deleted");
					else
						printf("deletion unsuccessful");
					break;
			case 4: printf("hash table :\n");
					print(h);
					break;
		}
	}
	return 0;
}