import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;

//개업 이래로 항상 승승장구하는 '승승장구 치킨집'의 비결은
//5대째 내려오는 '비밀의 승승장구 치킨 소스 비율 레시피'
//최근, 누리꾼 사이에서 이 레시피의 일부분을 발췌했다는 소문을 듣게 되었다.
//그 소문은 다음과 같다.
//
//N 가지의 재료 중에 단 M 가지만을 사용하여 조합한 모든 경우의 수 중 하나이다.
//재료는 0과 1로만 이루어진 숫자로 암호화가 되어 있고, 항상 1로 시작하며 복호화를 할 수 없다.
//단, 0이 3개 이상인 재료는 상한 재료이기 때문에 제외한다.
//재료의 순서에 따라 맛이 달라지기 때문에, 재료를 넣는 순서가 다르다면 다른 레시피이다.
//이 소문을 참고하여 '비밀의 승승장구 치킨 소스'가 될 수 있는 경우의 수를 모두 반환하는 함수를 작성하세요.
//
//인자 1: stuffArr
//int 타입의 재료를 담은 배열
//요소는 0과 1로만 이루어진 숫자이며, 항상 1로 시작합니다.
//요소는 중복될 수 없습니다.
//요소의 길이는 20 이하입니다.
//배열의 길이는 2 이상 10 이하입니다.
//ex) [111, 110, 1010, 10, 10110]
//
//인자 2: choiceNum
//int 타입의 1 이상 stuffArr 길이 이하의 자연수
//재료를 선택할 수 있는 수를 뜻합니다.
//ex) 2
//
//ArrayList<Integer[]> 타입을 반환해야 합니다.
//stuffArr가 [1, 10, 11000, 1111] 이고,
// choiceNum은 2라면, 11000은 상했으므로 제외되어
// 사용 가능한 재료는 [1, 10, 1111] 입니다. 조합할 수 있는 경우의 수는 6 가지입니다.
//
//주의사항:
//만약, 주어진 재료 모두 사용할 수 없다면 null을 반환해야 합니다.
//만약, 사용할 수 있는 재료가 choiceNum보다 작다면 null을 반환해야 합니다.
//조합 및 요소는 작은 숫자 -> 큰 숫자로 정렬합니다.
//예시로 [1, 10, 11000, 1111]이 요소로 들어왔다면, 0이 세 개인 11000을 제외하고 [1, 10, 1111] 순서가 되어야 하며,
//[ [1, 10], [1, 1111], [10, 1], [10, 1111], [1111, 1], [1111, 10] ]을 반환해야 합니다
public class NewChickenRecipe {
    ArrayList<Integer[]> result = new ArrayList<>();
    public ArrayList<Integer[]> newChickenRecipe(int[] stuffArr, int choiceNum) {
        //stuffArr 오름차순 정렬
        Arrays.sort(stuffArr);
        //정렬된 stuffArr을 new ArrayList<Integer>로 옮겨 담으면서 상한(0이 3개 이상)재료 제외
        ArrayList<Integer> stuffArrayList = new ArrayList<>();
        for(int i = 0 ; i < stuffArr.length ; i++) {
            if(!isRotten(stuffArr[i])) {
                stuffArrayList.add(stuffArr[i]);
            }
        }
        //사용할 수 있는 재료(ArrayList.size())가 choiceNum보다 작거나 0이면 null 반환
        if(stuffArrayList.size() == 0 || stuffArrayList.size() < choiceNum) {
            return null;
        }
        //순서 유효, 중복 제외
        ArrayList<Integer> cases = new ArrayList<>();
        boolean[] isUsed = new boolean[stuffArrayList.size()];
        recursion(choiceNum, cases, stuffArrayList, isUsed);

        return result;
    }
    public void recursion(int choiceNum, ArrayList<Integer> cases, ArrayList<Integer> stuffArrayList, boolean[] isUsed) {
        if(choiceNum == 0) {
            result.add(cases.stream().toArray(Integer[]::new));
            return;
        }

        for(int i = 0 ; i < stuffArrayList.size() ; i++) {
            if(!isUsed[i]) {
                isUsed[i] = true;
                ArrayList<Integer> temp = (ArrayList<Integer>) cases.clone();
                temp.add(stuffArrayList.get(i));
                recursion(choiceNum - 1, temp, stuffArrayList, isUsed);
                isUsed[i] = false;
            }
        }
    }

    //재료가 상했는지(0이 3개 이상) 판별하는 메서드
    public boolean isRotten(int stuff) {
        String stuff_string = Integer.toString(stuff);
        int count = 0;
        for(int i = 0 ; i < stuff_string.length() ; i++) {
            if(stuff_string.charAt(i) == '0') {
                count++;
                if(count == 3) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }
        return false;
    }
}
