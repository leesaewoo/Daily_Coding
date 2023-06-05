//구구단을 구하는 코드를 인터페이스와 구현 객체로 작성했으며,
// GugudanProxy 클래스는 실행 시간 측정이라는 공통 사항 로직에 집중하고
// GugudanByForLoop 클래스와 GugudanByRecursion 클래스에서
// 구구단 계산에 대한 핵심 기능을 담당하도록 역할을 분리시킴
interface Gugudan {
    void calculate(int level, int startNum);
}

class GugudanByRecursion implements Gugudan {
    @Override
    public void calculate(int level, int startNum) {
        if(startNum > 9) {
            return;
        }
        System.out.printf("%d x %d = %d\n", level, startNum, level * startNum);
        calculate(level, ++startNum);
    }
}

class GugudanByForLoop implements Gugudan {
    @Override
    public void calculate(int level, int startNum) {
        for(int count = startNum ; count < 10 ; count++) {
            System.out.printf("%d x %d = %d\n", level, count, level * count);
        }
    }
}

class GugudanProxy implements Gugudan {
    private Gugudan delegator;

    public GugudanProxy(Gugudan delegator) {
        this.delegator = delegator;
    }
    @Override
    public void calculate(int level, int startNum) {
        long start = System.nanoTime();
        delegator.calculate(level, startNum);
        long end = System.nanoTime();
        System.out.printf("클래스명: = %s\n", delegator.getClass().getSimpleName());
        System.out.printf("실행 시간 = %d ms\n", (end - start));
        System.out.println("-------------------------------");
    }
}

public class GugudanTest {
    public static void main(String[] args) {
        GugudanByForLoop gugudanByForLoop = new GugudanByForLoop();
        System.out.println("🎯 for문 구구단 2단");

        GugudanProxy gp1 = new GugudanProxy(gugudanByForLoop);
        gp1.calculate(2, 1);

        GugudanByRecursion gugudanByRecursion = new GugudanByRecursion();
        System.out.println("\n🎯 재귀 구구단 2단");

        GugudanProxy gp2 = new GugudanProxy(gugudanByRecursion);
        gp2.calculate(2, 1);
    }
}
