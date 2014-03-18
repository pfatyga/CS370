import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Main
{
	public static int gcd(int a, int b) {
		if(b == 0)
			return a;
		return gcd(b, a % b);		
	}

	public static int lcm(int a, int b) {
		return a * b / gcd(a, b);
	}

    public static void main (String args[])  // entry point from OS
    {
        Main myWork = new Main();  // create a dynamic instance
        myWork.Begin();            // the true entry point
    }
    
    

    void Begin()
    {
    	Scanner scan = new Scanner(System.in);
        
    	int numCoins = scan.nextInt();
    	int numTables = scan.nextInt();
    	
    	int[] coin_heights = new int[50];
    	
    	while(numCoins != 0 && numTables != 0)
    	{
    		//get all the coins
    		for(int i = 0; i < numCoins; i++)
    			coin_heights[i] = scan.nextInt();
    		
    		//for each table
    		for(int i = 0; i < numTables; i++)
    		{
    			int tableHeight = scan.nextInt();
    			int max = Integer.MIN_VALUE;
    			int min = Integer.MAX_VALUE;
    			
    			//loop through all combinations of coins
    			for(int a = 0; a < numCoins; a++)
    				for(int b = a+1; b < numCoins; b++)
    					for(int c = b+1; c < numCoins; c++)
    						for(int d = c+1; d < numCoins; d++)
    						{
    							//lcm(a,b,c,d) = lcm(lcm(a,b), lcm(c,d))
    							int length = lcm(lcm(coin_heights[a], coin_heights[b]), lcm(coin_heights[c], coin_heights[d]));
    							//System.out.println(length);
    							int tMax = (tableHeight / length) * length;
    							int tMin;
    							if(tableHeight % length != 0)
    							{
    								tMin = (tableHeight / length + 1) * length;
    							} else {
    								tMin = (tableHeight / length) * length;
    							}
    							if(tMin < min)
    								min = tMin;
    							if(tMax > max)
    								max = tMax;
    						}
    			System.out.println(max + " " + min);
    		}
    		
    		numCoins = scan.nextInt();
        	numTables = scan.nextInt();
    	}
        
        
    }
    
}