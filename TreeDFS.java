//임의의 tree를 구성하는 노드 중 하나의 Node 객체를 입력받아,
// 해당 노드를 시작으로 깊이 우선 탐색(DFS, Depth First Search)을 합니다.
// 이 때, 탐색되는 순서대로 노드의 값이 저장된 배열을 리턴해야 합니다.

import java.util.*;
import java.util.stream.Collectors;

public class TreeDFS {
    public ArrayList<String> dfs(TreeDFS.tree node) {
        ArrayList<String> result = new ArrayList<>();
        if(node.children == null) {
            return result;
        }

        Stack<tree> stack = new Stack<>();
        stack.push(node);

        while(!stack.isEmpty()) {
            tree currentTree = stack.pop();
            result.add(currentTree.getValue());
            if(currentTree.children != null) {
                ArrayList<tree> childrenNode = currentTree.getChildrenNode();
                childrenNode = (ArrayList<tree>)childrenNode.stream()
                        .sorted(Comparator.comparing(tree::getValue).reversed())
                        .collect(Collectors.toList());
                for(tree t : childrenNode) {
                    stack.push(t);
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
            if(children == null) children = new ArrayList<>();
            children.add(node);
            return children.get(children.size() - 1);
        }

        public String getValue() {      //현재 노드의 데이터를 반환
            return value;
        }

        public ArrayList<tree> getChildrenNode() {
            return children;
        }
    }
}

