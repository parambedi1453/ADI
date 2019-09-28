// GEEKS FOR GEEKS 
// Link https://practice.geeksforgeeks.org/problems/right-sibling-in-binary-tree/1


// {
//     import java.util.*;
//     import java.util.Scanner;
//     import java.util.HashSet;
//     import java.lang.Math;
//         class Node
//         {
//             int data;
//             Node left,right,parent;
//             Node(int d) {data = d; left =right= parent=null; }
//             Node(){}
//         }
//     public class GFG2
//     {
//         public static Node node,prev;
//         public static void inorder(Node root,int key)
//         {
//             if(root==null)
//             return;
//             inorder(root.left,key);
//             if(root.data==key)
//             node=root;
//             inorder(root.right,key);
//         }
//         public static void main(String args[])
//         {
//              Scanner sc = new Scanner(System.in);
//              int t=sc.nextInt();
             
//              while(t-->0)
//              {  
//                 int n = sc.nextInt();
//                 GFG2 llist=new GFG2();
//                 Node root=null,parent1=null;
//                 HashMap<Integer, Node> m = new HashMap<>();
//                 for(int i=0;i<n;i++)
//                 {
//                     int a=sc.nextInt();
//                     int b=sc.nextInt();
//                     char c=sc.next().charAt(0);
//                     if(m.containsKey(a)==false)
//                     {
//                         parent1=new Node(a);
//                         m.put(a,parent1);
//                         if(root==null)
//                         root=parent1;
//                     }
//                     else
//                         parent1=m.get(a);
//                     Node child=new Node(b);
//                     if(c=='L'){
//                     parent1.left=child;
//                     child.parent=parent1;}
//                     else{
//                     parent1.right=child;
//                     child.parent=parent1;}
//                     m.put(b,child);
//                 }
//                 int key=sc.nextInt();
//                 llist.inorder(root,key);
//                 llist.node=node;
//                 GFG obj = new GFG();
//                 Node ans=obj.findRightSibling(llist.node);
//                 if(ans!=null)
//                 System.out.println(ans.data);
//                 else
//                 System.out.println("-1");
//             }
//         }
//     }
//     }
    /*This is a function problem.You only need to complete the function given below*/
    /*class Node
    {
        int data; 
        Node left, right,parent; 
        Node(int d)
        {
            data = d;
            left = right =parent= null;
        }
    }*/
    //function should return the right sibling of the given node.
    class GFG
    {
        
     
        public static Node findRightSibling(Node node)
        {
            Queue<Node> q = new LinkedList<Node>();
            if(node.parent==null)
            return null;
            Node real = node;
            
            Node root=null;
            while(node.parent!=null)
            node=node.parent;
            root = node;
            
         
            
            q.add(root);
            int found=0;
            while(q.size()!=0)
            {
                Node temp = q.remove();
                if(temp==real)
                {
                    Node ans;
                    if(q.size()!=0)
                    {
                        ans = q.remove();
                        return ans;
                    }
                
                }
                if(temp.left!=null)
                {
                   
                    q.add(temp.left);
                }
                if(temp.right!=null)
                {
                    q.add(temp.right);
                }
            }
            return null;
            //Your code here
        }
    }