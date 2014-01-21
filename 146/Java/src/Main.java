import java.io.*;
import java.util.*;

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
        
        /*int num = 1;
        String start = "aaabbc";
        System.out.println(num++ + ": " + start);
        do {
        	start = next(start);
        	System.out.println(num++ + ": " + start);
        } while(!start.equals("No Successor") && num <= 60);*/
        
        while ((input = Main.ReadLn (255)) != null)
        {
          idata = new StringTokenizer (input);                          
          String i = idata.nextToken();
          if(i.equals("#"))
        	  return;
          System.out.println(next(i));
        }                           
        
    }
    
    //searches for the first letter from the right that has a smaller letter to the left
    public static int search(String s) {
    	for(int i = s.length()-1; i >= 0; i--) {
    		char letter = s.charAt(i);
    		for(int j = i - 1; j >= 0; j--) {
    			if(s.charAt(j) < letter)
    				return i;
    		}
    	}
    	return -1;
    }       
    
    public static String next(String s) {
    	if(s.length() < 2)
    		return "No Successor";
    	int targetLetterIndex = search(s);
    	if(targetLetterIndex == -1)
    		return "No Successor";
    	char targetLetter = s.charAt(targetLetterIndex);
    	int insertionIndex;
    	for(insertionIndex = targetLetterIndex-1; insertionIndex >= 0 && s.charAt(insertionIndex) >= targetLetter; insertionIndex--);
    	
    	String first = s.substring(0, insertionIndex);
    	String between = s.substring(insertionIndex, targetLetterIndex);
    	String after = s.substring(targetLetterIndex+1);
    	char[] everythingElse = (between + after).toCharArray();
    	Arrays.sort(everythingElse);
    	String everythingElseString = new String(everythingElse);
    	return first + targetLetter + everythingElseString;
    	
    }
    
}