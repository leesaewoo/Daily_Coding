import java.util.Arrays;

//배열을 입력받아 모든 요소의 논리곱(and)을 리턴해야 합니다.
//출력:
//boolean 타입을 리턴해야 합니다.
//주의 사항:
//함수 and는 재귀함수의 형태로 작성합니다.
//반복문(for, while) 사용은 금지됩니다.
//입력받은 배열은 함수의 호출 뒤에도 처음 상태를 유지해야 합니다(immutability).
//빈 배열의 논리곱은 true 입니다.
public class And {
    public boolean and(boolean[] arr) {
        if(arr.length == 0) {
            return true;
        }

        boolean[] newArr = Arrays.copyOfRange(arr, 1, arr.length);

        return arr[0] && and(newArr);
    }
}
