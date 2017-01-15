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
	trie_node *tn = new trie_node;
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
	int level, length, index;
	trie_node *x;
	length = strlen(key);
	t->count++;
	x = t->root;
	for(level = 0 ; level < length ; level++){
		index = (int)(key[level] - 'a');
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
		index = (int)(key[level] - 'a');
		if(x->children[index] == NULL)
			return 0;
		x = x->children[index];
	}
	if(x != NULL and x->value != 0)
		return 1;
	else
		return 0;
}
int main(){
	int length;
	char keys[][8] = {"the", "a", "through", "answer", "any", "by", "bye", "their"};
	trie t;
	char ans[][4] = {"no", "yes"};
	initialize(&t);
	length = sizeof(keys) / sizeof(keys[0]);
	for(int i = 0 ; i < length ; i++){
		insert(&t, keys[i]);
	}
	printf("%s -- %s\n", "the", ans[search(&t, (char*)"the")]);
	printf("%s -- %s\n", "these", ans[search(&t, (char*)"these")]);
	printf("%s -- %s\n", "their", ans[search(&t, (char*)"their")]);
	printf("%s -- %s\n", "thaw", ans[search(&t, (char*)"thaw")]);
	return 0;
}