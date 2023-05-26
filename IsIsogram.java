import java.util.HashMap;
//문자열을 입력받아 아이소그램인지 여부를 리턴해야 합니다.
// 아이소그램(isogram)은 각 알파벳을 한번씩만 이용해서 만든 단어나 문구를 말합니다.
//주의 사항:
//빈 문자열을 입력받은 경우, true를 리턴해야 합니다.
//대소문자는 구별하지 않습니다.
public class IsIsogram {
    public boolean isIsogram(String str) {
        if(str.equals("")) {
            return true;
        }

        String input = str.toLowerCase();

        boolean[] isUsed = new boolean[26];

        for(int i = 0 ; i < input.length() ; i++) {
            if(isUsed[input.charAt(i) - 'a']) {
                return false;
            }
            isUsed[input.charAt(i) - 'a'] = true;
        }
        return true;
    }
}
