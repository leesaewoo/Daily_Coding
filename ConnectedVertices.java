import java.util.Queue;
import java.util.LinkedList;
public class ConnectedVertices {
    public int connectedVertices(int[][] edges) {
        Queue<Integer> queue = new LinkedList<>();
        int count = 0;

        int max = 0;
        for (int[] a : edges) {
            if (max < Math.max(a[0], a[1])) {
                max = Math.max(a[0], a[1]);
            }
        }

        int[] visit = new int[max + 1];

        int[][] edge = new int[max + 1][max + 1];

        for (int[] a : edges) {
            edge[a[0]][a[1]] = 1;
            edge[a[1]][a[0]] = 1;
        }

        for (int i = 0 ; i < edges.length ; i++) {
            if (visit[edges[i][0]] == 0) {
                queue.offer(edges[i][0]);
                visit[edges[i][0]] = 1;
                count++;
            }

            while (!queue.isEmpty()) {
                int node = queue.poll();
                for (int j = 0 ; j < edge[node].length ; j++) {
                    if (edge[node][j] == 1 && visit[j] == 0) {
                        queue.offer(j);
                        visit[j] = 1;
                    }
                }
            }
        }

        return count;
    }
}
