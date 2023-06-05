//정수를 요소로 갖는 배열을 입력받아 오름차순으로 정렬하여 리턴해야 합니다.
//주의사항:
//위에서 설명한 알고리즘을 구현해야 합니다.
//arr.sort 사용은 금지됩니다.
//입력으로 주어진 배열은 중첩되지 않은 1차원 배열입니다.
public class BubbleSort {
    public int[] bubbleSort(int[] arr) {
        for(int i = 0 ; i < arr.length ; i++) {
            int check = 0;
            for(int head = 0 ; head < arr.length - 1 ; head++) {
                int tail = head + 1;
                if(arr[head] > arr[tail]) {
                    int temp = arr[head];
                    arr[head] = arr[tail];
                    arr[tail] = temp;
                    check++;
                }
            }
            if(check == 0) {
                return arr;
            }
        }
        return arr;
    }
}
