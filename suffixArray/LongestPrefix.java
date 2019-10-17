import java.util.*;
public class LongestPrefix
{

    public static int findMinLen(String a[],int n)
    {
        int l = Integer.MAX_VALUE;
        for(int i=0;i<n;i++)
        {
            if(a[i].length()<l)
            l=a[i].length();
        }
        return l;
    }
    public static String findPre(String a1,String a2,int len)
    {
        String ans  = "";
        for(int i=0;i<len;i++)
        {
           if(a1.charAt(i)!=a2.charAt(i))
           break;
           else
           ans = ans+a1.charAt(i);
        }
        return ans;
    }
    public static void main(String args[])
    {
       String a[] = {"paramveer", "parkk", 
                               "pat", "paaaaaaaa"}; 
        int n = a.length; 
        int len  = findMinLen(a,n);
        String prefix="";
        String a1 = a[0];
        String a2 = a[1];
        for(int i=0;i<len;i++)
        {
           if(a1.charAt(i)!=a2.charAt(i))
           break;
           else
           prefix = prefix+a1.charAt(i);
        }
        if(prefix=="")
        {
            System.out.println("No prefix found");
            System.exit(0);
        }
        for(int i=3;i<n;i++)
        {
            prefix = findPre(a[i],prefix,prefix.length());
            if(prefix=="")
            {
                System.out.println("No prefix found");
                System.exit(0);
            }
        }
        System.out.print(prefix);
    }
}