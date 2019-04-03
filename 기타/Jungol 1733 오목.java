import java.util.Scanner;

public class Jungol1733 {

	static int ansR, ansC;
	static int[][] map;
	static boolean win1, win2;

	static void find(int r, int c, int al) {
		int cnt1 = 0, cnt2 = 0;
		int tmp;
		// 세로
		for (int i = r + 1; i < 19; i++) {
			if (map[i][c] == al)
				cnt2++;
			else
				break;
		}
		for (int i = r - 1; i >= 0; i--) {
			if (map[i][c] == al)
				cnt1++;
			else
				break;
		}
		if (cnt2 + cnt1 + 1 == 5) { // 세로오목
			if (al == 1) {
				win1 = true;
				ansR = r - cnt1;
				ansC = c;
				return;
			} else {
				win2 = true;
				ansR = r - cnt1;
				ansC = c;
				return;
			}
		}
		// 가로
		cnt1 = cnt2 = 0;
		for (int j = c + 1; j < 19; j++) {
			if (map[r][j] == al)
				cnt2++;
			else
				break;
		}
		for (int j = c - 1; j >= 0; j--) {
			if (map[r][j] == al)
				cnt1++;
			else
				break;
		}
		if (cnt2 + cnt1 + 1 == 5) { // 가로오목
			if (al == 1) {
				win1 = true;
				ansR = r;
				ansC = c - cnt1;
				return;
			} else {
				win2 = true;
				ansR = r;
				ansC = c - cnt1;
				return;
			}
		}
		// 왼 대각
		cnt1 = cnt2 = 0;
		tmp = Math.min(r, c);
		for (int j = 1; j <= tmp; j++) { // 왼위
			if (map[r - j][c - j] == al)
				cnt2++;
			else
				break;
		}
		tmp = Math.min(18 - r, 18 - c);
		for (int j = 1; j <= tmp; j++) { // 오아래
			if (map[r + j][c + j] == al)
				cnt1++;
			else
				break;
		}
		if (cnt2 + cnt1 + 1 == 5) { // 왼대각 오목
			if (al == 1) {
				win1 = true;
				ansR = r - cnt2;
				ansC = c - cnt2;
				return;
			} else {
				win2 = true;
				ansR = r - cnt2;
				ansC = c - cnt2;
				return;
			}
		}
		// 오 대각
		cnt1 = cnt2 = 0;
		tmp = Math.min(r, 18 - c);
		for (int j = 1; j <= tmp; j++) { // 오위
			if (map[r - j][c + j] == al)
				cnt2++;
			else
				break;
		}
		tmp = Math.min(18 - r, c);
		for (int j = 1; j <= tmp; j++) { // 왼아래
			if (map[r + j][c - j] == al)
				cnt1++;
			else
				break;
		}
		if (cnt2 + cnt1 + 1 == 5) { // 오대각 오목
			if (al == 1) {
				win1 = true;
				ansR = r + cnt1;
				ansC = c - cnt1;
				return;
			} else {
				win2 = true;
				ansR = r + cnt1;
				ansC = c - cnt1;
				return;
			}
		}

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		map = new int[19][19];
		win1 = false;
		win2 = false;
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		for (int i = 0; i < 19 && !win1 && !win2; i++) {
			for (int j = 0; j < 19 && !win1 && !win2; j++) {
				if (map[i][j] == 1) {
					find(i, j, 1);
				} else if (map[i][j] == 2) {
					find(i, j, 2);
				}
			}
		}
		if (win1) {
			System.out.println("1");
			System.out.println((ansR + 1) + " " + (ansC + 1));
		} else if (win2) {
			System.out.println("2");
			System.out.println((ansR + 1) + " " + (ansC + 1));
		} else {
			System.out.println("0");
		}

		sc.close();
	}

}
