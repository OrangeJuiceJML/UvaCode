#include<stdio.h>
#include<string.h>

int main() {
	int Round;
	while (scanf("%d", &Round) == 1 && Round != -1) {
		char Word[100];
		char Guess[100];
		int word[26];
		int guess[26];
		int F = 0;
		int OK = 0;
		memset(word, 0, sizeof(word));
		memset(guess, 0, sizeof(guess));
		//输入目标单词和玩家猜想
		scanf("%s%s", Word, Guess);
		//读取目标单词中各字母出现情况
		for (int i = 0; i < strlen(Word); i++)
			word[Word[i] - 'a'] = 1;
		//读取玩家猜想中各字母出现情况
		for (int i = 0; i < strlen(Guess); i++) {
			if (guess[Guess[i] - 'a'] == 0) {
				guess[Guess[i] - 'a'] = 1;
				//猜错
				if (word[Guess[i] - 'a'] == 0)
					F++;
			}
			//猜重
			else
				F++;
			//判断错误次数
			if (F > 6) {
				printf("Round %d\nYou lose.\n", Round);
				break;
			}
			//判断是否猜全
			OK = 0;
			for (int j = 0; j < 26; j++) {
				if (guess[j] - word[j] >= 0)
					OK++;
			}
			if (OK == 26) {
				printf("Round %d\nYou win.\n", Round);
				break;
			}
		}
		//已放弃
		if (F <= 6 && OK < 26)
			printf("Round %d\nYou chickened out.\n", Round);
	}
	return 0;
}