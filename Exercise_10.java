import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Exercise_10 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("X미만의 자연수에서 A와 B의 배수를 구하여 합하는 프로그램입니다. (단, A와 B는 X보다 작은 자연수");
        while(true) {
            int cnt = 0; // 상황 판단을 위한 변수 (1 : 잘못된 입력, -1 : 프로그램 종료, 0 : 계속 진행)
            System.out.println("자연수 X의 값을 입력해주세요 (단, X는 9자리 미만의 자연수)\n중딘하려면 end 입력하세요");
            String inputString01 = br.readLine();
            if(inputString01.toLowerCase().equals("end")) {
                System.out.println("종료되었습니다.");
                break;
            }

            for(int i = 0 ; i < inputString01.length() ; i++) {
                if(inputString01.length() > 9 || inputString01.equals("")) {
                    System.out.println("잘못된 입력입니다.\n");
                    cnt = 1;
                    break;
                }
                else if((int)inputString01.charAt(i) > 57 || (int)inputString01.charAt(i) < 48) {
                    System.out.println("잘못된 입력입니다.\n");
                    cnt = 1;
                    break;
                }
            }
            if(cnt == 1) {
                continue;
            }

            while(true) {
                System.out.println("1이상 10 미만의 두 자연수를 공백으로 구분하여 입력하세요. ex)2 7 \n중단하려면 end 입력하세요");
                String inputString02 = br.readLine();
                String[] inputStringArray = inputString02.split(" ");

                if (inputString02.toLowerCase().equals("end")) {
                    System.out.println("종료되었습니다.");
                    cnt = - 1;
                    break;
                }
                //세가지 이상의 자연수 입력 시 오류
                else if (inputStringArray.length > 2 || inputStringArray.length < 1) {
                    System.out.println("잘못된 입력입니다.\n");
                    continue;
                }
                //두자리수 이상 자연수 입력 시 오류
                else if (inputStringArray[0].length() > 1 || inputStringArray[1].length() > 1) {
                    System.out.println("잘못된 입력입니다.\n");
                    continue;
                }
                //숫자가 아닌 값을 입력 시 오류
                else if (((int) (inputStringArray[0].charAt(0)) > 57 || ((int) (inputStringArray[0].charAt(0)) < 49))
                        || ((int) (inputStringArray[1].charAt(0)) > 57 || ((int) (inputStringArray[1].charAt(0)) < 49))) {
                    System.out.println("잘못된 입력입니다.\n");
                    continue;
                }


                int naturalNumber01 = inputStringArray[0].charAt(0) - 48;
                int naturalNumber02 = inputStringArray[1].charAt(0) - 48;
                int naturalNumber03 = naturalNumber01 * naturalNumber02;
                int naturalNumber01_quotient = Integer.parseInt(inputString01) / naturalNumber01;
                int naturalNumber02_quotient = Integer.parseInt(inputString01) / naturalNumber02;
                int naturalNumber03_quotient = Integer.parseInt(inputString01) / naturalNumber03;
                long naturalNumber01_sum = ((naturalNumber01 + (naturalNumber01 * naturalNumber01_quotient)) * naturalNumber01_quotient) / 2;
                long naturalNumber02_sum = ((naturalNumber02 + (naturalNumber02 * naturalNumber02_quotient)) * naturalNumber02_quotient) / 2;
                long naturalNumber03_sum = ((naturalNumber03 + (naturalNumber03 * naturalNumber03_quotient)) * naturalNumber03_quotient) / 2;
                long result = naturalNumber01_sum + naturalNumber02_sum - naturalNumber03_sum;
                System.out.println("결과 : " + result);
                break;
            }
            if(cnt == -1) {
                break;
            }
        }
    }
}
