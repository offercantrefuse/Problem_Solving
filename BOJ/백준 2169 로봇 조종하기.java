import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		Queue<Integer> q = new LinkedList<Integer>();
		boolean[] visit = new boolean[100001];
		q.offer(N);
		int ans = 0;
		boolean found = false;
		while (!q.isEmpty() && !found) {
			int qSize = q.size();
			for (int t = 0; t < qSize; t++) {
				int now = q.poll();
				if (now == K) {
					found = true;
					break;
				}
				if (now - 1 >= 0 && !visit[now - 1]) {
					visit[now - 1] = true;
					q.offer(now - 1);
				}
				if (now + 1 <= 100000 && !visit[now + 1]) {
					visit[now + 1] = true;
					q.offer(now + 1);
				}
				if (now * 2 <= 100000) {
					visit[now * 2] = true;
					q.offer(now * 2);
				}
			}
			ans++;
		}
		System.out.println(ans - 1);
		sc.close();
	}
}
