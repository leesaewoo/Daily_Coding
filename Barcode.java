//1, 2, 3으로만 이루어진 수열 바코드를 만들어야 합니다.
// 무조건 1, 2, 3만 붙여서 바코드를 만들었다면 쉬웠겠지만,
// 아쉽게도 바코드를 만드는 데에 조건이 걸려 있습니다.
// 바코드에서 인접한 두 개의 부분 수열이 동일하다면 제작할 수 없다고 할 때,
// 주어진 길이 len의 바코드 중 가장 작은 수를 반환하는 함수를 작성하세요.
public class Barcode {
    public String barcode(int len) {
        return findNum("", len);
    }

    public String findNum(String str, int len) {
        if (str.length() == len) {
            return str;
        }

        for(int i = 1 ; i <= 3 ; i++) {
            String temp = str + i;

            if (isMakeAble(temp)) {
                String result = findNum(temp, len);
                if(result != null) {
                    return result;
                }
            }
        }
        return null;
    }

    public boolean isMakeAble(String str) {
        int half = (str.length() / 2);
        for (int i = 1 ; i <= half ; i++) {
            if (str.substring(str.length() - i).equals(str.substring(str.length() - (i * 2), str.length() - i))) {
                return false;
            }
        }
        return true;
    }
}
