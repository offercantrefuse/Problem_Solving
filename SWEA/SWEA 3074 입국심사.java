import java.util.Scanner;

public class Solution3074 {

	static int T, N, M;
	static long ans;
	static long[] time;

	static long find(long num) {
		long sum = 0;
		for (int i = 1; i <= N; i++) {
			sum += num / time[i];
		}
		return sum;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			M = sc.nextInt();
			time = new long[N + 1];
			long maxVal = 0L;
			for (int i = 1; i <= N; i++) {
				time[i] = sc.nextLong();
				if (maxVal < time[i])
					maxVal = time[i];
			}
			long left = 1;
			long right = M * maxVal;
			while (left <= right) {
				long mid = (left + right) / 2;
				long tmp = find(mid);

				if (tmp < M) { // 작은쪽
					left = mid + 1;
				} else if (tmp >= M) { // 큰 쪽
					right = mid - 1;
				}
			}
			System.out.println("#" + tc + " " + left);
		}
		sc.close();
	}

}
