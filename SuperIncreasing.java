//수를 요소로 갖는 배열을 입력받아 각 요소들이 그 이전의 요소들의 합보다 큰지 여부를 리턴해야 합니다.
public class SuperIncreasing {
    public boolean superIncreasing(int[] arr) {
        if(arr.length == 0) {
            return false;
        }

        int sum = arr[0];

        for(int i = 1 ; i < arr.length ; i++) {
            if(arr[i] <= sum) {
                return false;
            }
            sum += arr[i];
        }
        return true;
    }
}
