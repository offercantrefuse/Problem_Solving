package com.ssafy.test;

import java.util.Scanner;

public class Solution7236 {

	static int T, N, ans;
	static char[][] map;
	static int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	static int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

	static int find(int r, int c) {
		int count = 0;
		for (int d = 0; d < 8; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nc < 0 || nr > N - 1 || nc > N - 1)
				continue;
			if (map[nr][nc] == 'W') {
				count++;
			}
		}
		if (count == 0)
			return 1;
		else
			return count;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			map = new char[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.next().charAt(0);
				}
			}
			ans = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int tmp = find(i, j);
					ans = ans < tmp ? tmp : ans;
				}
			}
			System.out.println("#" + tc + " " + ans);
		}
		sc.close();
	}

}
