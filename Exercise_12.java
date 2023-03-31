import java.util.ArrayList;
import java.util.Scanner;
public class Exercise_12 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("피보나치 수열을 출력하는 프로그램입니다.\n수열을 구할 마지막 항을 입력해 주세요.");
        int inputInteger = 0;
        while (inputInteger < 1 || inputInteger > 92) {
            try {
                inputInteger = scanner.nextInt();
                if(inputInteger < 1 || inputInteger > 92) {
                    System.out.println("입력값은 0보다 크고 93보다 작은 자연수이어야 합니다.");
                    scanner.nextLine();
                    continue;
                }
            } catch (Exception e) {
                System.out.println("입력값은 0보다 크고 93보다 작은 자연수이어야 합니다.");
                scanner.nextLine();
            }
        }
        ArrayList<Long> arrayList = new ArrayList<>();
        for(int i = 0 ; i < inputInteger ; i++) {
            if(i == 0 || i == 1) {
                arrayList.add((long)i);
            }
            else {
                arrayList.add(arrayList.get(i - 2) + arrayList.get(i - 1));
            }
        }
        System.out.println(arrayList);
    }
}