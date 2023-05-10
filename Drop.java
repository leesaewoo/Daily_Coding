import java.util.Arrays;

//수(num)와 배열을 입력받아 앞에서부터 차례대로 num개의 요소가 제거된 새로운 배열을 리턴해야 합니다.
//주의 사항
//함수 drop은 재귀함수의 형태로 작성합니다.
//반복문(for, while) 사용은 금지됩니다.
//입력받은 배열은 함수의 호출 뒤에도 처음 상태를 유지해야 합니다(immutability).
//num과 arr.length 중 최소값만큼 제거합니다.
public class Drop {
    public int[] drop(int num, int[] arr) {
        if(arr.length == 0) {
            return new int[]{};
        }
        else if(num == 0) {
            return arr;
        }

        int[] newArr = Arrays.copyOfRange(arr, 1, arr.length);

        return drop(num - 1, newArr);
    }
}
