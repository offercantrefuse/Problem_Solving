import java.util.Scanner;

public class Solution1865 {

	static int T, N;
	static double map[][];
	static int arr[];
	static boolean visit[];
	static double ans;

	static void dfs(int idx, double sum) {
		if (ans > sum)
			return;
		if (idx == N) {
			if (ans < sum)
				ans = sum;
			return;
		}
		for (int i = 0; i < N; i++) {
			if (!visit[i] && map[idx][i] != 0) {
				arr[idx] = i;
				visit[i] = true;
				dfs(idx + 1, sum * map[idx][arr[idx]]);
				visit[i] = false;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			map = new double[N][N];
			arr = new int[N];
			visit = new boolean[N];
			ans = 0.0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int tmp = sc.nextInt();
					map[i][j] = (double) tmp / 100;
				}
			}
			dfs(0, 1.0);
			System.out.printf("#" + tc + " %.6f\n", (ans * 100));
		}
		sc.close();
	}

}
