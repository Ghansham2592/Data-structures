import java.util.*;

public class AVLTree {



    private Node rightRotate(Node root){
        Node newRoot = root.left;
        root.left = root.left.right;
        newRoot.right = root;
        root.height = setHeight(root);
        newRoot.height = setHeight(newRoot);
        return newRoot;
    }
    private Node leftRotate(Node root){
        Node newRoot = root.right;
        root.right = root.right.left;
        newRoot.left = root;
        root.height = setHeight(root);
        newRoot.height = setHeight(newRoot);
        return newRoot;
    }

    private int setHeight(Node root){
        if(root == null){
            return 0;
        }
        return 1 + Math.max((root.left != null ? root.left.height : 0), (root.right != null ? root.right.height : 0));
    }

    private int height(Node root){
        if(root == null){
            return 0;
        }else {
            return root.height;
        }
    }

    public Node inorderSuccessor(Node root){
        Node temp = root;
        while(temp.left != null){
            temp = temp.left;
        }
        return temp;
    }


    public Node insert(Node root, int data){
        //normal bst approach
        if(root == null){
            return Node.newNode(data);
        }
        if(root.data <= data){
            root.right = insert(root.right,data);
        }
        else{
            root.left = insert(root.left,data);
        }
        //normal bst approach end here

        int balance = height(root.left) - height(root.right);
        if(balance > 1){
            if(height(root.left.left) >= height(root.left.right)){
                root = rightRotate(root);
            }else{
                root.left = leftRotate(root.left);
                root = rightRotate(root);
            }
        }else if(balance < -1){
            if(height(root.right.right) >= height(root.right.left)){
                root = leftRotate(root);
            }else{
                root.right = rightRotate(root.right);
                root = leftRotate(root);
            }
        }
        else{
            root.height = setHeight(root);
        }
        return root;
    }

    public Node deleteNode(Node root, int val){
        if(root == null){
            return root;
        }
        if(val < root.data){
            root.left = deleteNode(root.left, val);
        }
        else if( val > root.data){
            root.right  = deleteNode(root.right, val);
        }
        else{
            Node temp =null;
            if(root.left == null || root.right ==null){

                if(root.left != null){
                    temp = root.left;
                }
                else{
                    temp = root.right;
                }
                root = temp;
            }
            else{
                temp = inorderSuccessor(root.right);
                root.data = temp.data;
                root.right = deleteNode(root.right, temp.data);
            }

        }
        if (root == null){
            return root;
        }
        int balance = height(root.left) - height(root.right);
        if(balance > 1){
            if(height(root.left.left) >= height(root.left.right)){
                root = rightRotate(root);
            }else{
                root.left = leftRotate(root.left);
                root = rightRotate(root);
            }
        }else if(balance < -1){
            if(height(root.right.right) >= height(root.right.left)){
                root = leftRotate(root);
            }else{
                root.right = rightRotate(root.right);
                root = leftRotate(root);
            }
        }
        else{
            root.height = setHeight(root);
        }
        return root;

    }

    public static void main(String args[]){
        AVLTree avlTree = new AVLTree();
        TreeTraversals tt = new TreeTraversals();
        Node root = null;
        String s1 = " ";
        Scanner sc = new Scanner(System.in);
//        System.out.println("Please enter your request (i=insert, d=delete, p=print e=exit) :");
//        s1 = sc.next();
        int num= 0;
        String inputChar, inputNum;
        String[] spltArray;
        boolean flag = true;
        while(flag){
            System.out.print("Please enter your request (i=insert, d=delete, p=print e=exit) :");
            s1 = sc.next();
            if(s1.equals("i") || s1.equals("d")){
                num = sc.nextInt();
            }

            switch (s1){
                case "i" :
                    root = avlTree.insert(root,num);
                    System.out.println(num + " Inserted successfully");
                    break;
                case "d" :
                    root = avlTree.deleteNode(root, num);
                    System.out.println(num + " Deleted successfully");
                    break;
                case "p" :
                    System.out.print("AVL Tree: ");
                    tt.preOrder(root);
                    System.out.println();
                    break;
                case "e" :  System.out.print("Bye");
                    flag = false;
                    break;

            }
        }
//        root = avlTree.insert(root, 20);
//        root = avlTree.insert(root, 10);
//        root = avlTree.insert(root, 5);
//        root = avlTree.insert(root, 9);
//        root = avlTree.insert(root, 3);
//        root = avlTree.insert(root, 1);
//        root = avlTree.insert(root, 12);
//        root = avlTree.insert(root, 8);p
//        root = avlTree.insert(root, 5);
//        root = avlTree.insert(root, 4);
//        root = avlTree.insert(root, 7);
//        root = avlTree.insert(root, 6);

//        System.out.println();
//        tt.preOrder(root);
//        root = avlTree.deleteNode(root, 12);
//        System.out.println("delete");
//        tt.preOrder(root);

    }
}
class Node{
    Node left;
    Node right;
    int data;

    int height;
    public static Node newNode(int data){
        Node n = new Node();
        n.left = null;
        n.right = null;
        n.data = data;
        n.height = 1;
        return n;
    }
}
class TreeTraversals {
    public void preOrder(Node root){
        if(root == null){
            System.out.print("NULL,");
            return;
        }
        System.out.print("(");
        System.out.print(root.data + ",");
        preOrder(root.left);
        preOrder(root.right);
        if(root.left ==null && root.right ==null){
            System.out.print("),");
        }
        else
            System.out.print(")");
    }
}
