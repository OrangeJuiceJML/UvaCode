//#define LOCAL
#include<stdio.h>
#include<string.h>
#define maxn 20
char Map[maxn][maxn];

int main() {
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	int n = 0;	//������
	int f = 1;
	char* p[maxn*maxn];
	int r, c;
	while (scanf("%d", &r) == 1 && r != 0) {
		scanf("%d", &c);
		memset(Map, 0, sizeof(Map));	//ˢ������

		//��������
		char ch;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++) {
				if ((ch = getchar()) != '\n')
					Map[i][j] = ch;
				else
					Map[i][j] = getchar();
			}

		//����ʼ��
		int x = 0;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++) {
				if (Map[i][j] == '*')
					continue;
				else
					if (i == 1 || j == 1 || Map[i][j - 1] == '*' || Map[i - 1][j] == '*')
						p[x++] = &Map[i][j];
			}

		//��ӡ��ʼ��
		/*for (int i = 0; i < x; i++) {
			printf("%c ", *p[i]);
		}
		printf("\n");*/

		//��ʼ���
		if (f == 1) {
			printf("puzzle #%d:\n", ++n);
			f = 0;
		}
		else
			printf("\npuzzle #%d:\n", ++n);

		//�������
		printf("Across\n");
		for (int i = 0; i < x; i++) {
			char* pr = p[i];
			if (*(pr - sizeof(char)) == 0 || *(pr - sizeof(char)) == '*') {
				printf("%3d.", i + 1);
				while (*pr != 0 && *pr != '*') {
					printf("%c", *pr);
					pr += sizeof(char);
				}
				printf("\n");
			}
		}

		//�������
		printf("Down\n");
		for (int i = 0; i < x; i++) {
			char* pr = p[i];
			if (*(pr - sizeof(char)*20) == 0 || *(pr - sizeof(char)*20) == '*') {
				printf("%3d.", i + 1);
				while (*pr != 0 && *pr != '*') {
					printf("%c", *pr);
					pr += sizeof(char)*20;
				}
				printf("\n");
			}
		}
		
		//��ӡ����
		/*for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				printf("%c", Map[i][j]);
			}
			printf("\n");
		}*/
	}
	return 0;
}