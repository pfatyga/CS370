import java.io.*;
import java.util.*;
//import java.util.Arrays;

class Main {
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
		final int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
							43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
							101, 103, 107, 109, 113, 127, 131, 137, 139, 149,
							151, 157, 163, 167, 173, 179, 181, 191, 193, 197,
							199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
							263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
							317, 331, 337, 347, 349, 353, 359, 367, 373, 379,
							383, 389, 397, 401, 409, 419, 421, 431, 433, 439,
							443, 449, 457, 461, 463, 467, 479, 487, 491, 499,
							503, 509, 521, 523, 541, 547, 557, 563, 569, 571,
							577, 587, 593, 599, 601, 607, 613, 617, 619, 631,
							641, 643, 647, 653, 659, 661, 673, 677, 683, 691,
							701, 709, 719, 727, 733, 739, 743, 751, 757, 761,
							769, 773, 787, 797, 809, 811, 821, 823, 827, 829,
							839, 853, 857, 859, 863, 877, 881, 883, 887, 907,
							911, 919, 929, 937, 941, 947, 953, 967, 971, 977,
							983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033,
							1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091,
							1093, 1097, 1103, 1109, 1117, 1123, 1129};
		int[][] result = new int[1121][15];
		int siz;
		int inp;
		int prm;
		int n;
		int r;

		result[0][0] = 1;
		//for(i = 0; i < 1121; i++)
			//result[i][0] = 1;
		
		//need prime loop first to prevent repeats
		for(prm = 0; prm < 189; prm++)
		{
			for(inp = 1120; inp >= primes[prm]; inp--) //need to decrement to prevent
			{
				for(siz = 1; siz < 15; siz++)
				{
					result[inp][siz] += result[inp - primes[prm]][siz - 1];
					//if(inp <= 24 && siz <= 3 && result[inp - primes[prm]][siz - 1] != 0)
					//	System.out.println("GOT " + primes[prm] + ": [" + inp + "][" + siz + "] = " + result[inp][siz]);
				}
			}
		}
		
		/*
		for(i=0;i<189;i++)
	        for(j=1120;j>=primes[i];j--)
	            for(k=1;k<15;k++)
	            	result[j][k]+=result[j-primes[i]][k-1];
		*/
		//System.out.println("");
        while (true) {
        	input = Main.ReadLn (255);
        	idata = new StringTokenizer (input);
            n = Integer.parseInt(idata.nextToken());
            r = Integer.parseInt(idata.nextToken());
            if (n == 0 && r == 0)
                break;
            System.out.println(result[n][r]);
        }
		
	}
}
