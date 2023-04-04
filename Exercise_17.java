/*
DashInsert 메서드는 숫자로 구성된 문자열을 입력받은 뒤 문자열 안에서 홀수가 연속되면 두 수 사이에 - 를 추가하고,
짝수가 연속되면 * 를 추가하는 기능을 갖고 있다. 다음과 같이 동작하는 DashInsert 메서드를 완성하시오.
*/
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
public class Exercise_17 {
    static void DashInsert(String inputString) {
        ArrayList<String> arrayList = new ArrayList<>();
        for(int i = 0 ; i < inputString.length() ; i++) {
            if(i == inputString.length() - 1) {
                arrayList.add(inputString.substring(i, i + 1));
            }
            else if(Integer.parseInt(inputString.substring(i, i + 1)) == 0 || Integer.parseInt(inputString.substring(i + 1, i + 2)) == 0) {
                arrayList.add(inputString.substring(i, i + 1));
            }
            else if(Integer.parseInt(inputString.substring(i, i + 1)) % 2 == 0 && Integer.parseInt(inputString.substring(i + 1, i + 2)) % 2 == 0) {
                arrayList.add(inputString.substring(i, i + 1));
                arrayList.add("*");
            }
            else if(Integer.parseInt(inputString.substring(i, i + 1)) % 2 == 1 && Integer.parseInt(inputString.substring(i + 1, i + 2)) % 2 == 1) {
                arrayList.add(inputString.substring(i, i + 1));
                arrayList.add("-");
            }
            else {
                arrayList.add(inputString.substring(i, i + 1));
            }
        }

        String result = "";
        for(String item : arrayList) {
            result += item;
        }
        System.out.println(result);
    }
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String inputString;
        System.out.println("18자리 이하의 숫자를 입력해 주십시오");
        try {
            inputString = br.readLine();
            Long.parseLong(inputString);
            DashInsert(inputString);
        }catch(IOException ioe) {
            ioe.printStackTrace();
        }catch(NumberFormatException nfe) {
            nfe.printStackTrace();
            System.out.println("18자리 이하의 숫자만 입력해 주세요.");
        }
    }
}