#include <iostream>
#include <stdio.h>
#include <cstring>
#define ALPHA_SIZE 26
using namespace std;
typedef struct TRIE_NODE{
	int value;
	struct TRIE_NODE *children[ALPHA_SIZE];
}trie_node;
typedef struct TRIE{
	int count;
	trie_node *root;
}trie;
trie_node* get_node(){
	trie_node *tn;
	tn = new trie_node;
	tn->value = 0;
	for(int i = 0 ; i < ALPHA_SIZE ; i++)
		tn->children[i] = NULL;
	return tn;
}
void initialize(trie *t){
	t->count = 0;
	t->root = get_node();
}
void insert(trie *t, char key[]){
	int length, level, index;
	trie_node *x = t->root;
	t->count++;
	length = strlen(key);
	for(level = 0 ; level < length ; level++){
		index = key[level] - 'a';
		if(x->children[index] == NULL)
			x->children[index] = get_node();
		x = x->children[index];
	}
	x->value = t->count;
}
int search(trie *t, char key[]){
	int level, length, index;
	trie_node *x = t->root;
	length = strlen(key);
	for(level = 0 ; level < length ; level++){
		index = key[level] - 'a';
		if(x->children[index] == NULL)
			return 0;
		x = x->children[index];
	}
	if(x != NULL and x->value != 0)
		return 1;
	else
		return 0;
}
bool isLeaf(trie_node *tn){
	return (tn->value != 0);
}
bool isFree(trie_node *tn){
	for(int i = 0 ; i < ALPHA_SIZE ; i++)
		if(tn->children[i] != NULL)
			return 0;
	return 1;
}
bool deletekey(trie_node *tn, char key[], int level, int length){
	if(tn != NULL){
		if(level == length){
			if(tn->value != 0){
				tn->value = 0;
				return isFree(tn);
			}
		}
		else{
			int index = key[level]-'a';
			if(deletekey(tn->children[index], key, level+1, length)){
				delete tn->children[index];
				tn->children[index] = NULL;
				return (!isLeaf(tn) and isFree(tn));
			}
		}
	}
	return false;
}
int main(){
	int size;
	char s[10];
	char key[][8] = {"she", "sells", "sea", "shore", "the", "by", "sheer"};
	char ans[][4] = {"no", "yes"};
	trie t;
	initialize(&t);
	size = sizeof(key) / sizeof(key[0]);
	for(int i = 0 ; i < size ; i++)
		insert(&t, key[i]);
	scanf("%s", s);
	printf("%s -- %s\n", s, ans[search(&t, s)]);
	if(s != NULL and strcmp(s, "") != 0){
		printf("deleting\n");
		deletekey(t.root, s, 0, strlen(s));
	}
	printf("%s -- %s\n", s, ans[search(&t, s)]);
	return 0;
}