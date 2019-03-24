import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	static ArrayList<Integer> stick = new ArrayList<Integer>();

	static int sum() {
		int tmp = 0;
		for (int s : stick) {
			tmp += s;
		}
		return tmp;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		stick.add(64);
		int total = 64;
		while (total > X) {
			Collections.sort(stick);
			int tmp1 = stick.get(0) / 2;
			int tmp2 = tmp1;
			stick.remove(0);
			stick.add(tmp1);
			stick.add(tmp2);
			Collections.sort(stick);
			if (sum() - tmp1 >= X)
				stick.remove(0);
			total = sum();
		}
		System.out.println(stick.size());
		sc.close();
	}
}
