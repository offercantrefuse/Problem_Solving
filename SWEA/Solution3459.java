import java.util.Scanner;

public class Solution3459 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			long num = sc.nextLong();

			while (num > 3) {
				num = (num - 2) / 4;
			}
			if (num == 1)
				System.out.println("#" + tc + " " + "Bob");
			else
				System.out.println("#" + tc + " " + "Alice");
		}
		sc.close();
	}

}
