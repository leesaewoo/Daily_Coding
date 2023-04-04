/*
시저 암호는, 고대 로마의 황제 줄리어스 시저가 만들어 낸 암호인데, 예를 들어 알파벳 A를 입력했을 때,
그 알파벳의 n개 뒤에 오는 알파벳이 출력되는 것이다.
예를 들어 바꾸려는 단어가 "CAT"고, n을 5로 지정하였을 때 "HFY"가 되는 것이다.
어떠한 암호를 만들 문장과 n을 입력했을 때 암호를 만들어 출력하는 프로그램을 작성하시오.
단, 알파벳은 A~Z 까지의 대문자만 사용한다.
*/
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
class InputException2 extends RuntimeException {

}
public class Exercise_21 {
    public static void inputExceptionCheck(String inputString) throws InputException2 {
        for(int i = 0 ; i < inputString.length() ; i++) {
            if((int)inputString.charAt(i) < 65 || (int)inputString.charAt(i) > 90) {
                throw new InputException2();
            }
        }
    }
    public static String getCaesarCipher(String inputString) {
        String result = "";
        char tmp;
        for(int i = 0 ; i < inputString.length() ; i++) {
            if((int)inputString.charAt(i) < 86) {
                tmp = (char) ((int) inputString.charAt(i) + 5);
                result += Character.toString(tmp);
            }
            else {
                tmp = (char) ((int) inputString.charAt(i) - 21);
                result += Character.toString(tmp);
            }
        }
        return result;
    }
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String inputString = br.readLine();
            inputExceptionCheck(inputString);
            System.out.println(getCaesarCipher(inputString));
        }catch(IOException ioe) {
            ioe.printStackTrace();
        }catch(InputException2 ie) {
            ie.printStackTrace();
            System.out.println("영문 대문자만 입력해 주세요.");
        }

    }
}
