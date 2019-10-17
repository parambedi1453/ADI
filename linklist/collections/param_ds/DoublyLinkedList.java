package param_ds;
public class DoublyLinkedList<E>
{
    private static class Node<E>
    {
        private E element ;

        private Node<E>  prev;

        private Node<E> next;

        public Node(E e,Node<E> p,Node<E> n)
        {
            element = e;
            prev = p;
            next = n;
        }

        public E getElement()
        {return element;}

        public Node<E> getPrev()
        {return prev;}

        public Node<E> getNext()
        {return next;}

        public void setPrev(Node<E> p)
        {prev = p;}

        public void setNext(Node<E> n)
        {next = n ;}

    }

    private Node<E> head;
    private Node<E> tail;
    int size;

    public DoublyLinkedList()
    {
        head = null;
        tail = null;
        size =0;
    }
    public int size()
    {
        return size;
    }
    public boolean isEmpty()
    {
        return size==0;
    }
    public E first()
    {
        if (isEmpty()) return null;
        return head.getElement();
    }
    public E last()
    {
        if (isEmpty()) return null;
        return tail.getElement();
    }
    public void addFirst(E e)
    {
        head = new  Node<>(e,null,head);
        if(size == 0)
        tail = head;
        size++;
    }
    // public void compare(DoublyLinkedList<E> ob2)
    // {
    //     E a = first();
    //     E b = ob2.first();
    //     System.out.println(a);
    //     System.out.println(b);
    //     if(a>b)
    //     System.out.println(first());
    //     else
    //     System.out.println(ob2.first());
    //
    // }


    public void addLast(E e)
    {
        Node<E> newNode = new Node<>(e,null,null);
        if(isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail.setNext(newNode);
            newNode.setPrev(tail);
            tail = newNode;
        }
        size++;
    }
    public void printlist()
    {
        Node<E> k = head;
        while(k!=null)
        {
            System.out.print(k.getElement()+" ");
            k = k.getNext();
        }
        System.out.println("\n");
    }
    // private void addBetween(E e, Node<E> predecessor, Node<E> successor)
    // {
    //
    // }
    public void addBetween(int index,E e)
    {
        if(head == null)
        {
            addFirst(e);
            size++;
            return;
        }
        if(index == size)
        {
            addLast(e);
            size++;
            return ;
        }
        if(index>size)
        {
            System.out.println("Out of Bound Exception");
        }
        int c = 1;
        Node<E> k =head;
        while(k!=null)
        {
            if(c == index-1)
            {
                Node<E> btw = new Node<>(e,null,null);
                btw.setNext(k.getNext());
                btw.setPrev(k);
                k.setNext(btw);
                size++;
                return;
            }
            k=k.getNext();
            c++;
        }
    }
    // public E remove(Node<E> node)
    // {
    //
    // }
    // public String toString()
    // {
    //
    // }
}
