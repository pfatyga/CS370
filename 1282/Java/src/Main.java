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
        
//        for(int i = 0; i <= 100; i++)
//        	System.out.println(i + ": " + mFib(i));
        
        //while ((input = Main.ReadLn (255)) != null)
        //{  
        int caseNum = 1;
        while((input = Main.ReadLn (255)) != null) {
    	  int n = Integer.parseInt(input);
          input = Main.ReadLn (255);
          idata = new StringTokenizer (input);
          String c = idata.nextToken();
          
          if(c.equals("1")) {
        	  System.out.println("Case " + (caseNum++) + ": " + fib(n));
        	  continue;
          }
          if(c.equals("0")) {
        	  if(n == 0)
        		  System.out.println("Case " + (caseNum++) + ": " + 1);
        	  else
        		  System.out.println("Case " + (caseNum++) + ": " + fib(n-1));
        	  continue;
          }
          
          int s = inverseFib(c.length())-1;
          //String basecase = F(s);         
          //String mergeFirst = basecase.substring(basecase.length()-(c.length()-1)) + F(s-1).substring(0, c.length());
          String secondMerge = F(s+2);
          //F(s).length() == fibonacci(s+1)
          int basecaseOccurences = match(secondMerge.substring(0, (fib(s+1).intValue())), c);
          int mergeFirstOccurences = match(secondMerge.substring(fib(s+1).intValue() - (c.length()-1), fib(s+1).intValue() + Math.min(fib(s).intValue(), c.length()-1)), c);
          int mergeSecondOccurences = match(secondMerge.substring(fib(s+2).intValue() - (c.length()-1), fib(s+2).intValue() + c.length()-1), c);
          
          //System.out.println(secondMerge.substring(0, (fib(s+1))));
          //System.out.println(secondMerge.substring(fib(s+1) - (c.length()-1), fib(s+1) + Math.min(fib(s), c.length()-1)));
          //System.out.println(secondMerge.substring(fib(s+2) - (c.length()-1), fib(s+2) + c.length()-1));
          
          //System.out.println("basecaseOccurences: " + basecaseOccurences + ", mergeFirstOccurences: " + mergeFirstOccurences + ", mergeSecondOccurences: " + mergeSecondOccurences);
   
          System.out.println("Case " + (caseNum++) + ": " + fib(n - s + 1).multiply(BigInteger.valueOf(basecaseOccurences)).add(mFib(n-s).multiply(BigInteger.valueOf(mergeFirstOccurences))).add(mFib(n - s - 1).multiply(BigInteger.valueOf(mergeSecondOccurences))));
        };
        
    }
    
    //1,1,3,4,8,12,21,33
    public static BigInteger mFib(int n)
    {
    	BigInteger first = new BigInteger("0");
    	BigInteger second = new BigInteger("0");
    	BigInteger next = new BigInteger("0");
    	BigInteger alt = new BigInteger("0");

    	n++;

    	for(int c = 0; c < n; c++)
    	{
    		next = first.add(second).add(alt);
    		first = second;
    		second = next;

    		if(!alt.equals(BigInteger.ZERO))
    			alt = BigInteger.ZERO;
    		else
    			alt = BigInteger.ONE;
    	}

    	return next;
    }
    
    //dont call for large n pls
    public static String F(int n) {    	
    	String prev = "0";
    	String current = "1";
    	for(int a = 1; a < n; a++) {
    		String temp = current;
    		current += prev;
    		prev = temp;
    	}
    	return current;
    }
    
    public static BigInteger fib(int n) {
    	BigInteger prev = new BigInteger("0");
    	BigInteger current = new BigInteger("1");
    	for(int a = 1; a < n; a++) {
    		BigInteger temp = current;
    		current = current.add(prev);
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