import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Solution1258 {

	static class Pos implements Comparable<Pos> {
		int r, c;

		Pos(int r, int c) {
			this.r = r;
			this.c = c;
		}

		Pos() {
		}

		@Override
		public int compareTo(Pos pos) {
			if ((this.r * this.c) > (pos.r * pos.c)) {
				return 1;
			} else if ((this.r * this.c) == (pos.r * pos.c)) {
				if (this.r > pos.r)
					return 1;
			}
			return -1;
		}

	}

	static int N, row, col;
	static int[][] map;
	static List<Pos> list;

	static void findMatrix(int r, int c) {
		row = 0;
		col = 0;
		int dr = 0, dc = 0;
		for (int i = r; i < N; i++) {
			if (map[i][c] == 0) {
				dr = i;
				break;
			}
			row++;
			if (i == N - 1)
				dr = N;
		}
		for (int j = c; j < N; j++) {
			if (map[r][j] == 0) {
				dc = j;
				break;
			}
			col++;
			if (j == N - 1)
				dc = N;
		}
		for (int i = r; i < dr; i++) {
			for (int j = c; j < dc; j++) {
				map[i][j] = 0;
			}
		}
		list.add(new Pos(row, col));
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			map = new int[N][N];
			list = new ArrayList<Pos>();
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			int num = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] != 0) {
						num++;
						findMatrix(i, j);
					}
				}
			}
			Pos[] arr = new Pos[list.size()];
			for (int i = 0; i < list.size(); i++) {
				arr[i] = list.get(i);
			}
			Arrays.sort(arr);
			System.out.print("#" + tc + " " + num);
			for (int i = 0; i < list.size(); i++) {
				System.out.print(" " + arr[i].r + " " + arr[i].c);
			}
			System.out.println();
		}
		sc.close();
	}

}
