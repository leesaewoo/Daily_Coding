//문자열을 입력받아 문자열 내의 모든 종류의 괄호('(', ')', '{', '}', '[', ']')의
// 짝이 맞는지 여부를 리턴해야 합니다.
//주의사항:
//괄호는 먼저 열리고('('), 열린만큼만 닫혀야(')') 합니다.
//빈 문자열을 입력받은 경우, true를 리턴해야 합니다
import java.util.Scanner;

public class BalancedBrackets {
    public boolean balancedBrackets(String str) {
        if(str.length() == 1) {
            return false;
        }

        int open1 = 0;
        int open2 = 0;
        int open3 = 0;

        for(int i = 0 ; i < str.length() ; i++) {
            char current = str.charAt(i);
            if(current == '(') {
                open1++;
            }
            else if(current == '{') {
                open2++;
            }
            else if(current == '[') {
                open3++;
            }
            else if(current == ')' && open1 > 0) {
                open1--;
            }
            else if(current == '}' && open2 > 0) {
                open2--;
            }
            else if(current == ']' && open3 > 0) {
                open3--;
            }
            else {
                return false;
            }
        }

        return true;
    }
}
