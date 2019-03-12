import java.util.Scanner;

public class Solution1493 {

	static int T;
	static int[] firstNum = new int[501];

	static void setNum() { // (1,i) 좌표의 값 입력
		for (int i = 1; i <= 500; i++) {
			firstNum[i] = 1 + i * (i - 1) / 2;
		}
	}

	static int find(int num) { // 가까운 (1, i)의 index 찾기
		int tmp = 0;
		for (int i = 1; i <= 500; i++) {
			if (firstNum[i] > num) {
				tmp = i - 1;
				break;
			}
		}
		return tmp;
	}

	public static void main(String[] args) {
		setNum();
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int p = sc.nextInt();
			int q = sc.nextInt();
		
			int idx1 = find(p);
			int tmp = p - firstNum[idx1];
			int px = 1, py = idx1;
			for (int i = 0; i < tmp; i++) {
				px++;
				py--;
			}
			
			int idx2 = find(q);
			int qx = 1, qy = idx2;
			tmp = q - firstNum[idx2];
			for (int i = 0; i < tmp; i++) {
				qx++;
				qy--;
			}

			int xx = px + qx;
			int yy = py + qy;
			int cnt = 0;
			while (xx > 1) {
				xx--;
				yy++;
				cnt++;
			}
			int ans = firstNum[yy];
			ans += cnt;
			System.out.println("#" + tc + " " + ans);
		}
		sc.close();
	}

}
