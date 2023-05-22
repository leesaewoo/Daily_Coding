//문자열을 입력받아 연속된 한자리 홀수 숫자 사이에 '-'를 추가한 문자열을 리턴해야 합니다.
public class InsertDash {
    public String insertDash(String str) {
        if(str.equals("")) return null;
        StringBuilder sb = new StringBuilder();
        boolean prevNumIsOdd = false;
        for(int i = 0 ; i < str.length() ; i++) {
            int current = str.charAt(i) - '0';
            if(!prevNumIsOdd && current % 2 == 1) {
                prevNumIsOdd = true;
                sb.append(current);
            }
            else if(prevNumIsOdd && current % 2 == 1) {
                sb.append('-');
                sb.append(current);
            }
            else {
                prevNumIsOdd = false;
                sb.append(current);
            }
        }
        return sb.toString();
    }
}
