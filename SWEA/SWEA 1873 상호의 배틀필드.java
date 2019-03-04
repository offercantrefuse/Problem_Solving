import java.util.Scanner;

public class Solution1873 {

	static int H, W, N, tr, tc, ts;
	static char[][] map;
	static char[] cmd;

	// 상태 : 0: 위, 1: 오른, 2: 아래, 3: 왼
	public static void move(int idx) {
		if (cmd[idx] == 'U') {
			ts = 0;
			map[tr][tc] ='^';
			// 맵 밖 이동 x
			if (tr - 1 < 0)
				return;
			if (map[tr - 1][tc] == '.') {
				map[tr][tc] = '.';
				map[tr - 1][tc] = '^';
				tr--;
			}
		} else if (cmd[idx] == 'D') {
			ts = 2;
			map[tr][tc] ='v';
			// 맵 밖 이동 x
			if (tr + 1 > H - 1)
				return;
			if (map[tr + 1][tc] == '.') {
				map[tr][tc] = '.';
				map[tr + 1][tc] = 'v';
				tr++;
			}
		} else if (cmd[idx] == 'L') {
			ts = 3;
			map[tr][tc] ='<';
			// 맵 밖 이동 x
			if (tc - 1 < 0)
				return;
			if (map[tr][tc - 1] == '.') {
				map[tr][tc] = '.';
				map[tr][tc - 1] = '<';
				tc--;
			}
		} else if (cmd[idx] == 'R') {
			ts = 1;
			map[tr][tc] ='>';
			// 맵 밖 이동 x
			if (tc + 1 > W - 1)
				return;
			if (map[tr][tc + 1] == '.') {
				map[tr][tc] = '.';
				map[tr][tc + 1] = '>';
				tc++;
			}
		} else if (cmd[idx] == 'S') {
			// 포탄 직진, 벽 부심
			if (ts == 0) { // U
				for (int i = tr - 1; i >= 0; i--) {
					if (map[i][tc] == '#')
						break;
					else if (map[i][tc] == '*') {
						map[i][tc] = '.';
						break;
					}
				}
			} else if (ts == 1) { // R
				for (int i = tc + 1; i <= W - 1; i++) {
					if (map[tr][i] == '#')
						break;
					else if (map[tr][i] == '*') {
						map[tr][i] = '.';
						break;
					}
				}
			} else if (ts == 2) { // D
				for (int i = tr + 1; i <= H - 1; i++) {
					if (map[i][tc] == '#')
						break;
					else if (map[i][tc] == '*') {
						map[i][tc] = '.';
						break;
					}
				}
			} else if (ts == 3) { // L
				for (int i = tc - 1; i >= 0; i--) {
					if (map[tr][i] == '#')
						break;
					else if (map[tr][i] == '*') {
						map[tr][i] = '.';
						break;
					}
				}
			}
		}

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tt = 1; tt <= T; tt++) {
			// 맵 입력
			H = sc.nextInt();
			W = sc.nextInt();
			map = new char[H][W];
			for (int i = 0; i < H; i++) {
				String tmp = sc.next();
				for (int j = 0; j < tmp.length(); j++) {
					map[i][j] = tmp.charAt(j);
					// 탱크 위치, 상태 : 0: 위, 1: 오른, 2: 아래, 3: 왼
					if (map[i][j] == '^' || map[i][j] == 'v' || map[i][j] == '<' || map[i][j] == '>') {
						tr = i;
						tc = j;
						if (map[i][j] == '^')
							ts = 0;
						else if (map[i][j] == '>')
							ts = 1;
						else if (map[i][j] == 'v')
							ts = 2;
						else if (map[i][j] == '<')
							ts = 3;
					}
				}
			}
			// 커맨드입력
			int N = sc.nextInt();
			cmd = new char[N];
			String tmp = sc.next();
			for (int j = 0; j < tmp.length(); j++) {
				cmd[j] = tmp.charAt(j);
			}

			for (int i = 0; i < N; i++) {
				move(i);
			}

			System.out.print("#" + tt + " ");
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					System.out.print(map[i][j]);
				}
				System.out.println();
			}
		}

	}

}
