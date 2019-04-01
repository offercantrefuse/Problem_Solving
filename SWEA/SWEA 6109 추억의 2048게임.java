import java.util.LinkedList;
import java.util.Scanner;

public class Solution6109 {

	static int T, N;
	static int map[][];

	static void moveUp(int c) {
		LinkedList<Integer> arr = new LinkedList<Integer>();
		for (int i = 0; i < N; i++) {
			if (map[i][c] != 0) {
				arr.add(map[i][c]);
			}
		}
		int cnt = 0;
		int aSize = arr.size();
		for (int i = 0; i < aSize; i++) {
			int tmp = arr.get(i);
			if (i < arr.size() - 1 && tmp == arr.get(i + 1)) {
				map[cnt++][c] = tmp * 2;
				i++;
			} else {
				map[cnt++][c] = tmp;
			}
		}
		for (int i = cnt; i < N; i++) {
			map[i][c] = 0;
		}
	}

	static void moveDown(int c) {
		LinkedList<Integer> arr = new LinkedList<Integer>();
		for (int i = N - 1; i >= 0; i--) {
			if (map[i][c] != 0) {
				arr.add(map[i][c]);
			}
		}
		int cnt = N - 1;
		int aSize = arr.size();
		for (int i = 0; i < aSize; i++) {
			int tmp = arr.get(i);
			if (i < arr.size() - 1 && tmp == arr.get(i + 1)) {
				map[cnt--][c] = tmp * 2;
				i++;
			} else {
				map[cnt--][c] = arr.get(i);
			}
		}
		for (int i = cnt; i >= 0; i--) {
			map[i][c] = 0;
		}
	}

	static void moveLeft(int r) {
		LinkedList<Integer> arr = new LinkedList<Integer>();
		for (int j = 0; j < N; j++) {
			if (map[r][j] != 0) {
				arr.add(map[r][j]);
			}
		}
		int cnt = 0;
		int aSize = arr.size();
		for (int i = 0; i < aSize; i++) {
			int tmp = arr.get(i);
			if (i < arr.size() - 1 && tmp == arr.get(i + 1)) {
				map[r][cnt++] = tmp * 2;
				i++;
			} else {
				map[r][cnt++] = arr.get(i);
			}
		}
		for (int j = cnt; j < N; j++) {
			map[r][j] = 0;
		}
	}

	static void moveRight(int r) {
		LinkedList<Integer> arr = new LinkedList<Integer>();
		for (int j = N - 1; j >= 0; j--) {
			if (map[r][j] != 0) {
				arr.add(map[r][j]);
			}
		}
		int cnt = N - 1;
		int aSize = arr.size();
		for (int i = 0; i < aSize; i++) {
			int tmp = arr.get(i);
			if (i < arr.size() - 1 && tmp == arr.get(i + 1)) {
				map[r][cnt--] = tmp * 2;
				i++;
			} else {
				map[r][cnt--] = arr.get(i);
			}
		}
		for (int j = cnt; j >= 0; j--) {
			map[r][j] = 0;
		}
	}

	static void go(String s) {
		if (s.equals("up")) {
			for (int j = 0; j < N; j++)
				moveUp(j);
		} else if (s.equals("down")) {
			for (int j = 0; j < N; j++)
				moveDown(j);
		} else if (s.equals("left")) {
			for (int i = 0; i < N; i++)
				moveLeft(i);
		} else if (s.equals("right")) {
			for (int i = 0; i < N; i++)
				moveRight(i);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			map = new int[N][N];
			String s = sc.next();
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			go(s);
			System.out.println("#" + tc);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					System.out.print(map[i][j] + " ");
				}
				System.out.println();
			}
		}
		sc.close();
	}

}
