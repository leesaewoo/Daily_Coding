/*
0~9의 문자로 된 숫자를 입력받았을 때, 이 입력값이 0~9의 모든 숫자를 각각 한 번씩만 사용한 것인지 확인하는 프로그램을 작성하시오.
*/
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
public class Exercise_19 {
    static void Duplicate(String inputString) {
        HashMap<Character,Integer> checkDuplicate = new HashMap<>();
        checkDuplicate.put('0', 0);
        checkDuplicate.put('1', 0);
        checkDuplicate.put('2', 0);
        checkDuplicate.put('3', 0);
        checkDuplicate.put('4', 0);
        checkDuplicate.put('5', 0);
        checkDuplicate.put('6', 0);
        checkDuplicate.put('7', 0);
        checkDuplicate.put('8', 0);
        checkDuplicate.put('9', 0);
        for(int i = 0 ; i < inputString.length() ; i++) {
            checkDuplicate.put(inputString.charAt(i), + 1);
        }
        for(char i = '0' ; i <= '9' ; i++) {
            if(checkDuplicate.get(i) != 1) {
                System.out.printf("false ");
                break;
            }
            else if(i == '9') {
                System.out.printf("true ");
            }
        }

    }
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String inputString;
        try{
            inputString = br.readLine();
            String[] inputStringArray = inputString.split(" ");
            for(int i = 0 ; i < inputStringArray.length ; i++) {
                Integer.parseInt(inputStringArray[i]); // 숫자 외의 입력 확인
                Duplicate(inputStringArray[i]);
            }
        }
        catch(IOException ioe) {
            ioe.printStackTrace();
        }
        catch(NumberFormatException nfe) {
            nfe.printStackTrace();
            System.out.println("숫자만 입력해 주세요.");
        }
    }
}
