class Animal {
    private String name;
    private String sex;
    private int age;
    private int weight;
    public Animal(String name, String sex, int age, int weight) {
        this.name = name;
        this.sex = sex;
        this.age = age;
        this.weight = weight;
    }
    void printVal() {
        System.out.printf("name: %s\nsex: %s\nage: %d\nweight: %d\n", this.name, this.sex, this.age, this.weight);
    }
}

class Cat extends Animal {
    private final String catCode;
    public Cat(String catCode, String name, String sex, int age, int weight) {
        super(name, sex, age, weight);
        this.catCode = catCode;
    }
    void printcatCode() {
        System.out.println("catCode: " + this.catCode);
    }
}
public class OOP_practice_01 {
    public static void main(String[] args) {
        Cat cat1 = new Cat("abcdefg", "navi", "male", 4, 11);
        Cat cat2 = new Cat("hijk", "ddong", "female", 3, 8);

        System.out.println("Cat1");
        cat1.printVal();
        cat1.printcatCode();
        System.out.println("\nCat2");
        cat2.printVal();
        cat2.printcatCode();
    }
}