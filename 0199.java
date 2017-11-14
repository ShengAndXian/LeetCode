
import java.util.*;

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();

        queue.offer(root);

        while (!queue.isEmpty()) {
            int count = queue.size();

            while (count != 1) {
                TreeNode node = queue.poll();
                addChildNode(queue, node);
                count--;
            }

            TreeNode node = queue.poll();
            if (node != null) {
                res.add(node.val);
                addChildNode(queue, node);
            }
        }

        return res;
    }

    private void addChildNode(Queue<TreeNode> queue, TreeNode node) {
        if (node.left != null)
            queue.offer(node.left);
        if (node.right != null)
            queue.offer(node.right);
    }
}

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}