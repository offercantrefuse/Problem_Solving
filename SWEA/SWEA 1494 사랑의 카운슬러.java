import java.util.Arrays;
import java.util.Scanner;

public class SWEA1494 {

	static class Worm {
		long x, y;

		public Worm(long x, long y) {
			this.x = x;
			this.y = y;
		}
	}

	static int T, N;
	static long mini;
	static Worm[] worm;
	static int[] visit;

	static void dfs(int idx, int cnt) {
		if (cnt == N / 2) {
			long sumx = 0, sumy = 0;
			for (int i = 0; i < N; i++) {
				if (visit[i] == 0) {
					sumx += worm[i].x;
					sumy += worm[i].y;
				} else {
					sumx -= worm[i].x;
					sumy -= worm[i].y;
				}
			}
			long tmp = sumx * sumx + sumy * sumy;
			mini = mini > tmp ? tmp : mini;
			return;
		}

		for (int i = idx; i < N; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				dfs(i + 1, cnt + 1);
				visit[i] = 0;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			worm = new Worm[N];
			visit = new int[N];
			Arrays.fill(visit, 0);
			mini = Long.MAX_VALUE;
			for (int i = 0; i < N; i++) {
				int tmpx = sc.nextInt();
				int tmpy = sc.nextInt();
				worm[i] = new Worm(tmpx, tmpy);
			}
			dfs(0, 0);
			System.out.println("#" + tc + " " + mini);
		}
		sc.close();
	}

}
