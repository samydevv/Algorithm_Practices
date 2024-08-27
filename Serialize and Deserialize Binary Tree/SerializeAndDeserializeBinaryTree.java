class Node {
    public Node left = null;
    public Node right = null;
    public int value;

    Node(int value) {
        this.value = value;
    }

    Node(int value, Node left, Node right) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

public class SerializeAndDeserializeBinaryTree {

    public static void main(String[] args) {
        Node n7 = new Node(7);
        Node n5 = new Node(5);
        Node n4 = new Node(4);
        Node n6 = new Node(6);
        Node n8 = new Node(8, n7, null);
        Node n2 = new Node(2, n8, n5);
        Node n3 = new Node(3, n4, n6);
        Node n1 = new Node(1, n2, n3);

        // Serialize the tree
        StringBuilder postOrder = new StringBuilder("");
        SerializeBinaryTree(n1, postOrder);
        System.out.println("Serialized postorder: " + postOrder.toString());

        // Deserialize the tree back
        String serializedTree = postOrder.toString();
        Node deserializedRoot = DeserializeBinaryTree(serializedTree);
        StringBuilder resultPostOrder = new StringBuilder("");
        SerializeBinaryTree(deserializedRoot, resultPostOrder);
        System.out.println("Postorder of Deserialized Tree: " + resultPostOrder);
    }

    // Serialize the tree including null markers for missing children
    public static void SerializeBinaryTree(Node node, StringBuilder s) {
        if (node == null) {
            s.append("# ");  // Using '#' to mark null nodes
            return;
        }
        SerializeBinaryTree(node.left, s);
        SerializeBinaryTree(node.right, s);
        s.append(node.value).append(" ");
    }

    // Helper class to hold the index while deserializing
    static class Index {
        int index;
        Index(int index) {
            this.index = index;
        }
    }

    // Function to deserialize the binary tree from postorder string
    public static Node DeserializeBinaryTree(String postorder) {
        if (postorder == null || postorder.length() == 0) {
            return null;
        }

        String[] nodes = postorder.split(" ");
        Index index = new Index(nodes.length - 1);  // Start from the last element in the postorder array
        return buildTreeFromPostorder(nodes, index);
    }

    // Recursive function to build the tree from the postorder array
    private static Node buildTreeFromPostorder(String[] nodes, Index index) {
        // Base case
        if (index.index < 0 || nodes[index.index].equals("#")) {
            index.index--;  // Move to the previous element for null nodes
            return null;
        }

        // Create a new node with the current value
        Node root = new Node(Integer.parseInt(nodes[index.index]));
        index.index--;

        // Build the right and left subtrees (postorder: left, right, root -> process right first)
        root.right = buildTreeFromPostorder(nodes, index);
        root.left = buildTreeFromPostorder(nodes, index);

        return root;
    }
}
