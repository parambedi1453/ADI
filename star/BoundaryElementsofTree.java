// GEEKS PRACTICE CODE 
// link  https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1


// {
//     // INITIAL CODE
//     import java.util.*;
//     import java.lang.*;
//     import java.io.*;
//     // A Binary Tree node
//     class Node
//     {
//         int data;
//         Node left, right;
//         Node(int item)
//         {
//             data = item;
//             left = right = null;
//         }
//     }
//     class Boundary_Traversal
//     {
//         int height(Node node)
//             {
//                 if(node==null)
//                     return 0;
//                 int l = 1+height(node.left);
//                 int r = 1+height(node.right);
//                 if(l>r)
//                     return l;
//                 else
//                     return r;
//             }
        
//         // driver function to test the above functions
//         public static void main(String args[])
//         {
            
//             // Input the number of test cases you want to run
//             Scanner sc = new Scanner(System.in);
//             int t = sc.nextInt();
//             //Node root=null;
//             while (t > 0)
//             {
//                 HashMap<Integer, Node> m = new HashMap<Integer, Node> ();
//                 int n = sc.nextInt();
//                 Node root=null;
//                 while (n > 0)
//                 {
//                     int n1 = sc.nextInt();
//                     int n2 = sc.nextInt();
//                     char lr = sc.next().charAt(0);
//                     //  cout << n1 << " " << n2 << " " << (char)lr << endl;
//                     Node parent = m.get(n1);
//                     if (parent == null)
//                     {
//                         parent = new Node(n1);
//                         m.put(n1, parent);
//                         if (root == null)
//                             root = parent;
//                     }
//                     Node child = new Node(n2);
//                     if (lr == 'L')
//                         parent.left = child;
//                     else
//                         parent.right = child;
//                     m.put(n2, child);
//                     n--;
//                 }
            
//                 GfG g = new GfG();
//                 g.printBoundary(root);
//                 System.out.println();
//                 t--;
                
//             }
//         }
//     }
//     }
    /*This is a function problem.You only need to complete the function given below*/
    /* A Binary Tree node
    class Node
    {
        int data;
        Node left, right;
        Node(int item)
        {
            data = item;
            left = right = null;
        }
    }*/
    class GfG
    {
        public Queue<Node> s = new LinkedList<Node>();
        public Stack<Node> ss = new Stack<Node>();
        public void getRightNodes(Node rightRoot)
        {
            if(rightRoot==null)
            return;
            if(rightRoot.left==null && rightRoot.right==null)
            return;
            
            ss.push(rightRoot);
            if(rightRoot.right!=null)
            getRightNodes(rightRoot.right);
            else if(rightRoot.right==null && rightRoot.left!=null)//that is it is also a boundary node
            getRightNodes(rightRoot.left);
        }
        public void getLeftNodes(Node leftRoot)
        {
            if(leftRoot==null)
            return;
            if(leftRoot.left==null && leftRoot.right==null)
            return;
            
            s.add(leftRoot);
            if(leftRoot.left!=null)
            getLeftNodes(leftRoot.left);
            else if(leftRoot.left==null && leftRoot.right!=null)
            getLeftNodes(leftRoot.right);
        }
        public void getleafNodes(Node root)
        {
            if(root==null)
            return;
            if(root.left==null &&root.right==null)
            s.add(root);
            
            getleafNodes(root.left);
            getleafNodes(root.right);
          
        }
        void printBoundary(Node root)
        {
            s.add(root);
            getLeftNodes(root.left);
            getleafNodes(root);
            getRightNodes(root.right);
           
           
           
            while(s.size()!=0)
            {
                Node temp = s.remove();
                System.out.print(temp.data+" ");
            }
            while(ss.empty()==false)
            {
                Node t = ss.pop();
                 System.out.print(t.data+" ");
            }	    
            // Your code here
        }
    }