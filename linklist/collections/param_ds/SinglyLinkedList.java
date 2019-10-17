package param_ds;
public class SinglyLinkedList
{
    private static class Node
    {
        private int element;
        private Node next;

        public Node(int e,Node n)
        {
            element = e;
            next = n;
        }
        public int getElement()
        {
            return element;
        }
        public Node getNext()
        {
            return next;
        }
        public void setNext(Node n)
        {
            next = n;
        }
    }

    private Node head = null;

    private Node tail = null;

    private int size = 0;

    public SinglyLinkedList()
    {
        head=null;
        tail=null;
        size = 0;
    }
    public void mergeList(SinglyLinkedList ob1,SinglyLinkedList ob2)
    {
        Node k1 = ob1.head;
        Node k2 = ob2.head;
        while(k1!=null && k2!=null)
        {
            int a = k1.getElement();
            int b = k2.getElement();
            if(k1.getElement()<k2.getElement())
            {
                addLast(a);
                k1 = k1.getNext();
            }
            else
            {
                addLast(b);
                k2=k2.getNext();
            }
        }
        while(k1!=null)
        {
            int a = k1.getElement();
            k1 = k1.getNext();
        }
        while(k2!=null)
        {
            int b = k2.getElement();
            k2 = k2.getNext();
        }
    }
    public int size()
    {
        return size;
    }
    public boolean isEmpty()
    {
        if(head == null)
        return true;
        else
        return false;
    }
    public int first()
    {

        return head.getElement();
    }
    public int last()
    {

        return tail.getElement();
    }
    public void addFirst(int e)
    {
        head = new Node(e,head);
        if(size==0)
        tail = head;
        size++;
    }
    public void addLast(int e)
    {
        Node newNode = new Node(e,null);
        if(tail == null)
        {
            tail = newNode;
            head = newNode;
        }
        else
        {
            tail.setNext(newNode);
            tail = newNode;
        }
        size++;
    }
    public int removeFirst()
    {
        int k = head.getElement();
        head = head.getNext();
        size--;
        return k;
    }
    public void addInBetween(int e,int index)
    {

        if(head == null)
        {
            addFirst(e);
            size++;
            return ;
        }
        if(index == size)
        {
            addLast(e);
            size++;
            return;
        }
        if(index>size)
        {
            System.out.println("Out of Bound Exception");
        }

        int c =  1;
        Node k = head;
        while(k!=null)
        {
            if(c==index-1)
            {
                Node btw = new Node(e,null);
                btw.setNext(k.getNext());
                k.setNext(btw);
                size++;
                return;
            }
            c++;
            k=k.getNext();
        }

    }
    public void printlist()
    {
        Node k = head;
        while(k!=null)
        {
            System.out.print(k.getElement()+" ");
            k = k.getNext();
        }
        System.out.println("\n");
    }

    // public String toString()
    // {
    //
    // }

}
