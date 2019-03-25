import java.util.Scanner;

public class Jungol1077 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int W = sc.nextInt();
		int[][] jewelry = new int[N][2]; // 0: 무게, 1: 가치
		int[] dp = new int[W + 1];
		for (int i = 0; i < N; i++) {
			jewelry[i][0] = sc.nextInt();
			jewelry[i][1] = sc.nextInt();
		}
		for (int j = 0; j <= W; j++) {
			dp[j] = jewelry[0][1] * (j / jewelry[0][0]);
		}
		for (int i = 1; i < N; i++) {
			for (int j = 0; j <= W; j++) {
				if (j < jewelry[i][0])
					continue;
				if (j == jewelry[i][0]) {
					dp[j] = Math.max(jewelry[i][1], dp[j]);
				}
				dp[j] = Math.max(dp[jewelry[i][0]] + dp[j - jewelry[i][0]], dp[j]);
			}
		}
		System.out.println(dp[W]);
		sc.close();
	}

}