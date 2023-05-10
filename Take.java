import java.util.Arrays;

//수(num)와 배열을 입력받아 차례대로 num개의 요소만 포함된 새로운 배열을 리턴해야 합니다.
//출력 :
//순차적으로 num 개의 요소로 구성된 배열을 리턴해야 합니다.
//주의 사항 :
//함수 take는 재귀함수의 형태로 작성합니다.
//반복문(for, while) 사용은 금지됩니다.
//입력받은 배열은 함수의 호출 뒤에도 처음 상태를 유지해야 합니다(immutability).
public class Take {
    public int[] take(int num, int[] arr) {
        if(arr.length == 0) {
            return new int[]{};
        }
        else if(num >= arr.length) {
            return arr;
        }

        int[] newArr = Arrays.copyOf(arr, arr.length - 1);

        return take(num, newArr);
    }
}
