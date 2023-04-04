/*
문자열 형식으로 입력받은 모스 부호(dot:. dash:-)를 해독하여 영어 문장으로 출력하는 프로그램을 작성하시오.
글자와 글자 사이는 공백 1개, 단어와 단어 사이는 공백 2개로 구분한다.
예를 들어 다음 모스 부호는 "HE SLEEPS EARLY"로 해석해야 한다.
.... .  ... .-.. . . .--. ...  . .- .-. .-.. -.--
*/
import java.util.HashMap;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
class InputException extends RuntimeException {
}
public class Exercise_20 {
    public static String getResult(String inputString) throws InputException {
        HashMap<String,String> morseCode = new HashMap<>();
        morseCode.put(".-", "A");
        morseCode.put("-...", "B");
        morseCode.put("-.-.", "C");
        morseCode.put("-..", "D");
        morseCode.put(".", "E");
        morseCode.put("..-.", "F");
        morseCode.put("--.", "G");
        morseCode.put("....", "H");
        morseCode.put("..", "I");
        morseCode.put(".---", "J");
        morseCode.put("-.-", "K");
        morseCode.put(".-..", "L");
        morseCode.put("--", "M");
        morseCode.put("-.", "N");
        morseCode.put("===", "O");
        morseCode.put(".--.", "P");
        morseCode.put("--.-", "Q");
        morseCode.put(".-.", "R");
        morseCode.put("...", "S");
        morseCode.put("-", "T");
        morseCode.put("..-", "U");
        morseCode.put("...-", "V");
        morseCode.put(".==", "W");
        morseCode.put("-..-", "X");
        morseCode.put("-.--", "Y");
        morseCode.put("--..", "Z");
        morseCode.put("space", " ");

        ArrayList morseCodeArray = new ArrayList();
        String result = "";
        int endIndex = 0; // 최근 사용했던 substring의 endIndex를 저장하는 변수

        for(int i = 0 ; i < inputString.length() ; i++) {
            if(inputString.charAt(i) == ' ') {
                morseCodeArray.add(inputString.substring(endIndex, i));
                if(i != inputString.length() - 1 && inputString.charAt(i + 1) == ' ') {
                    morseCodeArray.add("space");
                    endIndex = i + 2;
                    i += 1; // 공백이 2개 이므로 for문 인덱스에 1만큼 더해준다
                }
                else {
                    endIndex = i + 1;
                }
            }
            else if(i == inputString.length() - 1) {
                morseCodeArray.add(inputString.substring(endIndex));
            }
        }

        for(int i = 0 ; i < morseCodeArray.size() ; i++) {
            if(morseCode.get(morseCodeArray.get(i)) == null) {
                throw new InputException();
            }
            result += morseCode.get(morseCodeArray.get(i));
        }
        return result;
    }

    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String inputString = "";
        try {
            inputString = br.readLine();
            System.out.println(getResult(inputString));
        }catch (IOException ioe) {
            ioe.printStackTrace();
        }catch (InputException ie) {
            ie.printStackTrace();
            System.out.println("잘못된 모스 부호가 입력 되었습니다.");
        }
    }
}
