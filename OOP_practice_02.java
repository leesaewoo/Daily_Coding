interface Predator {
    String getFood();
}
class Animal02 {
    String name;
    void setName(String name) {
        this.name = name;
    }
}

class Tiger extends Animal02 implements Predator {
    public String getFood() {
        return "apple";
    }
}

class Lion extends  Animal02 implements Predator {
    public String getFood() {
        return "orange";
    }
}

class Zookeeper {
    void feed(Predator predator) {
        System.out.printf("feed %s\n", predator.getFood());
    }
}

public class OOP_practice_02 {
    public static void main(String[] args) {
        Zookeeper zookeeper = new Zookeeper();
        Tiger tiger = new Tiger();
        Lion lion = new Lion();
        zookeeper.feed(tiger);
        zookeeper.feed(lion);
    }
}
