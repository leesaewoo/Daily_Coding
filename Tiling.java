//세로 길이 2, 가로 길이 n인 2 x n 보드가 있습니다.
// 2 x 1 크기의 타일을 가지고 이 보드를 채우는 모든 경우의 수를 리턴해야 합니다.
//주의사항:
//타일을 가로, 세로 어느 방향으로 놓아도 상관없습니다.
public class Tiling {
    static int[] cache = new int[1000];

    public Tiling() {
        cache[0] = 1;
        cache[1] = 1;
    }

    public int tiling(int num) {
        if(num == 0 || num == 1) {
            return cache[num];
        }

        if(cache[num] == 0) {
            int result = tiling(num - 2) + tiling(num - 1);
            cache[num] = result;
            return result;
        }
        else {
            return cache[num];
        }
    }
}
