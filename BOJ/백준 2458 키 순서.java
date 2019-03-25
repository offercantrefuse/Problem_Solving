import java.util.Arrays;
import java.util.Scanner;

public class BOJ2458 {

	static int N, M, cnt1, cnt2, ans = 0;
	static int[][] adj;
	static boolean[] visit;

	static void findBig(int idx) {
		visit[idx] = true;
		for (int i = 1; i <= N; i++) {
			if (!visit[i] && adj[idx][i] == -1) {
				cnt1++;
				findBig(i);
			}
		}
	}

	static void findSmall(int idx) {
		visit[idx] = true;
		for (int i = 1; i <= N; i++) {
			if (!visit[i] && adj[idx][i] == 1) {
				cnt2++;
				findSmall(i);
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		adj = new int[N + 1][N + 1];
		visit = new boolean[N + 1];
		for (int i = 0; i < M; i++) {
			int tmp1 = sc.nextInt();
			int tmp2 = sc.nextInt();
			adj[tmp1][tmp2] = -1; // tmp1 < tmp2
			adj[tmp2][tmp1] = 1;
		}

		for (int i = 1; i <= N; i++) {
			Arrays.fill(visit, false);
			cnt1 = cnt2 = 0;
			findBig(i);
			findSmall(i);
			if (cnt1 + cnt2 == N - 1)
				ans++;
		}
		System.out.println(ans);
		sc.close();
	}

}
