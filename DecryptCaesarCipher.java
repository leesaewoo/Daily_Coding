//암호화된 문자열과 암호화 키를 입력받아 복호화된 문자열을 리턴해야 합니다.
//카이사르 암호(Caesar cipher)는 평문(plaintext)을
// 암호키 secret개만큼 (오른쪽으로) 평행이동시켜 암호화 합니다.
// 복호화는 암호화된 문자열을 원래의 평문으로 복원하는 것을 말합니다.
//'hello'를 secret 3으로 암호화한 경우: 'khoor'
//'codestates'를 secret 11로 암호화한 경우: 'nzopdelepd'
//주의 사항:
//빈 문자열을 입력받은 경우, 빈 문자열을 리턴해야 합니다.
//공백은 그대로 두어야 합니다.
//입력된 문자열은 모두 소문자만 입력됩니다.
public class DecryptCaesarCipher {
    public String decryptCaesarCipher(String str, int secret) {
        if(str.length() == 0) {
            return "";
        }

        StringBuilder sb = new StringBuilder();

        for(int i = 0 ; i < str.length() ; i++) {
            char current = str.charAt(i);
            if(current == ' ') {
                sb.append(current);
            }
            else if(current > 'a' + secret - 1) {
                sb.append((char)(current - secret));
            }
            else {
                sb.append((char)(current + 26 - secret));
            }
        }
        return sb.toString();
    }
}
