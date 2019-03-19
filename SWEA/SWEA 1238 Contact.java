import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution1238 {

	static int N, start, cnt;
	static int[][] adj;
	static int[] visit;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int tc = 1; tc <= 10; tc++) {
			N = sc.nextInt();
			start = sc.nextInt();
			adj = new int[101][101];
			visit = new int[101];
			Queue<Integer> q = new LinkedList<Integer>();
			q.add(start);
			for (int i = 0; i < N / 2; i++) {
				int from = sc.nextInt();
				int to = sc.nextInt();
				adj[from][to] = 1;
			}
			cnt = 1;  // 시작점에서 거리
			while (!q.isEmpty()) {
				int qSize = q.size();  // 거리를 표시해주기 위해 size를 잡아서 반복
				for (int t = 0; t < qSize; t++) {
					int now = q.poll();
					visit[now] = cnt;
					for (int i = 1; i <= 100; i++) {
						if (adj[now][i] == 1 && visit[i] == 0) {
							q.offer(i);
							visit[i] = cnt;
						}
					}
				}
				cnt++;
			}
			int maxi = 0;
			int ans = 0;
			for (int i = 1; i < 101; i++) {
				if (maxi <= visit[i]) {
					maxi = visit[i];
					ans = i;
				}
			}
			System.out.println("#" + tc + " " + ans);
		}
		sc.close();
	}

}
