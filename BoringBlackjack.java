import java.util.ArrayList;
//평범한 블랙잭 게임에서 수시로 패배하자 흥미가 떨어진 김코딩은
// 박타짜에게 게임룰을 변형하여 새로운 카드 놀이를 해 볼 것을 제안합니다.
//새로운 룰은 다음과 같습니다.
//
//1. 숫자로 이루어진 카드를 여러 장 받습니다.
//2. 3장씩 카드를 고르고, 3장에 적힌 숫자들의 합이 소수인지 확인합니다.
//3. 받아든 카드로 만들 수 있는 소수의 개수가 많은 사람이 이기게 됩니다.
//
//예로, [1, 2, 3, 4]라는 카드를 받았을 때 만들 수 있는 숫자는 6, 7, 8, 9이고,
// 소수는 7 하나이기 때문에 가지고 있는 소수의 개수는 1개입니다.
//[2, 3, 4, 8, 13]라는 카드를 받았을 때 만들 수 있는 숫자는 9, 13, 18, 14, 19, 23, 15, 20, 24, 25이고,
// 소수는 13, 19, 23 총 3개이기 때문에 가지고 있는 소수의 개수는 3개입니다.
//
//여러 장의 카드 중 세 장씩 조합해 소수가 되는 경우의 수를 리턴하는 함수를 완성해 주세요.
//
//int[] cards:
//배열의 크기는 3 이상 50 이하
//중복된 숫자는 들어있지 않습니다.
//배열의 요소는 1이상 1,000이하의 자연수입니다.
public class BoringBlackjack {
    ArrayList<Integer> result = new ArrayList<>();
    public int boringBlackjack(int[] cards) {
        //여러 장의 카드 중 세 장씩 조합해 소수가 되는 경우의 수를 리턴
        //중복된 숫자는 없음
        //소수인지 판별하는 메서드 필요함
        //주어진 카드 중 세 장(순서 상관 X, 중복 X) 골라서 합한 수를 소수판별하여 소수면 count++
        //고르는 카드의 수가 정해져 있으므로, 3중 반복문 사용
        recursion(cards, 0, 3, 0);
        int count = 0;
        for(int i = 0 ; i < result.size() ; i++) {
            if(isPrimeNumber(result.get(i))) {
                count++;
            }
        }
        return count;
    }

    public void recursion(int[] cards, int index, int choiceNum, int sum) {
        if(choiceNum == 0) {
            result.add(sum);
            return;
        }

        if(index > cards.length - choiceNum) {
            return;
        }

        //뽑거나
        int newSum = sum + cards[index];
        recursion(cards, index + 1, choiceNum - 1, newSum);
        //안뽑거나
        recursion(cards, index + 1, choiceNum, sum);
    }

    //소수인지 판별하는 메서드
    public boolean isPrimeNumber(int number) {
        for(int i = 2 ; i < number / 2 ; i++) {
            if(number % i == 0) {
                return false;
            }
        }
        return true;
    }
}