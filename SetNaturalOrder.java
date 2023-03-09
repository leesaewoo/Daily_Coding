import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
/*
public class Sample {
    public static void main(String[] args) {
        ArrayList<Integer> arl = new ArrayList<>(Arrays.asList(1, 3, 5, 4, 2));
        System.out.println(arl);

        arl.sort(Comparator.naturalOrder());
        System.out.println(arl);
    }
}
 */

public class Sample {
    public static void main(String[] args) {
        ArrayList<Integer> arl = new ArrayList<>(Arrays.asList(1, 3, 5, 4, 2));

        for(int i = 0 ; i < arl.size() - 1 ; i++) {
            for(int j = i + 1 ; j < arl.size() ; j++) {
                setNaturalOrder(arl, i, j);
            }
        }

        System.out.println(arl);
    }

    static void setNaturalOrder(ArrayList<Integer> arl, int a, int b) {
        if(arl.get(a) > arl.get(b)) {
            int tmp = arl.get(a);
            arl.set(a, arl.get(b));
            arl.set(b, tmp);
        }
    }
}