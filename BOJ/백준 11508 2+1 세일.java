import java.util.Arrays;
import java.util.Scanner;

public class BOJ11508 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] num = new int[N];
		for (int i = 0; i < N; i++) {
			num[i] = sc.nextInt();
		}
		Arrays.sort(num);
		int pt = N - 1;
		int sum = 0;
		while (pt - 2 >= 0) {
			sum += num[pt] + num[pt - 1];
			pt -= 3;
		}
		while (pt >= 0) {
			sum += num[pt];
			pt--;
		}
		System.out.println(sum);
		sc.close();
	}

}
