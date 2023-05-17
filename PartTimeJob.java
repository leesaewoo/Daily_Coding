import java.util.HashMap;
//편의점에서 아르바이트를 하고 있는 중에,
// 하필이면 피크 시간대에 손님에게 거스름돈으로 줄 동전이 부족하다는 것을 알게 되었습니다.
//현재 가지고 있는 동전은 1원, 5원, 10원, 50원, 100원, 500원으로 오름차순으로 정렬되어 있고,
// 각 동전들은 서로 배수 관계에 있습니다.
//동전 개수를 최소화하여 거스름돈 k를 만들어야 합니다.
//이때, 필요한 동전 개수의 최솟값을 구하는 함수를 작성해 주세요.
//1 <= k <= 100,000,000
public class PartTimeJob {
    public int partTimeJob(int k) {
        int change = k;
        HashMap<Integer, Integer> coins_HashMap = new HashMap<>() {{
            put(500, 0);
            put(100, 0);
            put(50, 0);
            put(10, 0);
            put(5, 0);
            put(1, 0);
        }};
        final int[] coins_Array;
        coins_Array = new int[]{500, 100, 50, 10, 5, 1};
        int total = 0;

        while(change != 0) {
            for(int coin : coins_Array) {
                int numOfCoin = change / coin;
                coins_HashMap.put(coin, numOfCoin);
                change -= coin * numOfCoin;
                total += numOfCoin;
            }
        }
        return total;
    }
}
