//임의의 tree를 구성하는 노드 중 하나의 Node 객체를 입력받아,
// 해당 노드를 시작으로 너비 우선 탐색(BFS, Breadth First Search)을 합니다.
// 이 때, 탐색되는 순서대로 노드의 값이 저장된 배열을 리턴해야 합니다.

import java.util.*;
import java.util.stream.Collectors;

public class TreeBFS {
    public ArrayList<String> bfs(TreeBFS.tree node) {
        ArrayList<String> result = new ArrayList<>();
        if (node.children == null) {
            return result;
        }

        Queue<tree> queue = new LinkedList<>();
        queue.add(node);

        while (!queue.isEmpty()) {
            tree currentTree = queue.poll();
            result.add(currentTree.getValue());
            if (currentTree.children != null) {
                ArrayList<tree> childrenNode = currentTree.getChildrenNode();
                for (tree t : childrenNode) {
                    queue.add(t);
                    System.out.println(t.getValue());
                }
            }
        }
        return result;
    }

    public static class tree {
        private String value;
        private ArrayList<tree> children;

        public tree(String data) {
            this.value = data;
            this.children = null;
        }

        public tree addChildNode(tree node) {
            if (children == null) children = new ArrayList<>();
            children.add(node);
            return children.get(children.size() - 1);
        }

        public String getValue() {
            return value;
        }

        public ArrayList<tree> getChildrenNode() {
            return children;
        }
    }
}
