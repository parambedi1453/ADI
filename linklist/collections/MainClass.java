import java.util.*;

class Buffer{
    static int count=0;
    public void display(){
        System.out.print("Hello ");
        synchronized(this){
            count++;
            System.out.println(count);
        }

    }
}


class ThreadDemo extends Thread{
    Buffer b;
    ThreadDemo(Buffer b){
        this.b=b;
        start();
    }
    public void run(){
        b.display();
    }
}

class MainClass{
    public static void main(String args[]){
        Buffer b=new Buffer();
        ThreadDemo td1=new ThreadDemo(b);
        ThreadDemo td2=new ThreadDemo(b);
    }
}
