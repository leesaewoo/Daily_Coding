import java.util.ArrayList;
import java.util.Arrays;
/*
public class SetNaturalOrder {
    public static void main(String[] args) {
        ArrayList<Integer> arl = new ArrayList<>(Arrays.asList(1, 3, 5, 4, 2));
        System.out.println(arl);

        arl.sort(Comparator.naturalOrder());
        System.out.println(arl);
    }
}
 */
class Comparison {
    /** 오름차순으로 정렬해주는 매서드 **/
    void sortNaturalOrder(ArrayList<Integer> arl) {
        for(int i = 0 ; i < arl.size() - 1 ; i++) {
            for(int j = i + 1 ; j < arl.size() ; j++) {
                if(arl.get(i) > arl.get(j)) {
                    int tmp = arl.get(i);
                    arl.set(i, arl.get(j));
                    arl.set(j, tmp);
                }
            }
        }
    }

}
public class NaturalOrder {
    public static void main(String[] args) {
        ArrayList<Integer> arl = new ArrayList<>(Arrays.asList(1, 3, 5, 4, 2));

        Comparison call = new Comparison();

        call.sortNaturalOrder(arl);

        System.out.println(arl);
    }
}
