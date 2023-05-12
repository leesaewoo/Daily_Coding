//수를 입력받아 2의 거듭제곱인지 여부를 리턴해야 합니다.
//주의 사항:
//반복문(while)문을 사용해야 합니다.
//2의 0승은 1입니다.
//Math.log 사용은 금지됩니다.
public class PowerOfTwo {
    public boolean powerOfTwo(long num) {
        if(num == 1) {
            return true;
        }

        while(num > 1) {
            if(num % 2 == 0) {
                num = num / 2;
            }
            else {
                return false;
            }
        }

        return true;
    }
}
