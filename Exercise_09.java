import java.util.ArrayList;
import java.util.Arrays;
public class Exercise_09 {
    public static void main(String[] args) {
        int[] numbers = {1, -2, 3, -5, 8, -3};
        ArrayList<Integer> ar = new ArrayList<>();

        for(int i = 0 ; i < numbers.length ; i++) {
            if(numbers[i] < 0) {
                continue;
            }
            else {
                ar.add(numbers[i]);
            }
        }

        Integer[] result = ar.toArray(new Integer[ar.size()]);

        System.out.println(Arrays.asList(result));
    }
}