/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class Infix {
    static boolean isValid(char ch)
    {
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z') || (ch>='0'&&ch<='9'))
        return true;
        else
        return false;
    }
    static int precedence(char ch)
    {
        if(ch=='+'||ch=='-')
        return 1;
        else if(ch=='*'||ch=='/')
        return 2;
        else if(ch=='^')
        return 3;
        else
        return -1;
    }
	public static void main (String[] args) {
	    
	    Scanner sc = new Scanner(System.in);
	    int t;
	    t = sc.nextInt();
	    String ss;
	    while(t-->0)
	    {
	        ss = sc.next();
	        char str[] = ss.toCharArray();
	        Stack<Character> s = new Stack<Character>();
	        String ans="";
	        for(int i=0;i<str.length;i++)
	        {
	            if(isValid(str[i]))
	            ans+=str[i];
	            else if(str[i] == '(')
	            s.push(str[i]);
	            else if(str[i]==')')
	            {
	                while(!s.empty() && s.peek()!='(' )
	                {
	                    ans+=s.peek();
	                    s.pop();
	                }
	                s.pop();
	            }
	            else
	            {
	                while(!s.empty() && precedence(str[i])<= precedence(s.peek()) )
	                {
	                    ans+=s.peek();
	                    s.pop();
	                }
	                s.push(str[i]);
	            }
	        }
	        while(!s.empty())
	        {
	            ans+=s.peek();
	            s.pop();
	        }
	        System.out.println(ans);
	    }
	    
		//code
	}
}