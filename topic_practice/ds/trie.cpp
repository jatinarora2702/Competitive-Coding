#include <bits/stdc++.h>
#define N 256
#define M 100
using namespace std;

/*
1 she 1
1 sells 2
1 sea 3
1 shore 4
1 the 5
1 by 6
1 sheer 7
1 shore 8
1 the 9
1 there 10
*/

typedef struct _trie{
	struct _trie *child[N];
	struct _trie *parent;
	vector < int > occurances;
}trie;

void tprint(trie *node, char c, int k) {
	int i;
	printf("%d: %c -> ", k, c);
	for(i = 0 ; i < N ; i++) {
		if(node->child[i] != NULL) {
			printf("%c ", i);
		}
	}
	printf("\n");
	for(i = 0 ; i < N ; i++) {
		if(node->child[i] != NULL) {
			tprint(node->child[i], i, k+1);
		}
	}
}

trie *tgetnode(trie *node, trie *p) {
	int i;
	if(node != NULL) {
		return node;
	}
	node = new trie();
	node->parent = p;
	for(i = 0 ; i < N ; i++) {
		node->child[i] = NULL;
	}
	node->occurances.clear();
	return node;
}

int tredundant(trie *node) {
	int i;
	if(node->occurances.size() > 0) {
		return 0;
	}
	for(i = 0 ; i < N ; i++) {
		if(node->child[i] != NULL) {
			return 0;
		}
	}
	return 1;
}

vector < int > tsearch(trie *node, char *s) {
	vector < int > vtemp;
	vtemp.clear();
	if(node == NULL) {
		return vtemp;
	}
	if(s[0] == '\0') {
		return node->occurances;
	}
	return tsearch(node->child[s[0]], s+1);
}

trie *tinsert(trie *node, char *s, int k) {
	if(s[0] == '\0') {
		node->occurances.push_back(k);
		return node;
	}
	node->child[s[0]] = tgetnode(node->child[s[0]], node);
	node->child[s[0]] = tinsert(node->child[s[0]], s+1, k);
	return node;
}

trie *tdelete(trie *node, char *s, int k) {
	int i;
	if(node == NULL) {
		return node;
	}
	if(s[0] == '\0') {
		vector < int > &v = node->occurances;
		for(i = 0 ; i < v.size() ; i++) {
			if(v[i] == k) {
				break;
			}
		}
		if(i < v.size()) {
			v.erase(v.begin() + i);
		}
		if(tredundant(node) && node->parent != NULL) {
			node->parent = NULL;
			delete(node);
			return NULL;
		}
		return node;
	}
	node->child[s[0]] = tdelete(node->child[s[0]], s+1, k);
	if(tredundant(node) && node->parent != NULL) {
		node->parent = NULL;
		delete(node);
		return NULL;
	}
	return node;
}

int main() {
	int i, k, pos;
	char s[M];
	trie *root;
	vector < int > occ;
	root = NULL;
	root = tgetnode(root, NULL);
	while(1) {
		scanf("%d", &k);
		switch(k) {
			case 1: 
				scanf("%s%d", s, &pos);
				tinsert(root, s, pos);
				tprint(root, '$', 1);
				break;
			case 2:
				scanf("%s%d", s, &pos);
				tdelete(root, s, pos);
				tprint(root, '$', 1);
				break;
			case 3:
				scanf("%s", s);
				occ = tsearch(root, s);
				if(occ.size() > 0) {
					printf("Found at: ");
					for(i = 0 ; i < occ.size() ; i++) {
						printf("%d ", occ[i]);
					}
					printf("\n");
				}
				else {
					printf("Not Found\n");
				}
				break;
		}
	}
	return 0;
}