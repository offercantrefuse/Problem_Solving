import java.util.ArrayList;
import java.util.Scanner;

public class BOJ2636 {

	static class Pos {
		int r, c;

		Pos(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}

	static int R, C;
	static int[][] map, visit;
	static int dr[] = { -1, 0, 1, 0 };
	static int dc[] = { 0, -1, 0, 1 };
	static ArrayList<Pos> cheese = new ArrayList<Pos>();
	static ArrayList<Pos> n_cheese = new ArrayList<Pos>();

	static void color(int r, int c) {
		map[r][c] = 2;
		visit[r][c] = 1;
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nr > R - 1 || nc < 0 || nc > C - 1)
				continue;
			if (visit[nr][nc] == 0 && map[nr][nc] == 0) {
				color(nr, nc);
			}
		}
	}

	static boolean check(int idx) {
		int cnt = 0;
		int rr = cheese.get(idx).r;
		int cc = cheese.get(idx).c;
		for (int d = 0; d < 4; d++) {
			int nr = rr + dr[d];
			int nc = cc + dc[d];
			if (map[nr][nc] == 2)
				cnt++;
		}
		return cnt >= 1 ? true : false;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		R = sc.nextInt();
		C = sc.nextInt();
		map = new int[R][C];
		visit = new int[R][C];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				map[i][j] = sc.nextInt();
				if (map[i][j] == 1) {
					cheese.add(new Pos(i, j));
				}
			}
		}
		int time = 0;
		int tmp = 0;
		color(0, 0);
		while (!cheese.isEmpty()) {
			for (int i = 0; i < cheese.size(); i++) {
				if (check(i)) {
					map[cheese.get(i).r][cheese.get(i).c] = 0;
					n_cheese.add(cheese.get(i));
					cheese.remove(i);
					i--;
				}
			}
			tmp = n_cheese.size();
			while (!n_cheese.isEmpty()) {
				color(n_cheese.get(0).r, n_cheese.get(0).c);
				n_cheese.remove(0);
			}
			time++;
		}
		System.out.println(time + "\n" + tmp);
		sc.close();
	}

}
