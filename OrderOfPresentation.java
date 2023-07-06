//말썽꾸러기 김코딩은 오늘도 장난을 치다가 조별 발표 순서가 담긴 통을 쏟고 말았습니다.
//
//선생님께서는 미리 모든 발표 순서의 경우의 수를 저장해 놓았지만 김코딩의 버릇을 고치기 위해 문제를 내겠다고 말씀하셨습니다.
//
//김코딩은 모든 조별 발표 순서에 대한 경우의 수를 차례대로 구한 뒤 발표 순서를 말하면, 이 발표 순서가 몇 번째 경우의 수인지를 대답해야 합니다.
//
//총 조의 수 N과 선생님이 말씀하시는 발표 순서 k가 주어질 때, 김코딩이 정답을 말 할 수 있게 올바른 리턴 값을 구하세요.
//
//모든 경우의 수가 담긴 배열은 번호가 작을수록 앞에 위치한다고 가정합니다.
//ex) N = 3일경우, [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

//입력:
//N: int 타입의 1 <= N <= 12인 조의 개수
//K: int타입을 요소로 가지는 배열 (0 <= index)
//ex) n이 3이고 k가 [2, 3, 1]일 경우
//모든 경우의 수를 2차원 배열에 담는다면 [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]이 되고,
//반환하는 값은 3이 됩니다.
//
//주의사항:
//k내에 중복되는 요소는 없다고 가정합니다.

import java.util.ArrayList;
import java.util.List;

public class OrderOfPresentation {
    public int orderOfPresentation(int N, int[] K) {

        List<Integer> list = new ArrayList<>();

        for(int i = 1 ; i <= N ; i++) {
            list.add(i);
        }

        int count = 0;

        for(int i = 0 ; i < N ; i++) {
            int size = list.size();

            int numOfSmallNum = findSmallNum(list, K[i]); // list 에서 K[i]보다 작은 값들을 구하는 함수

            if(numOfSmallNum != 0) { //K[i]이 가장 작은 값 일땐 해당 값보다 먼저 올 수 있는 숫자의 경우의 수 없음
                if(size >= 3) {
                    count += numOfSmallNum * factorial(size - 1); //먼저 올 수 있는 숫자의 경우 X 나머지 자리에 올 수 있는 경우의 수
                    list.remove(list.indexOf(K[i]));
                }
                else if(list.size() == 2) {
                    count++;
                }
            }
            else {
                list.remove(list.indexOf(K[i]));
            }
        }

        return count;
    }

    public int findSmallNum(List<Integer> list, int num) {
        int count = 0;

        for(int i : list) {
            if(num > i) {
                count++;
            }
        }

        return count;
    }

    public int factorial(int num) {
        int result = 1;

        for(int i = 2 ; i <= num ; i++) {
            result *= i;
        }

        return result;
    }
}
