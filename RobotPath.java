//세로와 가로의 길이가 각각 M, N인 방의 지도가 2차원 배열로 주어졌을 때,
//1은 장애물을 의미하고 0 이동이 가능한 통로를 의미합니다.
//로봇은 지도 위를 일분에 한 칸씩 상하좌우로 이동할 수 있습니다.
//로봇의 위치와 목표 지점이 함께 주어질 경우, 로봇이 목표 지점까지 도달하는 데 걸리는 최소 시간을 리턴해야 합니다.
//
//주의사항:
//M, N은 20 이하의 자연수입니다.
//src, dst는 항상 로봇이 지나갈 수 있는 통로입니다.
//src에서 dst로 가는 경로가 항상 존재합니다.

import java.util.ArrayList;
import java.util.List;

public class RobotPath {
    //TODO: 시간초과 해결
    List<Integer> result = new ArrayList<>();
    public int robotPath(int[][] room, int[] src, int[] dst) {

        int[][] visited = new int[room.length][room[0].length];

        recursive(room, visited, src, dst, 0);

        return result.stream().mapToInt(x -> x).min().orElseThrow(RuntimeException::new);
    }

    public void recursive(int[][] room, int[][] visited, int[] cur, int[] dst, int minute) {
        if(cur[0] == dst[0] && cur[1] == dst[1]) {
            result.add(minute);
        }

        if(cur[0] > 0 && room[cur[0] - 1][cur[1]] == 0 && visited[cur[0] - 1][cur[1]] == 0) {
            //UP
            cur[0] -= 1;
            visited[cur[0]][cur[1]] = 1;
            minute += 1;

            recursive(room, visited, cur, dst, minute);

            visited[cur[0]][cur[1]] = 0;
            cur[0] += 1;
            minute -= 1;
        }

        if(cur[0] < room.length - 1 && room[cur[0] + 1][cur[1]] == 0 && visited[cur[0] + 1][cur[1]] == 0) {
            //DOWN
            cur[0] += 1;
            visited[cur[0]][cur[1]] = 1;
            minute += 1;

            recursive(room, visited, cur, dst, minute);

            visited[cur[0]][cur[1]] = 0;
            cur[0] -= 1;
            minute -= 1;
        }

        if(cur[1] > 0 && room[cur[0]][cur[1] - 1] == 0 && visited[cur[0]][cur[1] - 1] == 0) {
            //LEFT
            cur[1] -= 1;
            visited[cur[0]][cur[1]] = 1;
            minute += 1;

            recursive(room, visited, cur, dst, minute);

            visited[cur[0]][cur[1]] = 0;
            cur[1] += 1;
            minute -= 1;
        }

        if(cur[1] < room[0].length - 1 && room[cur[0]][cur[1] + 1] == 0 && visited[cur[0]][cur[1] + 1] == 0) {
            //RIGHT
            cur[1] += 1;
            visited[cur[0]][cur[1]] = 1;
            minute += 1;

            recursive(room, visited, cur, dst, minute);

            visited[cur[0]][cur[1]] = 0;
            cur[1] -= 1;
            minute -= 1;
        }
    }
}
