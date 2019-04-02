import java.util.Scanner;

public class Jungol1239 {

	static int A = 0, B = 15, C = 19, D = 28, E = 38, F = 41, G = 53, H = 58;
	static int num;
	static boolean found;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		num = sc.nextInt();
		int cnt = 0;
		String s = sc.next();
		StringBuilder sb = new StringBuilder();
		found = true;
		for (int i = 0; i < s.length() && found; i += 6) {
			int sum = 0;
			for (int j = i + 5; j >= i; j--) {
				sum += (s.charAt(j) - '0') * (1 << (i + 5 - j));
			}
			char ch = find(sum); // 맞는 글자 찾기
			sb.append(ch); // 글자 붙이기
			cnt++; // 몇 번째 글자인지
		}
		if (!found)
			System.out.println(cnt);
		else
			System.out.println(sb.toString());
		sc.close();
	}

	private static char find(int sum) {
		// 차이 한 개인지
		if ((A ^ sum) == 0 || (A ^ sum) == 1 || (A ^ sum) == 2 || (A ^ sum) == 4 || (A ^ sum) == 8 || (A ^ sum) == 16
				|| (A ^ sum) == 32)
			return 'A';
		if ((B ^ sum) == 0 || (B ^ sum) == 1 || (B ^ sum) == 2 || (B ^ sum) == 4 || (B ^ sum) == 8 || (B ^ sum) == 16
				|| (B ^ sum) == 32)
			return 'B';
		if ((C ^ sum) == 0 || (C ^ sum) == 1 || (C ^ sum) == 2 || (C ^ sum) == 4 || (C ^ sum) == 8 || (C ^ sum) == 16
				|| (C ^ sum) == 32)
			return 'C';
		if ((D ^ sum) == 0 || (D ^ sum) == 1 || (D ^ sum) == 2 || (D ^ sum) == 4 || (D ^ sum) == 8 || (D ^ sum) == 16
				|| (D ^ sum) == 32)
			return 'D';
		if ((E ^ sum) == 0 || (E ^ sum) == 1 || (E ^ sum) == 2 || (E ^ sum) == 4 || (E ^ sum) == 8 || (E ^ sum) == 16
				|| (E ^ sum) == 32)
			return 'E';
		if ((F ^ sum) == 0 || (F ^ sum) == 1 || (F ^ sum) == 2 || (F ^ sum) == 4 || (F ^ sum) == 8 || (F ^ sum) == 16
				|| (F ^ sum) == 32)
			return 'F';
		if ((G ^ sum) == 0 || (G ^ sum) == 1 || (G ^ sum) == 2 || (G ^ sum) == 4 || (G ^ sum) == 8 || (G ^ sum) == 16
				|| (G ^ sum) == 32)
			return 'G';
		if ((H ^ sum) == 0 || (H ^ sum) == 1 || (H ^ sum) == 2 || (H ^ sum) == 4 || (H ^ sum) == 8 || (H ^ sum) == 16
				|| (H ^ sum) == 32)
			return 'H';
		found = false;
		return 'Z';
	}

}
