import java.util.Scanner;

public class BOJ1149 {

	static int N;
	static int[][] house, dp;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		house = new int[N][3];
		dp = new int[N][3];   // i번째에 j로 칠했을 때 최대값
		for(int i=0;i<N;i++) {
			house[i][0] = sc.nextInt();
			house[i][1] = sc.nextInt();
			house[i][2] = sc.nextInt();
		}
		dp[0][0] = house[0][0];
		dp[0][1] = house[0][1];
		dp[0][2] = house[0][2];
		for(int i=1;i<N;i++) {
			dp[i][0] = Math.min(dp[i-1][1]+house[i][0], dp[i-1][2]+house[i][0]);
			dp[i][1] = Math.min(dp[i-1][0]+house[i][1], dp[i-1][2]+house[i][1]);
			dp[i][2] = Math.min(dp[i-1][0]+house[i][2], dp[i-1][1]+house[i][2]);
		}
		System.out.println(Math.min(Math.min(dp[N-1][0], dp[N-1][1]),dp[N-1][2]));
		sc.close();
	}

}
