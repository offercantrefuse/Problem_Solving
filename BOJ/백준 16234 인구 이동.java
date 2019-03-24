import java.util.Arrays;
import java.util.Scanner;

public class Main {

	static int N, L, R, flag, num;
	static int[][] map;
	static int[][] visit;
	static int[] sum; // 연합들의 인구수 합
	static int[] cnt; // 연합 수
	static int[] dr = { -1, 0, 1, 0 };
	static int[] dc = { 0, -1, 0, 1 };

	static void dfs(int r, int c) {
		visit[r][c] = num;
		sum[num] += map[r][c];
		cnt[num]++;
		// 섬 번호 매기기
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nc < 0 || nr > N - 1 || nc > N - 1)
				continue;
			if (visit[nr][nc] == 0
					&& (Math.abs(map[r][c] - map[nr][nc]) >= L && Math.abs(map[r][c] - map[nr][nc]) <= R)) {
				dfs(nr, nc);
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		L = sc.nextInt();
		R = sc.nextInt();
		map = new int[N][N];
		visit = new int[N][N];
		sum = new int[N * N + 1];
		cnt = new int[N * N + 1];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		int moveCnt = 0;
		while (flag != 1) {
			// 초기화
			flag = 0;
			num = 1;
			Arrays.fill(sum, 0);
			Arrays.fill(cnt, 0);
			for (int i = 0; i < N; i++)
				Arrays.fill(visit[i], 0);
			// 나라 번호들 visit에 입히기
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (visit[i][j] == 0) {
						dfs(i, j);
						if (flag < cnt[num]) // 섬의 개수 최대값 (1이면 연합 발생 x)
							flag = cnt[num];
						num++;
					}
				}
			}
			if (flag != 1) { // 연합 발생 했을 때
				// visit 돌면서 인구이동 해주기
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						map[i][j] = sum[visit[i][j]] / cnt[visit[i][j]];
					}
				}
				moveCnt++;
			}
		}
		System.out.println(moveCnt);
		sc.close();
	}
}
