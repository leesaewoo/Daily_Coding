//문자열을 입력받아 문자열에서 숫자를 모두 찾아 더한 뒤에
// 해당 값을 (숫자와 공백을 제외한 나머지) 문자열의 길이로 나눈 값을 정수로 반올림하여 리턴해야 합니다.
//주의 사항:
//빈 문자열을 입력받은 경우, 0을 리턴해야 합니다.
//숫자(digit)는 연속해서 등장하지 않습니다.
public class NumberSearch {
    public int numberSearch(String str) {
        if(str.equals("")) {
            return 0;
        }

        int sum = 0;
        int length = str.length();

        for(int i = 0 ; i < str.length() ; i++) {
            char currentChar = str.charAt(i);
            if(currentChar >= '0' && currentChar <= '9') {
                sum += currentChar - '0';
                length -= 1;
            }
            else if (currentChar == ' ') {
                length -= 1;
            }
        }

        if(length == 0) {
            return 0;
        }

        return Math.round((float)sum / length);
    }
}
