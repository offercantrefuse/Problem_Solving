import java.util.Scanner;

public class BOJ3109 {

	static int R, C, ans;
	static boolean found;
	static char map[][];
	static boolean visit[][];
	static int dr[] = { -1, 0, 1 };

	static void go(int r, int c) {
		if (c == C - 1) {
			found = true;
			ans++;
			return;
		}
		for (int d = 0; d < 3; d++) {
			if (found)
				return;
			int nr = r + dr[d];
			int nc = c + 1;
			if (nr < 0 || nr > R - 1 || nc > C - 1)
				continue;
			if (map[nr][nc] == '.' && !visit[nr][nc]) {
				visit[nr][nc] = true;
				go(nr, nc);
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		R = sc.nextInt();
		C = sc.nextInt();
		map = new char[R][C];
		visit = new boolean[R][C];
		for (int i = 0; i < R; i++) {
			String s = sc.next();
			for (int j = 0; j < C; j++) {
				map[i][j] = s.charAt(j);
			}
		}
		ans = 0;
		for (int i = 0; i < R; i++) {
			found = false;
			for (int d = 0; d < 3; d++) {
				int nr = i + dr[d];
				if (nr < 0 || nr > R - 1)
					continue;
				if (map[nr][1] == '.' && !visit[nr][1]) {
					visit[nr][1] = true;
					go(nr, 1);
				}
			}
		}
		System.out.println(ans);
		sc.close();
	}

}
