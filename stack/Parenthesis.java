/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class Parenthesis {
	public static void main (String[] args) {
		//code
		Scanner sc  = new Scanner(System.in);
		int t = sc.nextInt();
		String ss;
		while(t-->0)
		{
		    ss = sc.next();
		    char str[] = ss.toCharArray();
		    Stack<Character> s = new Stack<Character>();
		    
		    int flag = 0;
		    for(int i=0;i<str.length;i++)
		    {
		        if(str[i]=='(' || str[i]=='{' || str[i]== '[')
		        {
		            s.push(str[i]);
		        }
		        else 
		        {
		            if(str[i]==')'&&!s.empty() &&s.peek()=='(')
		            s.pop();
		            else if(str[i]==']' && !s.empty() && s.peek()=='[')
		            s.pop();
		            else if(str[i] == '}' && !s.empty() && s.peek() =='{')
		            s.pop();
		            else
		            {
		                flag=1;
		                break;
		            }
		            
		        }
		    }
		    if(flag==1)
		    System.out.println("not balanced");
		    else if(s.empty() ==false)
		    System.out.println("not balanced");
		    else
		    System.out.println("balanced");
		    
		}
	}
}