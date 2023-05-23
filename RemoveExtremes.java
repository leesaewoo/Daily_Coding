import java.util.Arrays;
import java.util.ArrayList;

//문자열을 요소로 갖는 배열을 입력받아
// 가장 짧은 문자열과 가장 긴 문자열을 제거한 배열을 리턴해야 합니다.
//주의 사항:
//가장 짧은 문자열의 길이와 가장 긴 문자열의 길이가 같은 경우는 없습니다.
//가장 짧은 문자열 또는 가장 긴 문자열이 다수일 경우, 나중에 위치한 문자열을 제거합니다.
//공백을 입력받을 경우, null을 반환합니다.
public class RemoveExtremes {
    public String[] removeExtremes(String[] arr) {
        if(arr.length == 0) {
            return null;
        }
        int shortest = arr[0].length();
        int longest = 0;
        String longestWord = "";
        String shortestWord = arr[0];

        for(int i = 0 ; i < arr.length ; i++) {
            if(arr[i].contains(" ")) {
                return null;
            }

            if(shortest >= arr[i].length()) {
                shortest = arr[i].length();
                shortestWord =  arr[i];
            }

            if(longest <= arr[i].length()) {
                longest = arr[i].length();
                longestWord =  arr[i];
            }
        }

        ArrayList<String> list = new ArrayList<>(Arrays.asList(arr));
        list.remove(list.indexOf(longestWord));
        list.remove(list.indexOf(shortestWord));

        String[] result = list.toArray(new String[list.size()]);
        return result;
    }
}
