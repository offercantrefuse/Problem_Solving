import java.util.Scanner;

public class Solution4613 {

	static int T, N, M, ans, sumW, sumR, sumB;
	static char map[][];

	static int count(int start, int finish) {
		int cnt = 0;
		for (int i = 0; i < start; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 'W')
					cnt++;
			}
		}
		for (int i = start; i <= finish; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 'B')
					cnt++;
			}
		}
		for (int i = finish + 1; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 'R')
					cnt++;
			}
		}
		return cnt;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		map = new char[N][M];
		for (int i = 0; i < N; i++) {
			String s = sc.next();
			for (int j = 0; j < M; j++) {
				map[i][j] = s.charAt(j);
			}
		}
		int sum = M * N;
		for (int i = 1; i < N - 1; i++) {
			for (int j = i; j < N - 1; j++) {
				int tmp = count(i, j);
				sum = sum < tmp ? sum : tmp;
			}
		}
		System.out.println(sum);
		sc.close();
	}

}
