//문자열을 입력받아 문자열을 구성하는 각 단어의 첫 글자가 대문자인 문자열을 리턴해야 합니다.
//주의 사항:
//단어는 공백으로 구분합니다.
//연속된 공백이 존재할 수 있습니다.
//빈 문자(공백)으로만 이루어진 문자열을 입력받은 경우, 빈 문자열을 리턴해야 합니다.
public class FirstLetterCapitalize {
    public String firstLetterCapitalize(String str) {
        if (str == "") {
            return "";
        }
        String[] ar = str.split(" ");
        StringBuilder sb = new StringBuilder();

        for (int i = 0 ; i < ar.length ; i++) {
            if (ar[i].equals("")) {
                sb.append(" ");
            } else if (ar[i].length() > 0) {
                sb.append(ar[i].substring(0,1).toUpperCase());
                if (ar[i].length() > 1) {
                    sb.append(ar[i].substring(1));
                }
                sb.append(" ");
            }
        }

        if (sb.length() != 0) {
            sb.deleteCharAt(sb.length() - 1);
        }

        return sb.toString();
    }
}
