//문자열을 요소로 갖는 배열을 입력받아 문자열을 세로로 읽었을 때의 문자열을 리턴해야 합니다.
//주의 사항:
//각 문자열의 길이는 다양합니다.
//각 문자의 위치를 행, 열로 나타낼 경우, 비어있는 (행, 열)은 무시합니다.
public class ReadVertically {
    public String readVertically(String[] arr) {
        StringBuilder sb = new StringBuilder();
        int index = 0;

        while(true) {

            int checkLength = sb.length();

            for(int i = 0 ; i < arr.length ; i++) {
                if(index < arr[i].length()) {
                    sb.append(arr[i].charAt(index));
                }
            }

            if(checkLength == sb.length()) {
                break;
            }

            index++;
        }

        return sb.toString();
    }
}
