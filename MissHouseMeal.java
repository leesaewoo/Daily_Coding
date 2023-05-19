import java.util.Arrays;
//김코딩은 몇 년의 해외 출장 끝에 본가에 내려왔습니다.
// 오랜만에 보는 김코딩의 얼굴에 반가웠던 부모님은 상다리가 부러질 정도로 음식을 만들었습니다.
//밥은 한 가지이며 반찬은 다수일 때,
// 밥과 함께 먹을 수 있는 반찬의 모든 경우의 수를 배열에 담아 리턴하세요.
//
//입력
//인자 1: sideDishes
//String 타입의 영문으로 된 반찬이 나열되어 있는 배열
//
//출력
//ArrayList<String[]> 타입을 리턴해야 합니다.
//밥과 함께 먹을 수 있는 반찬의 모든 경우의 수가 담긴 배열을 포함한 ArrayList
//주의사항
//반찬은 영문으로 작성이 되어 있습니다.
//반찬은 중복되지 않습니다.
//반찬을 먹지 않는 것도 포함됩니다. (출력되는 2차원 배열은 빈 배열을 포함합니다.)
//반찬은 3개 이상 99개 이하입니다.
//출력되는 배열은 전부 오름차순으로 정렬되어야 합니다.
import java.util.ArrayList;
public class MissHouseMeal {
    ArrayList<String[]> result = new ArrayList<>();
    public ArrayList<String[]> missHouseMeal(String[] sideDishes) {
        Arrays.sort(sideDishes);
        String[] picked = new String[]{};
        recursion(sideDishes, 0, picked);

        result.sort((o1, o2) -> Arrays.toString(o1).compareTo(Arrays.toString(o2)));
        return result;
    }

    public void recursion(String[] sideDishes, int index, String[] picked) {
        if(index == sideDishes.length) {
            result.add(picked);
            return;
        }

        //뽑거나
        String[] newPicked = Arrays.copyOf(picked, picked.length + 1);
        newPicked[newPicked.length - 1] = sideDishes[index];
        recursion(sideDishes, index + 1, newPicked);
        //안뽑거나
        recursion(sideDishes, index + 1, picked);
    }
}
