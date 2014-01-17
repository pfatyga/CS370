// @JUDGE_ID:  1000AA  100  Java  "Easy algorithm"

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
        
        Robot r = null;
        Grid g = null;
        
        int width = 0; 
        int height = 0;
        
        int x = 0;
        int y = 0;
        char dir = 'N';
        
        String instructions = "";
        
        while ((input = Main.ReadLn (255)) != null)
        {
          idata = new StringTokenizer (input);
          
          if(idata.hasMoreTokens())
        	  width = Integer.parseInt (idata.nextToken());        	  
          else
        	  continue;
          
          if(idata.hasMoreTokens()) {
        	  height = Integer.parseInt (idata.nextToken());
        	  g = new Grid(width+1, height+1);
        	  break;
          } else
        	  continue;          
                             
        }
        
        do {
	        while ((input = Main.ReadLn (255)) != null)
	        {
	          
	          idata = new StringTokenizer (input);
	          
	          if(idata.hasMoreTokens())
	        	  x = Integer.parseInt (idata.nextToken());        	  
	          else
	        	  continue;
	          
	          if(idata.hasMoreTokens())
	        	  y = Integer.parseInt (idata.nextToken());        	  
	          else
	        	  continue;          
	          
	          if(idata.hasMoreTokens()) {
	        	  dir = (idata.nextToken()).charAt(0);
	        	  r = new Robot(x, y, dir, g);
	        	  break;
	          } else
	        	  continue;
	          
	        }
	        
	        input = Main.ReadLn (255);
	        idata = new StringTokenizer (input);
	        instructions = idata.nextToken();
	        r.simulate(instructions);
	        
	        System.out.println(r);
        } while (input != null);
    }
    
    private class Grid {
    	private int width;
    	private int height;
    	
    	private boolean smell[][];
    	
    	public Grid(int width, int height) {
    		this.width = width;
    		this.height = height;
    		smell = new boolean[width][height];
    	}
    	
    	public boolean canFallOff(int x, int y) {
    		return !smell[x][y];
    	}
    	
    	public boolean isValid(int x, int y) {
    		return x >= 0 && x < width & y >= 0 && y < height;
    	}
    	
    	public void fellOff(int x, int y) {
    		smell[x][y] = true;
    	}
    	
    	public int getWidth() {
    		return width;
    	}
    	
    	public int getHeight() {
    		return height;
    	}
    }
    
    private class Robot {
    	private int x;
    	private int y;
    	private char dir;
    	private boolean isLost = false;
    	
    	private Grid g;
    	
    	public Robot(int x, int y, char dir, Grid g) {
    		this.x = x;
    		this.y = y;
    		this.dir = dir;
    		this.g = g;
    	}
    	
    	@Override
    	public String toString() {
    		if(isLost)
    			return x + " " + y + " " + dir + " LOST";
    		else
    			return x + " " + y + " " + dir;
    	}
    	
    	public void simulate(String instructions) {
    		for(char instruction: instructions.toCharArray()) {
    			step(instruction);
    		}
    	}
    	
    	private void step(char instruction) {
    		if(isLost)
    			return;
    		switch (instruction) {
    		case 'L':
    			turnLeft();
    			break;
    		case 'R':
    			turnRight();
    			break;
    		case 'F':
    			moveForward();
    			break;
    		}
    		//System.out.println(this);
    	}
    	
    	private void turnLeft() {
    		switch (dir) {
    		case 'N':
    			dir = 'W';
    			break;
    		case 'W':
    			dir = 'S';
    			break;
    		case 'S':
    			dir = 'E';
    			break;
    		case 'E':
    			dir = 'N';
    			break;
    		}
    	}    	
    	
    	private void turnRight() {
    		switch (dir) {
    		case 'N':
    			dir = 'E';
    			break;
    		case 'W':
    			dir = 'N';
    			break;
    		case 'S':
    			dir = 'W';
    			break;
    		case 'E':
    			dir = 'S';
    			break;
    		}
    	}
    	
    	private void moveForward() {
    		int prevX = x;
    		int prevY = y;
    		switch (dir) {
    		case 'N':
    			y++;
    			break;
    		case 'W':
    			x--;
    			break;
    		case 'S':
    			y--;
    			break;
    		case 'E':
    			x++;
    			break;
    		}
    		if(!g.isValid(x, y) && !g.canFallOff(prevX, prevY)) {	//if the robot fell off from a smelly area then revert x and y back
    			x = prevX;
    			y = prevY;
    			//ignore instruction
    		}
    		if(!g.isValid(x, y)) {
    			isLost = true;
    			g.fellOff(prevX, prevY);
    			x = prevX;
    			y = prevY;
    		}
    	}    	
    	
    }
}