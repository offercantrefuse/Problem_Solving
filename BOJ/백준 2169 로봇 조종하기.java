import java.util.Scanner;

public class Main {

	final static int INF = -1000000001;
	static int N, M;
	static int map[][];
	static int dp[][][];

	static int max3(int a, int b, int c) {
		return Math.max(Math.max(a, b), c);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		map = new int[N + 2][M + 2];
		dp = new int[3][N + 2][M + 2];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		// dp[0~2][i][j] : (i,j)로 0~2 방향에서 올 수 있는 경로 중 최대값
		// 0: 왼, 1: 오, 2: 위

		dp[0][1][1] = map[1][1];
		for (int j = 1; j <= M; j++)
			dp[2][1][j] = INF;
		for (int j = 2; j <= M; j++)
			dp[0][1][j] = dp[0][1][j - 1] + map[1][j];
		for (int j = M; j >= 1; j--)
			dp[1][1][j] = INF;

		for (int i = 2; i <= N; i++) { // 2 -> 0 -> 1
			for (int j = 1; j <= M; j++) { // 2: 위
				dp[2][i][j] = max3(dp[0][i - 1][j], dp[1][i - 1][j], dp[2][i - 1][j]) + map[i][j];
			}
			for (int j = 1; j <= M; j++) { // 0: 왼
				if (j == 1) {
					dp[0][i][j] = INF;
					continue;
				}
				dp[0][i][j] = Math.max(dp[2][i][j - 1], dp[0][i][j - 1]) + map[i][j];
			}
			for (int j = M; j >= 1; j--) { // 1: 오
				if (j == M) {
					dp[1][i][j] = INF;
					continue;
				}
				dp[1][i][j] = Math.max(dp[1][i][j + 1], dp[2][i][j + 1]) + map[i][j];
			}
		}
		System.out.println(max3(dp[0][N][M], dp[1][N][M], dp[2][N][M]));
		sc.close();
	}
}
