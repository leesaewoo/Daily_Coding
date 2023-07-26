//세로와 가로의 길이가 각각 M, N인 방의 지도가 2차원 배열로 주어졌을 때,
//1은 장애물을 의미하고 0 이동이 가능한 통로를 의미합니다.
//로봇은 지도 위를 일분에 한 칸씩 상하좌우로 이동할 수 있습니다.
//로봇의 위치와 목표 지점이 함께 주어질 경우, 로봇이 목표 지점까지 도달하는 데 걸리는 최소 시간을 리턴해야 합니다.
//
//주의사항:
//M, N은 20 이하의 자연수입니다.
//src, dst는 항상 로봇이 지나갈 수 있는 통로입니다.
//src에서 dst로 가는 경로가 항상 존재합니다.


import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class RobotPath {
    public int robotPath(int[][] room, int[] src, int[] dst) {
        boolean[][] visit = new boolean[room.length][room[0].length];

        int[][] distance = new int[room.length][room[0].length];
        for(int[] row : distance) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        distance[src[0]][src[1]] = 0;

        PriorityQueue<int[]> priorityQueue = new PriorityQueue<>(Comparator.comparingInt(a -> distance[a[0]][a[1]]));
        priorityQueue.offer(src);

        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!priorityQueue.isEmpty()) {
            int[] current = priorityQueue.poll();
            int x = current[0];
            int y = current[1];

            visit[x][y] = true;

            if(x == dst[0] && y == dst[1]) {
                return distance[x][y];
            }

            for(int[] dir : directions) {
                int nx = dir[0] + x;
                int ny = dir[1] + y;

                if(nx >= 0 && nx < room.length && ny >= 0 && ny < room[0].length && room[nx][ny] == 0 && !visit[nx][ny]) {
                    int newDistance = distance[x][y] + 1;
                    if(newDistance < distance[nx][ny]) {
                        distance[nx][ny] = newDistance;
                        priorityQueue.offer(new int[]{nx, ny});
                    }
                }
            }
        }

        throw new RuntimeException("No path found");
    }
}