/*
문자열을 입력받아 같은 문자가 연속적으로 반복되는 경우에 그 반복 횟수를 표시해 문자열을 압축하여 표시하시오.
입력 예시: aaabbcccccca
출력 예시: a3b2c6a1
*/
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Exercise_18 {
    public static void main(String [] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<String> arrayList = new ArrayList<>();
        String inputString;
        String result = "";
        int count = 1;

        try {
            inputString = br.readLine();

            for(int i = 0 ; i < inputString.length() ; i++) {
                if(i == inputString.length() - 1 && count == 1) {
                    result += inputString.substring(i, i + 1);
                    result += count;
                }
                else if(i == inputString.length() - 1 && count != 1) {
                    result += count;
                    count = 1;
                }
                else if(inputString.charAt(i) == inputString.charAt(i + 1) && count == 1) {
                    result += inputString.substring(i, i + 1);
                    count++;
                }
                else if(inputString.charAt(i) == inputString.charAt(i + 1) && count != 1) {
                    count++;
                }
                else if(inputString.charAt(i) != inputString.charAt(i + 1) && count != 1) {
                    result += count;
                    count = 1;
                }
                else {
                    result += inputString.substring(i, i + 1);
                    result += count;
                    count = 1;
                }
            }
            System.out.println(result);
        }catch(IOException ioe) {
            ioe.printStackTrace();
        }
    }
}
