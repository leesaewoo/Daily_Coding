import java.util.LinkedList;
import java.util.List;

//박스 포장
//문제:
//마트에서 장을 보고 박스를 포장하려고 합니다.
//들어온 순서대로 한 명씩 나가야 합니다.
//뒷사람이 포장을 전부 끝냈어도 앞사람이 끝내지 못하면 기다려야 합니다.
//앞사람이 포장을 끝내면, 포장을 마친 뒷사람들과 함께 한 번에 나가게 됩니다.
//만약, 앞사람의 박스는 5 개고, 뒷사람 1의 박스는 4 개, 뒷사람 2의 박스는 8 개라고 가정했을 때,
// 뒷사람 1이 제일 먼저 박스 포장을 끝내게 되어도 앞사람 1의 포장이 마칠 때까지 기다렸다가 같이 나가게 됩니다.
//이때, 통틀어 최대 몇 명이 한꺼번에 나가는지 알 수 있도록 함수를 구현해 주세요.
//주의 사항:
//먼저 포장을 전부 끝낸 사람이 있더라도, 앞사람이 포장을 끝내지 않았다면 나갈 수 없습니다
public class PaveBox {
    public int paveBox(Integer[] boxes) {
        int count = 1;
        int max = 0;
        Integer firstPerson = 0;
        LinkedList<Integer> queue = new LinkedList<>();

        queue.addAll(List.of(boxes));

        if(!queue.isEmpty()) {
            firstPerson = queue.pop();
        }

        while(!queue.isEmpty()) {
            count = 1;

            while(!queue.isEmpty()) {
                Integer popInteger = queue.pop();
                if(popInteger - firstPerson <= 0) {
                    count++;
                }
                else {
                    firstPerson = popInteger;

                    if(max < count) {
                        max = count;
                    }
                    break;
                }
            }
        }

        return count;
    }
}
