import java.util.InputMismatchException;
import java.util.Scanner;
public class Exercise_13 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int inputInteger = 0;
        System.out.println("구구단을 출력할 단 수(2 ~ 9)를 입력해 주세요.");
        while(inputInteger < 2 || inputInteger > 9) {
            try {
                inputInteger = scanner.nextInt();
                if(inputInteger < 2 || inputInteger > 9) {
                    System.out.println("잘못된 입력입니다.\n2에서 9 사이의 자연수를 입력해 주세요.");
                }
            }catch(InputMismatchException e) {
                System.out.println("잘못된 입력입니다.\n2에서 9 사이의 자연수를 입력해 주세요.");
                scanner.nextLine();
            }
        }
        final int MAX_NUMBER = 9;
        for(int i = 1 ; i <= MAX_NUMBER ; i++) {
            System.out.printf("%d ",inputInteger * i);
        }
    }
}
