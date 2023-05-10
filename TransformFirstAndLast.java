import java.util.HashMap;
public class TransformFirstAndLast {
    public HashMap transformFirstAndLast(String[] arr) {
        //배열을 입력받아 차례대로 배열의 첫 요소와 마지막 요소를 키와 값으로 하는 HashMap을 리턴해야 합니다.

        HashMap hashMap = new HashMap();

        if(arr.length != 0)
        hashMap.put(arr[0], arr[arr.length - 1]);

        return hashMap;
    }
}
