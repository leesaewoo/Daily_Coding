import java.util.Arrays;

//배열을 입력받아 순서가 뒤집힌 배열을 리턴해야 합니다.
//주의 사항:
//함수 reverseArr는 재귀함수의 형태로 작성합니다.
//반복문(for, while) 사용은 금지됩니다.
//입력받은 배열은 함수의 호출 뒤에도 처음 상태를 유지해야 합니다(immutability).
//빈 배열은 빈 배열 그대로를 리턴해야 합니다.
public class ReverseArr {
    public int[] reverseArr(int[] arr) {
        if(arr.length == 0) {
            return new int[]{};
        }

        int[] front = Arrays.copyOfRange(arr, arr.length - 1, arr.length);

        int[] back = reverseArr(Arrays.copyOfRange(arr, 0, arr.length - 1));

        int[] result = new int[front.length + back.length];

        System.arraycopy(front, 0, result, 0, front.length);

        System.arraycopy(back, 0, result, front.length, back.length);

        return result;
    }
}
