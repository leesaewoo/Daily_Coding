//문자열을 입력받아 연속되는 문자가 있을 경우,
// 연속 구간을 반복되는 수와 문자로 조합한 형태로 압축한 문자열을 리턴해야 합니다.
//주의 사항:
//빈 문자열을 입력받은 경우, 빈 문자열을 리턴해야 합니다.
//3개 이상 연속되는 문자만 압축합니다.
public class CompressString {
    public String compressString(String str) {
        if(str.equals("")) {
            return "";
        }

        StringBuilder result = new StringBuilder();
        StringBuilder temp = new StringBuilder();
        char current;
        temp.append(str.charAt(0));
        char before = str.charAt(0);

        for(int i = 1 ; i < str.length() ; i++) {
            current = str.charAt(i);
            if(before == current) {
                if(i == str.length() - 1) {
                    temp.append(current);
                    if(temp.length() >= 3) {
                        result.append(temp.length());
                        result.append(temp.charAt(0));
                        temp.setLength(0);
                        break;
                    }
                    result.append(temp);
                    temp.setLength(0);
                    break;
                }
                temp.append(current);
                continue;
            }
            else if(temp.length() >= 3) {
                result.append(temp.length());
                result.append(temp.charAt(0));
            }
            else {
                result.append(temp);
            }
            temp.setLength(0);
            temp.append(current);
            before = current;
        }

        if(temp.length() != 0) {
            result.append(temp);
        }

        return result.toString();
    }
}
