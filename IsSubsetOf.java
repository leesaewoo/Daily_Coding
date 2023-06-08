import java.util.*;
import java.util.stream.Collectors;

//두 개의 배열(base, sample)을 입력받아 sample이 base의 부분집합인지 여부를 리턴해야 합니다.
//주의사항:
//base, sample 내에 중복되는 요소는 없다고 가정합니다.
//sample.length는 50,000 이하
public class IsSubsetOf {
    public boolean isSubsetOf(int[] base,  int[] sample) {
        Set<Integer> set_base = new HashSet<>(Arrays.stream(base).boxed().collect(Collectors.toList()));
        Set<Integer> set_sample = new HashSet<>(Arrays.stream(sample).boxed().collect(Collectors.toList()));

        Set<Integer> mergedSet = new HashSet<>();
        mergedSet.addAll(set_base);
        mergedSet.addAll(set_sample);

        if(mergedSet.size() == set_base.size()) {
            return true;
        }
        return false;
    }
}
