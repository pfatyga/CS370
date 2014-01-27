import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Main
{
	//private static final int NUM_FIBS = 100;
	//private static BigInteger fibonacciNums[] = new BigInteger[NUM_FIBS+1];
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
          String basecase = F(s);
          int basecaseOccurences = match(basecase, c);
          //System.out.println("basecase: " + basecase + ", numOccurences: " + basecaseOccurences);
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