//정수를 요소로 갖는 배열을 입력받아 3개의 요소를 곱해 나올 수 있는 최대값을 리턴해야 합니다.
//주의사항:
//입력으로 주어진 배열은 중첩되지 않은 1차원 배열입니다.
//배열의 요소는 음수와 0을 포함하는 정수입니다.
//배열의 길이는 3 이상입니다.
public class LargestProductOfThree {
    public int largestProductOfThree(int[] arr) {
        int max = Integer.MIN_VALUE;
        for(int i = 0 ; i < arr.length ; i++) {
            for(int j = i + 1 ; j < arr.length ; j++) {
                for(int k = j + 1 ; k < arr.length ; k++) {
                    int temp = arr[i] * arr[j] * arr[k];
                    if(temp > max) {
                        max = temp;
                    }
                }
            }
        }

        return max;
    }
}
