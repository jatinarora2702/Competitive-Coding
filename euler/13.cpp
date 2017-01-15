#include <stdio.h>
#include <malloc.h>

void init(char *s, int d) {
	int i;
	for(i = 0 ; i < d ; i++) {
		s[i] = '0';
	}
	s[d] = '\0';
}

int digadd(int a, int b, int *pc) {
	int k = a + b + *pc;
	int old= *pc;
	*pc = (k > 9) ? (k%100)/10 : 0;
	printf("a = %d | b = %d | c = %d | s = %d | c = %d\n", a, b, old, (k%10), *pc);
	return (k%10);
}

void add(char *s, char *a, int d) {
	int i, m, c;
	printf("a=[%s]\n", a);
	for(m = 0 ; a[m] != '\0' ; m++);	
	c = 0;
	for(i = 0 ; i < d ; i++) {
		s[d-i-1] = digadd(s[d-i-1]-'0', a[m-i-1]-'0', &c) + '0';
	}
}

int main() {
	int d, dmax, n, i;
	char *a, *s;
	scanf("%d%d%d", &n, &d, &dmax);
	a = (char*)malloc((dmax+1)*sizeof(char));
	s = (char*)malloc((d+1)*sizeof(char));
	init(s, d);
	printf("[%s]\n", s);
	for(i = 0 ; i < n ; i++) {
		scanf("%s", a);
		add(s, a, d);
	}
	printf("%s\n", s);
	return 0;
}