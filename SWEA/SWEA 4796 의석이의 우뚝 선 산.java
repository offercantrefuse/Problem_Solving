import java.util.Scanner;

public class Solution4796 {

	static int T, N, ans;
	static long[] h;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			h = new long[N];
			for (int i = 0; i < N; i++) {
				h[i] = sc.nextLong();
			}
			int l = 0, r = N - 1;
			ans = 0;
			for (int i = 1; i < N - 1; i++) {
				long tmpl = h[i];
				long tmpr = h[i];
				int left = 0, right = 0;
				for (int j = i + 1; j <= r; j++) {
					if (h[j] < tmpr) {
						right++;
						tmpr = h[j];
					} else
						break;
				}
				if (right != 0) {
					for (int j = i - 1; j >= l; j--) {
						if (h[j] < tmpl) {
							left++;
							tmpl = h[j];
						} else
							break;
					}
					ans += left * right;
					if (right != 0) {
						l = i + right;
						i += right;
					}
				}
			}
			System.out.println("#" + tc + " " + ans);
		}
		sc.close();
	}

}
