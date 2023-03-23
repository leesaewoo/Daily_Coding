class EOCalculator {
    private int value;
    EOCalculator() {
        this.value = 2;
    }

    public void isOdd(int val) {
        int result = val % value;

        if(result == 0) {
            System.out.println("Even");
        }
        else {
            System.out.println("Odd");
        }
    }
}
public class Exercise_02 {
    public static void main(String[] args) {
        EOCalculator cal = new EOCalculator();
        cal.isOdd(3);
        cal.isOdd(4);
    }
}
