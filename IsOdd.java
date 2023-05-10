//수를 입력받아 홀수인지 여부를 리턴해야 합니다.
public class IsOdd {
    public boolean isOdd(int num) {
        if(num == 0) {
            return false;
        }
        else if(num == -1) {
            return true;
        }

        return isOdd(Math.abs(num) - 2);
    }
}
