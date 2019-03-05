import java.util.Arrays;
import java.util.Scanner;

public class BOJ8983 {

	static class Pos implements Comparable<Pos> {
		int x, y;

		public Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Pos o) {
			if (this.x > o.x)
				return 1; // 오름차순?
			else if (this.x == o.x) {
				if (this.y > o.y)
					return 1;
			}
			return -1;
		}
	}

	static int M, N, L, ans;
	static Pos[] saro, animal;

	static boolean dist(int aidx, int sidx) {
		if (Math.abs(animal[aidx].x - saro[sidx].x) + animal[aidx].y <= L)
			return true;
		return false;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		M = sc.nextInt();
		N = sc.nextInt();
		L = sc.nextInt();
		saro = new Pos[M];
		animal = new Pos[N];
		for (int i = 0; i < M; i++) {
			int tmp = sc.nextInt();
			saro[i] = new Pos(tmp, 0);
		}
		for (int i = 0; i < N; i++) {
			int tmp1 = sc.nextInt();
			int tmp2 = sc.nextInt();
			animal[i] = new Pos(tmp1, tmp2);
		}
		Arrays.sort(saro);
		Arrays.sort(animal);

		ans = 0;
		int cmp = 0;
		for (int i = 0; i < N; i++) {
			if (cmp == M - 1) {
				if (cmp == 0) {
					if (dist(i, cmp)) {
						ans++;
					}
				} else if (dist(i, cmp - 1) || dist(i, cmp))
					ans++;
			} else if (animal[i].x < saro[cmp].x) {
				if (cmp == 0) {
					if (dist(i, cmp)) {
						ans++;
					}
					continue;
				}
				if (dist(i, cmp - 1) || dist(i, cmp))
					ans++;
			} else if (animal[i].x >= saro[cmp].x) {
				i--;
				cmp++;
			}
		}
		System.out.println(ans);
		sc.close();
	}

}
