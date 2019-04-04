import java.util.Scanner;

public class Solution5672 {

	static int T, N;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			String s = "", tmp;
			for (int i = 0; i < N; i++) {
				tmp = sc.next();
				s += tmp;
			}
			String ans = "";
			int pt1 = 0, pt2 = s.length() - 1;
			int cnt = 0;
			while (cnt < s.length()) {
				int tmp1 = s.charAt(pt1);
				int tmp2 = s.charAt(pt2);
				if (tmp1 < tmp2) {
					ans += (char) tmp1;
					pt1++;
				} else if (tmp1 == tmp2) {
					int lp = pt1 + 1, rp = pt2 - 1;
					while (rp - lp > 0) {
						if (s.charAt(lp) == s.charAt(rp)) {
							lp++;
							rp--;
							continue;
						} else if (s.charAt(lp) < s.charAt(rp)) {
							break;
						} else if (s.charAt(lp) > s.charAt(rp)) {
							break;
						}
					}
					if (s.charAt(lp) <= s.charAt(rp)) {
						ans += (char) tmp1;
						pt1++;
					} else if (s.charAt(lp) > s.charAt(rp)) {
						ans += (char) tmp2;
						pt2--;
					}
				} else {
					ans += (char) tmp2;
					pt2--;
				}
				cnt++;
			}
			System.out.println("#" + tc + " " + ans);
		}
		sc.close();
	}

}
