import java.util.Arrays;
import java.util.Scanner;

public class Solution7208 {

	static int T, N, ans;
	static int[][] adjMat;
	static int[] country, comb;

	static boolean check() { // 인접국가 다른지 확인
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (adjMat[i][j] == 1 && comb[i] == comb[j]) {
					return false;
				}
			}
		}
		return true;
	}

	static int changeComb() { // 바꾼 개수
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (country[i] != comb[i])
				cnt++;
		}
		return cnt;
	}

	static void dfs(int idx) {
		if (idx == N+1) {
			if (check()) { // 되는지 확인
				int tmp = changeComb();
				ans = tmp < ans ? tmp : ans;
			}
			return;
		}
		for (int i = 1; i <= 4; i++) {
			comb[idx] = i;
			dfs(idx + 1);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			ans = Integer.MAX_VALUE;
			adjMat = new int[N + 1][N + 1];
			country = new int[N + 1];
			comb = new int[N + 1];
			Arrays.fill(comb, 1);
			for (int i = 1; i <= N; i++) {
				country[i] = sc.nextInt();
			}
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					adjMat[i][j] = sc.nextInt();
				}
			}
			dfs(1);
			System.out.println("#" + tc + " " + ans);
		}
		sc.close();
	}

}
