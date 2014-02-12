import java.io.*;
import java.math.BigInteger;
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
        
        while ((input = Main.ReadLn (255)) != null)
        {
          idata = new StringTokenizer (input);                          
          BigInteger n = new BigInteger(idata.nextToken());          
          
          		//if(n % 2) aka if(n % 2 != 0)
          if (!(n.mod(new BigInteger("2")).equals(BigInteger.ZERO)))
          {
			if (n.equals(BigInteger.ONE))
			{
				System.out.println("1");
			}
			else
			{
				n = n.add(BigInteger.ONE).divide(new BigInteger("2"));//(n + 1) / 2;
				System.out.println(n.multiply(n).multiply(new BigInteger("6")).subtract(new BigInteger("9")));
				//cout << 6 * n * n - 9 << endl;
			}
          }
          else
          {
        	  System.out.println("0");
        	  //cout << 0 << endl;
          }
          
        }                           
        
    }

}