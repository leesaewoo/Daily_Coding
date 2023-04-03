class Calculator_16 {
    private int[] data;
    Calculator_16(int[] data) {
        this.data = data;
    }

    double sum() {
        double sum = 0;
        for(int i = 0 ; i < this.data.length ; i++) {
            sum += this.data[i];
        }
        return sum;
    }

    double avg() {
        double avg;
        double sum = 0;
        for(int i = 0 ; i < this.data.length ; i++) {
            sum += this.data[i];
        }
        avg = sum / this.data.length;
        return avg;
    }
}
public class Exercise_16 {
    public static void main(String[] args) {
        int[] data1 = {1,2,3,4,5};
        Calculator_16 cal1 = new Calculator_16(data1);
        System.out.println(cal1.sum()); // 15 출력
        System.out.println(cal1.avg()); // 3.0 출력

        int[] data2 = {6,7,8,9,10};
        Calculator_16 cal2 = new Calculator_16(data2);
        System.out.println(cal2.sum()); // 40 출력
        System.out.println(cal2.avg()); // 8.0 출력
    }
}
