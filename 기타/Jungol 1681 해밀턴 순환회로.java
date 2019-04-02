import java.util.Scanner;

public class Jungol1681 {

	static int N, ans;
	static boolean visit[];
	static int[] route;
	static int[][] adj;

	static void dfs(int idx, int ss, int now) {
		if (ans < ss)
			return;
		if (idx == N - 1) {
			int sum = ss + adj[route[N - 2]][1];
			if (ans > sum)
				ans = sum;
			return;
		}
		for (int i = 2; i <= N; i++) {
			if (!visit[i]) {
				visit[i] = true;
				route[idx] = i;
				dfs(idx + 1, ss + adj[now][i], i);
				visit[i] = false;
			}

		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		adj = new int[N + 1][N + 1];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				adj[i][j] = sc.nextInt();
				if (adj[i][j] == 0)
					adj[i][j] = 1201;
			}
		}
		visit = new boolean[N + 1];
		route = new int[N + 1];
		ans = Integer.MAX_VALUE;
		for (int i = 2; i <= N; i++) {
			visit[i] = true;
			dfs(1, adj[1][i], i);
			visit[i] = false;
		}
		System.out.println(ans);
		sc.close();
	}

}
