//문자열을 입력받아 문자열 내에 아래 중 하나가 존재하는지 여부를 리턴해야 합니다.
//
//'a'로 시작해서 'b'로 끝나는 길이 5의 문자열
//'b'로 시작해서 'a'로 끝나는 길이 5의 문자열
//
//주의 사항:
//대소문자를 구분하지 않습니다.
//공백도 한 글자로 취급합니다.
public class ABCheck {
    public boolean abcCheck(String str) {
        int count = 0;
        boolean[] isStart = new boolean[2];
        final int A = 0;
        final int B = 1;
        for(int i = 0 ; i < str.length() ; i++) {
            if(!isStart[A] && !isStart[B]) {
                if(str.charAt(i) == 'a' || str.charAt(i) == 'A') {
                    isStart[A] = true;
                    count++;
                }else if(str.charAt(i) == 'b' || str.charAt(i) == 'B') {
                    isStart[B] = true;
                    count++;
                }
            }else if(isStart[A] || isStart[B]) {
                if(count == 4) {
                    if((str.charAt(i) == 'b' || str.charAt(i) == 'B') && isStart[A]) {
                        return true;
                    } else if((str.charAt(i) == 'a' || str.charAt(i) == 'A') && isStart[B]) {
                        return true;
                    } else {
                        i -= 4;
                        isStart[A] = false;
                        isStart[B] = false;
                        count = 0;
                    }
                }else {
                    count++;
                }
            }
        }
        return false;
    }
}
