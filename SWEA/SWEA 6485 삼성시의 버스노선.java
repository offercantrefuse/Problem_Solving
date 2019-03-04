import java.util.Scanner;

public class Solution6485 {

	static int N, P;
	static int[] A, B;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			A = new int[N + 1];
			B = new int[N + 1];
			for (int i = 1; i <= N; i++) {
				A[i] = sc.nextInt();
				B[i] = sc.nextInt();
			}
			StringBuilder sb = new StringBuilder();
			P = sc.nextInt();
			for (int i = 0; i < P; i++) {
				int num = sc.nextInt();
				int cnt = 0;
				for (int j = 1; j <= N; j++) {
					if (num >= A[j] && num <= B[j]) {
						cnt++;
					}
				}
				sb.append(cnt + " ");
			}
			System.out.println("#" + tc + " " + sb.toString());
		}
		sc.close();
	}
}
