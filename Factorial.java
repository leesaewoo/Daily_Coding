//수를 입력받아 n-factorial(n!; 엔-팩토리얼) 값을 리턴해야 합니다.
//n! 은 1부터 n까지 1씩 증가한 모든 값의 곱입니다.
public class Factorial {
    public int factorial(int num) {
        if(num == 0) {
            return 1;
        }

        return num * factorial(num - 1);
    }
}
