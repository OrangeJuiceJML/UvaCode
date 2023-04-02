#include<stdio.h>
#define maxn 1050
#define maxm 55
char DNA[maxm][maxn];
char Best[maxn];

int max(int a, int b) {	//ȡ���ֵ
	if (a > b)
		return a;
	return b;
}

char MaxCh(int t, int a, int g, int c) {	//������λ�����ַ�����ͬ���ֵ���ACGT��
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
	int K;	//����������ѭ��������
	scanf("%d", &K);
	while (K--) {
		int m, n;
		char c;
		scanf("%d%d", &m, &n);
		//����DNA
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if ((c = getchar()) != '\n')
					DNA[i][j] = c;
				else
					DNA[i][j] = getchar();
			}
		//��ӡDNA
		/*printf("-------------------------\n");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				putchar(DNA[i][j]);
			}
			printf("\n");
		}
		printf("-------------------------\n");*/
		//�������ŽⲢ���
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
		//����Hamming���벢���
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