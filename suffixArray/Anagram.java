import java.util.*;
public class Anagram
{
    public static String  sortString(String str)
    {
        char a[]  = str.toCharArray();
        Arrays.sort(a);

        return  (new String(a));
    }
    public static void main(String args[])
    {
        String arr[] = {"abb","bba","bat","tab","cab","crazy"};

        //sorting individual string
        for(int i=0;i<arr.length;i++)
        {
            arr[i] = sortString(arr[i]);
        } 

         // Sorted array of strings
        String temp;
        for(int i=0;i<arr.length;i++)
        {
            for(int j=i+1;j<arr.length;j++)
            {
                if(arr[i].compareTo(arr[j])>0)
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j]=temp;
                }
            }
        }

        int c =0;
        for(int i=0;i<arr.length-1;i++)
        {
            System.out.println(arr[i]);
            if(arr[i].equals(arr[i+1]))
            c++;
        }

        System.out.println(c);
       
       

    }
}