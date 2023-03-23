import java.util.ArrayList;
import java.util.Arrays;
class AverageCalculator {
    double avg(ArrayList<Integer> list) {
        double total = 0;

        for(int i = 0 ; i < list.size() ; i++) {
            total += list.get(i);
        }

        return total / list.size();
    }
}
public class Exercise_03 {
    public static void main(String[] args) {
        ArrayList<Integer> data = new ArrayList<>(Arrays.asList(1, 3, 5, 6, 9));
        AverageCalculator cal = new AverageCalculator();
        System.out.println(cal.avg(data));
    }
}
