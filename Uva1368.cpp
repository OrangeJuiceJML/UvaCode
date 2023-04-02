#include<stdio.h>
#define maxn 1050
#define maxm 55
char DNA[maxm][maxn];
char Best[maxn];

int max(int a, int b) {	//取最大值
	if (a > b)
		return a;
	return b;
}

char MaxCh(int t, int a, int g, int c) {	//给出该位最优字符（相同按字典序ACGT）
	int MAX = max(max(t, a), max(g, c));
	if (a == MAX)
		return 'A';
	if (c == MAX)
		return 'C';
	if (g == MAX)
		return 'G';
	if (t == MAX)
		return 'T';
}

int main() {
	int K;	//总数据量（循环次数）
	scanf("%d", &K);
	while (K--) {
		int m, n;
		char c;
		scanf("%d%d", &m, &n);
		//读入DNA
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if ((c = getchar()) != '\n')
					DNA[i][j] = c;
				else
					DNA[i][j] = getchar();
			}
		//打印DNA
		/*printf("-------------------------\n");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				putchar(DNA[i][j]);
			}
			printf("\n");
		}
		printf("-------------------------\n");*/
		//计算最优解并输出
		for (int i = 0; i < n; i++) {
			int T = 0, A = 0, G = 0, C = 0;
			for (int j = 0; j < m; j++) {
				if (DNA[j][i] == 'T')
					T++;
				if (DNA[j][i] == 'A')
					A++;
				if (DNA[j][i] == 'G')
					G++;
				if (DNA[j][i] == 'C')
					C++;
			}
			Best[i] = MaxCh(T, A, G, C);
			printf("%c", Best[i]);
		}
		printf("\n");
		//计算Hamming距离并输出
		int Ham = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (DNA[j][i] != Best[i])
					Ham++;
			}
		}
		printf("%d\n", Ham);
	}
	return 0;
}