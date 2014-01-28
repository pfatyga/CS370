import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Main
{
    static String ReadLn (int maxLg)  // utility function to read from stdin
    {
        byte lin[] = new byte [maxLg];
        int lg = 0, car = -1;
        String line = "";

        try
        {
            while (lg < maxLg)
            {
                car = System.in.read();
                if ((car < 0) || (car == '\n')) break;
                lin [lg++] += car;
            }
        }
        catch (IOException e)
        {
            return (null);
        }

        if ((car < 0) && (lg == 0)) return (null);  // eof
        return (new String (lin, 0, lg));
    }

    public static void main (String args[])  // entry point from OS
    {
        Main myWork = new Main();  // create a dynamic instance
        myWork.Begin();            // the true entry point
    }
    
    

    void Begin()
    {
        String input;
        StringTokenizer idata;
        
        while ((input = Main.ReadLn (255)) != null)
        {
          idata = new StringTokenizer (input);                          
          String c = idata.nextToken();
          int s = inverseFib(c.length())-1;
          //String basecase = F(s);         
          //String mergeFirst = basecase.substring(basecase.length()-(c.length()-1)) + F(s-1).substring(0, c.length());
          String secondMerge = F(s+2);
          //F(s).length() == fibonacci(s+1)
          int basecaseOccurences = match(secondMerge.substring(0, (fibonacci(s+1))), c);
          int mergeFirstOccurences = match(secondMerge.substring(fibonacci(s+1) - (c.length()-1), fibonacci(s+1) + Math.min(fibonacci(s), c.length()-1)), c);
          int mergeSecondOccurences = match(secondMerge.substring(fibonacci(s+2) - (c.length()-1), fibonacci(s+2) + c.length()-1), c);
          
          System.out.println(secondMerge.substring(fibonacci(s+1) - (c.length()-1), fibonacci(s+1) + Math.min(fibonacci(s), c.length()-1)));
          System.out.println(secondMerge.substring(fibonacci(s+2) - (c.length()-1), fibonacci(s+2) + c.length()-1));
          
          System.out.println("basecaseOccurences: " + basecaseOccurences + ", mergeFirstOccurences: " + mergeFirstOccurences + ", mergeSecondOccurences: " + mergeSecondOccurences);
        }                      
        
        
    }       
    
    //dont call for large n pls
    public static String F(int n) {    	
    	String prev = "0";
    	String current = "1";
    	for(int a = 1;a < n; a++) {
    		String temp = current;
    		current += prev;
    		prev = temp;
    	}
    	return current;
    }
    
    public static int fibonacci(int n) {
    	int prev = 0;
    	int current = 1;
    	for(int a = 1;a < n; a++) {
    		int temp = current;
    		current += prev;
    		prev = temp;
    	}
    	return current;
    }
    
    //find first fibonacci number >= length
    public static int inverseFib(int length) {    	
    	
    	int num = 1;
    	int prev = 0;
    	int current = 1;
    	for(;current < length; num++) {
    		current += prev;
    		prev = current - prev; 
    	}
    	return num;
    }
    
    public static int match(String str, String pattern) {    	
        Pattern p = Pattern.compile(pattern);
        Matcher m = p.matcher(str);
        int count = 0;
        while (m.find()){
        	count +=1;
        }
        return count;
    }
    
}