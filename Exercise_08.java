import java.util.ArrayList;
class HeavyWork implements Runnable {
    String name;

    HeavyWork(String name) {
        this.name = name;
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            try {
                Thread.sleep(100);  // 0.1 초 대기한다.
            } catch (Exception e) {
            }
        }
        System.out.printf("%s done.\n", this.name);
    }
}

public class Exercise_08 {
    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        ArrayList<Thread> threadList = new ArrayList<>();

        for (int i = 1; i < 5; i++) {
            Thread w = new Thread(new HeavyWork("w" + i));
            w.start();
            threadList.add(w);
        }

        for (int i = 0 ; i < threadList.size() ; i++) {
            Thread w = threadList.get(i);
            try {
                w.join();
            }catch (Exception e) {
            }
        }
        long end = System.currentTimeMillis();
        System.out.printf("elapsed time:%s ms\n", end - start);
    }
}