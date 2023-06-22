//부분적으로 오름차순 정렬*된 정수의 배열(rotated)과 정수(target)를 입력받아 target의 인덱스를 리턴해야 합니다.
//
//부분적으로 정렬된 배열: 배열을 왼쪽 혹은 오른쪽으로 0칸 이상 순환 이동할 경우 완전히 정렬되는 배열
//예시: [4, 5, 6, 0, 1, 2, 3]은 왼쪽으로 3칸 또는 오른쪽으로 4칸 순환 이동할 경우 완전히 정렬됩니다.
//주의사항:
//rotated에 중복된 요소는 없습니다.
//target이 없는 경우, -1을 리턴해야 합니다.
public class RotatedArraySearch {
    public int rotatedArraySearch(int[] rotated, int target) {

        int head = 0;
        int tail = rotated.length - 1;
        int mid;
        int result = - 1;

        while(head != tail) {
            mid = (head + tail) / 2;

            if(rotated[mid] == target) {
                result = mid;
                break;
            }
            else if(rotated[head] == target) {
                result = head;
                break;
            }
            else if(rotated[tail] == target) {
                result = tail;
                break;
            }
            else if(rotated[mid] < target && target < rotated[tail]) {
                head += 1;
                tail -= 1;

            } else {
                head += 1;
                tail -= 1;
            }
        }

        return result;
    }
}
