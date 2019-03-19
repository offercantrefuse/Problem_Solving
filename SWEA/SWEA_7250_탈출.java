import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution7250 {

	static class Node {
		int r, c;
		char who;

		Node(int r, int c, char who) {
			this.r = r;
			this.c = c;
			this.who = who;
		}
	}

	static class Node2 {
		int r, c, k;
		char who;

		Node2(int r, int c, int k, char who) {
			this.r = r;
			this.c = c;
			this.k = k;
			this.who = who;
		}
	}

	static int T, N, M, K, cnt;
	static boolean lose, win;
	static char[][] map;
	static boolean[][] visitV;
	static boolean[][][] visitS;

	static int dr[] = { -1, 0, 1, 0 };
	static int dc[] = { 0, -1, 0, 1 };
	static Queue<Node> qFire;
	static Queue<Node> qVillain;
	static Queue<Node2> qScott;

	static void moveFire() { // 불 그냥 이동
		int qSize = qFire.size();
		for (int t = 0; t < qSize; t++) {
			Node tmp = qFire.poll();
			int rr = tmp.r;
			int cc = tmp.c;
			char wwho = tmp.who;
			for (int d = 0; d < 4; d++) {
				int nr = rr + dr[d];
				int nc = cc + dc[d];
				if (nr < 0 || nc < 0 || nr > N - 1 || nc > M - 1)
					continue;
				if (map[nr][nc] == 'A' || map[nr][nc] == 'V' || map[nr][nc] == 'S') { // 통로, 악당, 스캇
					map[nr][nc] = 'F';
					qFire.offer(new Node(nr, nc, wwho));
				}
			}
		}
	}

	static void moveVillain() {
		int qSize = qVillain.size();
		for (int t = 0; t < qSize; t++) {
			Node tmp = qVillain.poll();
			int rr = tmp.r;
			int cc = tmp.c;
			char wwho = tmp.who;
			for (int d = 0; d < 4; d++) {
				int nr = rr + dr[d];
				int nc = cc + dc[d];
				if (nr < 0 || nc < 0 || nr > N - 1 || nc > M - 1)
					continue;
				if (!visitV[nr][nc]) {
					if (map[nr][nc] == 'A' || map[nr][nc] == 'F' || map[nr][nc] == 'S') { // 통로, 불, 스캇
						visitV[nr][nc] = true;
						qVillain.offer(new Node(nr, nc, wwho));
					} else if (map[nr][nc] == 'E') { // 탈출구
						lose = true;
					}
				}
			}
		}
	}

	static void moveScott() {
		int qSize = qScott.size();
		for (int t = 0; t < qSize; t++) {
			Node2 tmp = qScott.poll();
			int rr = tmp.r;
			int cc = tmp.c;
			int kk = tmp.k;
			char wwho = tmp.who;
			for (int d = 0; d < 4; d++) {
				int nr = rr + dr[d];
				int nc = cc + dc[d];
				if (nr < 0 || nc < 0 || nr > N - 1 || nc > M - 1)
					continue;
				if ((map[nr][nc] == 'A' || map[nr][nc] == 'V') && !visitS[nr][nc][K]) { // 통로 or 악당
					visitS[nr][nc][K] = true;
					qScott.offer(new Node2(nr, nc, K, wwho));
				} else if (map[nr][nc] == 'W' && !visitS[nr][nc][kk]) { // 통과 되는 벽
					if (kk > 0) {
						visitS[nr][nc][kk] = true;
						qScott.offer(new Node2(nr, nc, kk - 1, wwho));
					}
				} else if (map[nr][nc] == 'E') { // 탈출 성공
					win = true;
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			M = sc.nextInt();
			K = sc.nextInt();
			map = new char[N][M];
			visitV = new boolean[N][M];
			visitS = new boolean[N][M][K + 1];
			qFire = new LinkedList<Node>();
			qVillain = new LinkedList<Node>();
			qScott = new LinkedList<Node2>();
			for (int i = 0; i < N; i++) {
				String s;
				s = sc.next();
				for (int j = 0; j < M; j++) {
					map[i][j] = s.charAt(j);
					if (map[i][j] == 'S') {
						qScott.add(new Node2(i, j, K, 'S'));
						visitS[i][j][K] = true;
					} else if (map[i][j] == 'F') {
						qFire.add(new Node(i, j, 'F'));
					} else if (map[i][j] == 'V') {
						qVillain.add(new Node(i, j, 'V'));
						visitV[i][j] = true;
					}
				}
			}
			cnt = 0;
			lose = win = false;
			while (!lose && !win && !qScott.isEmpty()) {
				cnt++;
				moveFire();
				moveVillain();
				moveScott();
			}
			if (lose || !win)
				cnt = -1;
			System.out.println("#" + tc + " " + cnt);
		}
		sc.close();
	}

}
