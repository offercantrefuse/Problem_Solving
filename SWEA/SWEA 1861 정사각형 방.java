package com.ssafy.test;

import java.util.Scanner;

public class Solution1861 {

	static int T, N, maxi, now;
	static int dr[] = { -1, 0, 1, 0 };
	static int dc[] = { 0, -1, 0, 1 };
	static int[][] map;

	static int find(int r, int c) {
		int tmpr = r;
		int tmpc = c;
		int cnt = 1;
		if (N * N - map[r][c] < maxi)
			return 0;
		while (true) {
			boolean found = false;
			for (int d = 0; d < 4; d++) {
				int nr = tmpr + dr[d];
				int nc = tmpc + dc[d];
				if (nr < 0 || nc < 0 || nr > N - 1 || nc > N - 1)
					continue;
				if (map[nr][nc] == map[tmpr][tmpc] + 1) {
					tmpr = nr;
					tmpc = nc;
					cnt++;
					found = true;
					break;
				}
			}
			if (!found)
				break;
		}
		return cnt;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			map = new int[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			maxi = 0;
			now = N * N + 1;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int tmp = find(i, j);
					if (maxi < tmp) {
						maxi = tmp;
						now = map[i][j];
					} else if (maxi == tmp) {
						if (map[i][j] < now) {
							maxi = tmp;
							now = map[i][j];
						}
					}
				}
			}
			System.out.println("#" + tc + " " + now + " " + maxi);
		}
		sc.close();
	}

}
