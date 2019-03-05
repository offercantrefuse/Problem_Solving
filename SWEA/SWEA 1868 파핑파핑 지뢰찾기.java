import java.util.Scanner;

public class Solution1868 {

	static int N, ans;
	static char[][] map;
	static boolean[][] visit;
	static int[] dr = { -1, -1, 0, 1, 1, 1, 0, -1 };
	static int[] dc = { 0, 1, 1, 1, 0, -1, -1, -1 };

	static void dfs(int r, int c) {
		visit[r][c] = true;
		for (int d = 0; d < 8; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nc < 0 || nr > N - 1 || nc > N - 1)
				continue;
			if (!visit[nr][nc] && map[nr][nc] != '*') {
				if (map[nr][nc] == '0') {
					visit[nr][nc] = true;
					dfs(nr, nc);
				} else { // 숫자면
					visit[nr][nc] = true;
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			map = new char[N][N];
			visit = new boolean[N][N];
			for (int i = 0; i < N; i++) {
				String tmp = sc.next();
				for (int j = 0; j < tmp.length(); j++) {
					map[i][j] = tmp.charAt(j);
				}
			}

			// map에 수 표시
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] == '.') {
						int cnt = 0;
						for (int d = 0; d < 8; d++) {
							int ni = i + dr[d];
							int nj = j + dc[d];
							if (ni < 0 || nj < 0 || ni > N - 1 || nj > N - 1)
								continue;
							if (map[ni][nj] == '*')
								cnt++;
						}
						map[i][j] = (char) (cnt + '0');
					}
				}
			}

			ans = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] == '0' && !visit[i][j]) {
						dfs(i, j);
						ans++;
					}
				}
			}
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					if (!visit[i][j] && map[i][j] != '0' && map[i][j] != '*')
						ans++;

			System.out.println("#" + tc + " " + ans);
			sc.close();
		}
	}

}
