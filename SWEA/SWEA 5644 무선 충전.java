import java.util.ArrayList;
import java.util.Scanner;

public class SWEA5644 {

	static class Node {
		int r, c, range, perform;

		Node(int r, int c, int range, int perform) {
			this.r = r;
			this.c = c;
			this.range = range;
			this.perform = perform;
		}

		Node() {
		}
	}

	static int T, M, A, ans;
	static int[] cmd1, cmd2;
	static int[] use = new int[2];
	static Node[] BC;
	static int[] dr = { 0, -1, 0, 1, 0 };
	static int[] dc = { 0, 0, 1, 0, -1 };

	static boolean inDist(int r, int c, int rr, int cc, int range) {
		if (Math.abs(r - rr) + Math.abs(c - cc) <= range)
			return true;
		return false;
	}

	static void simul(int r1, int c1, int r2, int c2) {
		ArrayList<Integer> can1 = new ArrayList<Integer>();
		ArrayList<Integer> can2 = new ArrayList<Integer>();
		// BC 탐색
		can1.add(0);
		can2.add(0);
		for (int i = 1; i <= A; i++) {
			if (inDist(r1, c1, BC[i].r, BC[i].c, BC[i].range)) {
				can1.add(i);
			}
			if (inDist(r2, c2, BC[i].r, BC[i].c, BC[i].range)) {
				can2.add(i);
			}
		}
		// canUse에서 최대값 비교
		int maxi = 0;
		for (int i = 0; i < can1.size(); i++) {
			for (int j = 0; j < can2.size(); j++) {
				use[0] = can1.get(i);
				use[1] = can2.get(j);
				if (use[0] == use[1]) {
					if (maxi < BC[use[0]].perform)
						maxi = BC[use[0]].perform;
				} else {
					if (maxi < BC[use[0]].perform + BC[use[1]].perform)
						maxi = BC[use[0]].perform + BC[use[1]].perform;
				}
			}
		}
		// ans 갱신
		ans += maxi;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			M = sc.nextInt();
			A = sc.nextInt();
			cmd1 = new int[M];
			cmd2 = new int[M];
			BC = new Node[A + 1];
			for (int i = 0; i < M; i++)
				cmd1[i] = sc.nextInt();
			for (int i = 0; i < M; i++)
				cmd2[i] = sc.nextInt();

			for (int i = 1; i <= A; i++) {
				int tmp1 = sc.nextInt();
				int tmp2 = sc.nextInt();
				int tmp3 = sc.nextInt();
				int tmp4 = sc.nextInt();
				BC[i] = new Node(tmp2, tmp1, tmp3, tmp4);
			}
			BC[0] = new Node(0, 0, 0, 0);
			ans = 0;
			int r1 = 1, c1 = 1, r2 = 10, c2 = 10;
			simul(r1, c1, r2, c2);
			for (int i = 0; i < M; i++) {
				r1 = r1 + dr[cmd1[i]];
				c1 = c1 + dc[cmd1[i]];
				r2 = r2 + dr[cmd2[i]];
				c2 = c2 + dc[cmd2[i]];
				simul(r1, c1, r2, c2);
			}
			System.out.println("#" + tc + " " + ans);
		}

		sc.close();
	}

}
