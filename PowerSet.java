//하나의 집합을 의미하는 문자열을 입력받아 각 문자를 가지고 만들 수 있는 모든 부분집합을 리턴해야 합니다.
//주의사항:
//ArrayList의 요소는 각 부분집합을 구성하는 원소를 연결한 문자열입니다.
//ArrayList의 요소는 알파벳 순서로 정렬되어야 합니다.
//집합은 중복된 원소를 허용하지 않습니다.
//부분집합은 빈 문자열을 포함합니다.
//ArrayList는 오름차순으로 정렬되어야 합니다.

import java.util.*;
import java.util.stream.Collectors;

public class PowerSet {
    public ArrayList<String> powerSet(String str) {
        List<Character> charList = new ArrayList<>();
        for(int i = 0 ; i < str.length() ; i++) {
            charList.add(str.charAt(i));
        }

        charList = charList.stream().distinct().sorted(Comparator.naturalOrder()).collect(Collectors.toList());

        StringBuilder sb = new StringBuilder();
        for(int i = 0 ; i < charList.size() ; i++) {
            sb.append(charList.get(i));
        }

        String fixedStr = sb.toString();

        StringBuilder stringBuilder = new StringBuilder();
        ArrayList<String> result = new ArrayList<>();
        recursive(fixedStr, 0 , stringBuilder, result);

        result = (ArrayList<String>) result.stream().sorted(Comparator.naturalOrder()).collect(Collectors.toList());

        return result;
    }

    public void recursive(String str, int index, StringBuilder stringBuilder, ArrayList<String> result) {

        if(index >= str.length()) {
            String resultStr = stringBuilder.toString();
            result.add(resultStr);
            return;
        }

        //숫자 선택하지 않은 경우
        recursive(str, index + 1, stringBuilder, result);

        //숫자 선택한 경우
        stringBuilder.append(str.charAt(index));
        recursive(str, index + 1, stringBuilder, result);
        stringBuilder.deleteCharAt(stringBuilder.length() - 1);
    }
}
