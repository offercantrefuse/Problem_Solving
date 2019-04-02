import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution5656 {

	static class Pos {
		int r, c, num;

		Pos(int r, int c, int num) {
			this.r = r;
			this.c = c;
			this.num = num;
		}

		Pos() {
		}
	}

	static int T, N, W, H, ans;
	static int[] order;
	static int[][] map;
	static int[][] tmp;

	static int count() {
		int ct = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (tmp[i][j] != 0) {
					ct++;
				}
			}
		}
		return ct;
	}

	static void down() {
		for (int j = 0; j < W; j++) {
			ArrayList<Integer> arr = new ArrayList<Integer>();
			for (int i = H - 1; i >= 0; i--) {
				if (tmp[i][j] != 0) {
					arr.add(tmp[i][j]);
				}
			}
			int aSize = arr.size();
			int cnt = H - 1;
			for (int i = 0; i < aSize; i++) {
				tmp[cnt--][j] = arr.get(i);
			}
			while (cnt >= 0) {
				tmp[cnt--][j] = 0;
			}
		}
	}

	static void bomb(int r, int c) {
		Queue<Pos> q = new LinkedList<Pos>();
		q.offer(new Pos(r, c, tmp[r][c]));
		while (!q.isEmpty()) {
			Pos p = q.poll();
			int rr = p.r;
			int cc = p.c;
			int nnum = p.num;
			tmp[rr][cc] = 0;
			for (int j = 1; j <= nnum - 1; j++) { // left
				int nc = cc - j;
				if (nc < 0)
					break;
				if (tmp[rr][nc] == 1) {
					tmp[rr][nc] = 0;
				} else if (tmp[rr][nc] > 1) {
					q.offer(new Pos(rr, nc, tmp[rr][nc]));
					tmp[rr][nc] = 0;
				}
			}
			for (int j = 1; j <= nnum - 1; j++) { // right
				int nc = cc + j;
				if (nc > W - 1)
					break;
				if (tmp[rr][nc] == 1) {
					tmp[rr][nc] = 0;
				} else if (tmp[rr][nc] > 1) {
					q.offer(new Pos(rr, nc, tmp[rr][nc]));
					tmp[rr][nc] = 0;
				}
			}
			for (int i = 1; i <= nnum - 1; i++) { // down
				int nr = rr + i;
				if (nr > H - 1)
					break;
				if (tmp[nr][cc] == 1) {
					tmp[nr][cc] = 0;
				} else if (tmp[nr][cc] > 1) {
					q.offer(new Pos(nr, cc, tmp[nr][cc]));
					tmp[nr][cc] = 0;
				}
			}
			for (int i = 1; i <= nnum - 1; i++) { // up
				int nr = rr - i;
				if (nr < 0)
					break;
				if (tmp[nr][cc] == 1) {
					tmp[nr][cc] = 0;
				} else if (tmp[nr][cc] > 1) {
					q.offer(new Pos(nr, cc, tmp[nr][cc]));
					tmp[nr][cc] = 0;
				}
			}
		}
	}

	static void simul() {
		for (int k = 0; k < N; k++) {
			int col = order[k];
			for (int i = 0; i < H; i++) {
				if (tmp[i][col] != 0) {
					bomb(i, col);
					break;
				}
			}
			down();
		}
		int cnt = count();
		ans = ans > cnt ? cnt : ans;
	}

	static void mapCopy() {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				tmp[i][j] = map[i][j];
			}
		}
	}

	static void dfs(int idx) {
		if (idx == N) {
			mapCopy();
			simul();
			return;
		}
		for (int i = 0; i < W; i++) {
			order[idx] = i;
			dfs(idx + 1);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			W = sc.nextInt();
			H = sc.nextInt();
			map = new int[H][W];
			tmp = new int[H][W];
			order = new int[N];
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			ans = Integer.MAX_VALUE;
			dfs(0);
			System.out.println("#" + tc + " " + ans);
		}
		sc.close();
	}

}
