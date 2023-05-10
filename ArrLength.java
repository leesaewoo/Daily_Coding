import java.util.Arrays;

//배열을 입력받아 그 길이를 리턴해야 합니다.
//주의 사항
//함수 arrLength는 재귀함수의 형태로 작성합니다.
//반복문(for, while) 사용은 금지됩니다.
//입력받은 배열은 함수의 호출 뒤에도 처음 상태를 유지해야 합니다(immutability).
//빈 배열의 길이는 0입니다.
public class ArrLength {
    public int arrLength(int[] arr) {
        if(arr.length == 0) {
            return 0;
        }

        int[] newArr = Arrays.copyOfRange(arr, 1, arr.length);

        return 1 + arrLength(newArr);
    }
}
