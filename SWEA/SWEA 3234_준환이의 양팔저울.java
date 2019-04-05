import java.util.Scanner;

public class Solution3234 {

	static int T, N, left, right, ans;
	static int[] ball, arr;
	static boolean visit[];

	static void dfs2(int idx, int left, int right) {
		if (left < right) {
			return;
		}
		if (idx == N) {
			ans++;
			return;
		}
		// 0: left, 1: right
		dfs2(idx + 1, left + ball[arr[idx]], right);
		dfs2(idx + 1, left, right + ball[arr[idx]]);
	}

	static void dfs(int idx) {
		if (idx == N) {
			dfs2(0, 0, 0);
			return;
		}
		for (int i = 0; i < N; i++) {
			if (!visit[i]) {
				visit[i] = true;
				arr[idx] = i;
				dfs(idx + 1);
				visit[i] = false;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			ball = new int[N];
			arr = new int[N];
			visit = new boolean[N];
			for (int i = 0; i < N; i++) {
				ball[i] = sc.nextInt();
			}
			ans = left = right = 0;
			dfs(0);
			System.out.println("#" + tc + " " + ans);
		}

		sc.close();
	}

}
