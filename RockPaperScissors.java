import java.util.ArrayList;
//가위바위보 게임은 2인 이상의 사람이 동시에 '가위, 바위, 보'를 외치고
// 동시에 가위, 바위 또는 보 중에서 한 가지를 의미하는 손 모양을 내밀어 승부를 결정짓는 게임입니다.
// 세 판의 가위바위보 게임을 할 경우, 한 사람은 세 번의 선택(예. 가위, 가위, 보)을 할 수 있습니다.
// 입력받은 rounds만큼의 선택으로 가능한 모든 경우의 수를 구하는 함수를 작성합니다
//ArrayList가 담고있는 배열은 전체 경우의 수 중 한 가지 경우(총 세 번의 선택)를 의미하는 배열입니다.
//주의사항:
//최종적으로 리턴되는 배열의 순서는 가중치 적용 정렬(Weighted Sort)을 따릅니다.
//중요도는 'rock', 'paper', 'scissors' 순으로 높습니다.
public class RockPaperScissors {
    final static String[] format = {"rock", "paper", "scissors"};
    ArrayList<String[]> result = new ArrayList<>();
    public ArrayList<String[]> rockPaperScissors(int rounds) {
        String[] cases = new String[rounds];
        recursion(0, rounds, cases);
        return result;
    }

    public void recursion(int count, int rounds, String[] cases) {
        if(count == rounds) {
            String[] temp = new String[rounds];
            System.arraycopy(cases, 0, temp, 0, rounds);
            result.add(temp);
            return;
        }

        for(int i = 0 ; i < 3 ; i++) {
            cases[count] = format[i];
            recursion(count + 1, rounds, cases);
        }
    }
}
