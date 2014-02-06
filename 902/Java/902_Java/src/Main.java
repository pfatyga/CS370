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
        Main myWork = new Main();  // create a dinamic instance
        myWork.Begin();            // the true entry point
    }

    void Begin()
    {
        String input;
        StringTokenizer idata;
        int n;
        String text;
        String code;
        ArrayList<CharTree> root;
        StrIntPair ret;
		StrIntPair temp;
        int i;
        int j;

        //System.out.println();
        //fill & count
        while ((input = Main.ReadLn (255)) != null)
        {
          idata = new StringTokenizer (input);
          if(idata.countTokens() == 1)
          {
        	  n = Integer.parseInt (idata.nextToken());
        	  input = Main.ReadLn (255);
        	  text = input;
          }
          else
          {
        	  n = Integer.parseInt (idata.nextToken());
        	  text = idata.nextToken();
          }
          root = new ArrayList<CharTree>();
          
          //System.out.println("Input: " + n + " " + text);
          
          j = 0;
          
          if(n != 0 && n < text.length())
          {
          while(j <= text.length() - n)
          {
        	  code = text.substring(j, j + n);
        	  //System.out.println("Code: " + code);
        	  //System.out.println("root.size() = " + root.size());
        	  for(i = 0; i < root.size() && root.get(i).c != code.charAt(0); i++); //System.out.println(i);
        	  
        	  if(i == root.size())
      			{
        		  //System.out.println("root: new node " + code.charAt(0));
      				root.add(new CharTree(code.charAt(0)));
      				if(code.length() != 1)
      				{
      					//System.out.println("root: " + code.charAt(0) + ".addCode()");
      					root.get(i).addCode(code.substring(1));
      				}
      			}
        	  else
      			{
      				if(code.length() != 1)
      				{
      					//System.out.println("root: " + code.charAt(0) + ".addCode()");
      					root.get(i).addCode(code.substring(1));
      				}
      				else
      				{
      					root.get(i).count++;
      				}
      			}
        	  j++;
          }
          
          //find max count
  			ret = root.get(0).getMax();
  			for(i = 1; i < root.size(); i++)
  			{
  				temp = root.get(i).getMax();
  				if(ret.getInt() < temp.getInt())
  					ret = temp;
  			}
  		
  			System.out.println(ret.getString());
          }
          else
          {
        	  System.out.println();
          }
        }
    }
    
    private class CharTree
    {
    	public char c;
    	public long count;
    	ArrayList<CharTree> children;
    	
    	public CharTree(char c)
    	{
    		this.c = c;
    		this.count = 1;
    		children = new ArrayList<CharTree>();
    	}
    	
    	public void addCode(String code)
    	{
    		int i;
    		
    		for(i = 0; i < children.size() && this.children.get(i).c != code.charAt(0); i++);
    		
    		if(i == children.size())
    		{
    			//System.out.println(this.c + ": new node " + code.charAt(0));
    			children.add(new CharTree(code.charAt(0)));
    			if(code.length() != 1)
    			{
    				//System.out.println(this.c + ": " + code.charAt(0) + ".addCode()");
    				this.children.get(i).addCode(code.substring(1));
    			}
    			else
    			{
    				//System.out.println("New Leaf: " + code);
    			}
    		}
    		else
    		{
    			if(code.length() != 1)
    			{
    				//System.out.println(this.c + ": " + code.charAt(0) + ".addCode()");
    				this.children.get(i).addCode(code.substring(1));
    			}
    			else
    			{
    				this.children.get(i).count++;
    				//System.out.println(this.c + ": count++ = " + this.count);
    			}
    		}
    	}
    	
    	public StrIntPair getMax()
    	{
    		StrIntPair ret;
    		StrIntPair temp;
    		int i;
    		
    		if(this.children.size() == 0)
    		{
    			//System.out.println(this.c + ": count = " + this.count);
    			ret = new StrIntPair((new Character(this.c)).toString(),this.count);
    			//System.out.println("RAW COUNT = " + this.count);
    		}
    		else
    		{
    			//System.out.println(this.c + ": " + this.children.get(0).c + ".getMax() Start");
    			ret = this.children.get(0).getMax();
    			//System.out.println(this.c + ": " + this.children.get(0).c + ".getMax() Done");
    			for(i = 1; i < this.children.size(); i++)
    			{
    				//System.out.println("i = " + i + ", children.size() = " + children.size());
    				//System.out.println(this.c + ": " + this.children.get(i).c + ".getMax() Start");
    				temp = this.children.get(i).getMax();
    				//System.out.println(this.c + ": " + this.children.get(i).c + ".getMax() Done");
    				if(ret.getInt() < temp.getInt())
    					ret = temp;
    			}
    			ret.setString((new Character(this.c)).toString() + ret.getString());
    		}
    		//System.out.println(this.c + ": Return " + ret.getString() + ", " + ret.getInt());
    		return ret;
    	}
    	
    }
    
    private class StrIntPair
	{
		String str;
		long n;
		
		public StrIntPair(String str, long n)
		{
			this.str = str;
			this.n = n;
		}
		
		public void setString(String str){this.str = str;}
		public String getString(){return str;}
		public long getInt(){return n;}
	}
}