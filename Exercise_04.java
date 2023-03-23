interface Mineral {
    int add();
}

class Gold implements Mineral {
    public int add() {
        return 100;
    }
}

class Silver implements Mineral {
    public int add() {
        return 90;
    }
}

class Bronze implements Mineral {
    public int add() {
        return 80;
    }
}
class MineralCalculator {
    int value = 0;
    public void add(Mineral mineral) {
        this.value += mineral.add();
    }

    public int getValue() {
        return this.value;
    }
}
public class Exercise_04 {
    public static void main(String[] args) {
        MineralCalculator cal = new MineralCalculator();
        cal.add(new Gold());
        cal.add(new Silver());
        cal.add(new Bronze());

        System.out.println(cal.getValue());
    }
}