class Calculator {
    int value;

    Calculator() {
        this.value = 0;
    }

    void add(int val) {
        this.value += val;
    }

    void minus(int val) {
        this.value -= val;
    }

    int getValue() {
        return this.value;
    }
}

class MaxLimitCalculator extends Calculator {
    int getValue() {
        if(this.value > 100) {
            return 100;
        }
        else {
            return this.value;
        }
    }
}
public class Exercise_01 {
    public static void main(String[] args) {
        MaxLimitCalculator cal = new MaxLimitCalculator();
        cal.add(10);
        cal.minus(3);
        cal.add(94);
        System.out.println(cal.getValue());
    }
}