//자신이 감옥에 간 사이 연인이었던 줄리아를 앤디에게 빼앗겨 화가 난 조지는
// 브레드, 맷과 함께 앤디 소유의 카지노 지하에 있는 금고를 털기로 합니다.
// 온갖 트랩을 뚫고 드디어 금고에 진입한 조지와 일행들.
// 조지는 이와중에 감옥에서 틈틈이 공부한 알고리즘을 이용해
// target 금액을 훔칠 수 있는 방법의 경우의 수를 계산하기 시작합니다.
//
//예를 들어 $50 을 훔칠 때 $10, $20, $50 이 있다면 다음과 같이 4 가지 방법으로 $50을 훔칠 수 있습니다.
//
//1. $50 한 장을 훔친다
//2. $20 두 장, $10 한 장을 훔친다
//3. $20 한 장, $10 세 장을 훔친다
//4. $10 다섯 장을 훔친다
//
//훔치고 싶은 target 금액과 금고에 있는 돈의 종류 type 을 입력받아,
// 조지가 target 을 훔칠 수 있는 방법의 수를 리턴하세요.
//
//target: int 타입의 100,000 이하의 자연수
//type: int 타입을 요소로 갖는 100 이하의 자연수를 담은 배열
//
//주의사항:
//모든 화폐는 무한하게 있다고 가정합니다.
public class CoinChange {
    public long coinChange(int target, int[] type) {
        long[][] coinChange = new long[type.length + 1][target + 1];
        coinChange[0][0] = 1;

        for(int i = 0 ; i < type.length ; i++) {
            for(int j = 0 ; j < target + 1 ; j++) {
                if(type[i] > j && j >= 0) {
                    coinChange[i + 1][j] = coinChange[i][j];
                }
                else {
                    coinChange[i + 1][j] = coinChange[i + 1][j - type[i]] + coinChange[i][j];
                }
            }
        }

        return coinChange[type.length][target];
    }
}
