import java.util.*;

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
    	 outer: for(int a = 0; a < numCoins; a++)
    				for(int b = a+1; b < numCoins; b++)
    					for(int c = b+1; c < numCoins; c++)
    						for(int d = c+1; d < numCoins; d++)
    						{
                                //calculate least common multiple of 4 coins
    							//lcm(a,b,c,d) = lcm(lcm(a,b), lcm(c,d))
    							int height = lcm(lcm(coin_heights[a], coin_heights[b]), lcm(coin_heights[c], coin_heights[d]));
    							
    							if(tableHeight % height == 0)
    							{	//if it is divisible by tableHeight then we're done because the max and min are both tableHeight
    								min = max = tableHeight;
    								break outer;
    							}
    							else
    							{
	    							max = Math.max(max, (tableHeight / height) * height);	//calculate max < tableHeight using integer division: (1000 / 400) * 400 = (2) * 400 = 800    						
	    							min = Math.min(min, (tableHeight / height + 1) * height);	//same thing except get the multiple after the tableHeight	    								    							
    							}
    						}
    			System.out.println(max + " " + min);
    		}
    		
    		numCoins = scan.nextInt();
        	numTables = scan.nextInt();
    	}
        
        
    }
    
}
