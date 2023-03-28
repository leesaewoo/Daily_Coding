class Singleton {
    static Singleton one;
    private Singleton() {

    }

    public static Singleton getInstance() {
        if(one == null){
            one = new Singleton();
        }
        return one;
    }
}
public class Exercise_07 {
    public static void main(String[] args) {
        Singleton singleton1 = Singleton.getInstance();
    }
}
