//브라우저 뒤로 가기 앞으로 가기
//조건:
//새로운 페이지로 접속할 경우 prev 스택에 원래 있던 페이지를 넣고 next 스택을 비웁니다.
//뒤로 가기 버튼을 누를 경우 원래 있던 페이지를 next 스택에 넣고 prev 스택의 top에 있는
// 페이지로 이동한 뒤 prev 스택의 값을 pop 합니다.
//앞으로 가기 버튼을 누를 경우 원래 있던 페이지를 prev 스택에 넣고 next 스택의 top에 있는
// 페이지로 이동한 뒤 next 스택의 값을 pop 합니다.
//브라우저에서 뒤로 가기, 앞으로 가기 버튼이 비활성화일 경우(클릭이 되지 않을 경우)에는
// 스택에 push 하지 않습니다.
//인터넷 브라우저에서 행동한 순서가 들어있는 배열 actions와 시작 페이지 start가 주어질 때
// 마지막에 접속해 있는 페이지와 방문했던 페이지들이 담긴 스택을 반환하는 솔루션
//주의사항:
//앞으로가기나 뒤로가기가 아닌 경우에 새로운 페이지로 취급을 한다
//뒤로 가기 버튼을 누른 행동은 "-1"로 표기합니다.
//앞으로 가기 버튼을 누른 행동은 "1"로 표기합니다.
//다음 방문할 페이지는 항상 현재 페이지와 다른 페이지로 접속합니다.
//방문한 페이지의 개수는 100개 이하입니다.
//반환되는 출력값 ArrayList의 첫 번째 요소 prev 스택, 두번째 요소 current 스택,
// 세 번째 요소 next 스택을 사용해야 합니다.
import java.util.Stack;
import java.util.ArrayList;
public class PrevAndNextPage {
    public ArrayList<Stack> browserStack(String[] actions, String start) {
        Stack<String> prevStack = new Stack();
        Stack<String> nextStack = new Stack();
        Stack<String> current = new Stack();
        ArrayList<Stack> result = new ArrayList<>();

        current.push(start);

        for(String s : actions) {
            if(s.equals("-1") && prevStack.size() != 0) {
                nextStack.push(current.pop());
                current.push(prevStack.pop());
            }
            else if(s.equals("1") && nextStack.size() != 0) {
                prevStack.push(current.pop());
                current.push(nextStack.pop());
            }
            else if(!(s.equals("-1") || s.equals("1"))) {
                prevStack.push(current.pop());
                current.push(s);
                nextStack.removeAllElements();
            }
        }

        result.add(prevStack);
        result.add(current);
        result.add(nextStack);

        return result;
    }
}
