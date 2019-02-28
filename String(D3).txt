#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int t, n, i, j;
	int cnt, same, length;
	char find[10];
	char text[1000];

	for (t = 1; t <= 10; t++) {

		find[0] = '\0';
		text[0] = '\0';
		
		same = 0;
		cnt = 0;
		length = 0;

		scanf("%d", &n);
		scanf("%s", find);
		scanf("%s", text);


		while (text[length] != '\0') {
			length++;
		}

		while (find[cnt] != '\0') {
			cnt++;
		}

		for (i = 0; i < length; i++) {
			if (text[i] == find[0]) {
				for (j = 1; j < cnt; j++) {
					if (text[i + j] != find[j]) {
						break;
					}
					if (j == cnt - 1)
						same++;
				}
			}
		}
		printf("#%d %d\n", n, same);
	}
	return 0;
}