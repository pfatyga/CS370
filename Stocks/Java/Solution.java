import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int num_testcases = 0;
		num_testcases = reader.nextInt();

		for(int i = 0; i < num_testcases; i++)
		{
			int N;	//number of stock prices
			int[] prices;

			N = reader.nextInt();
			prices = new int[N];

			for(int j = 0; j < N; j++)
			{
				prices[j] = reader.nextInt();
			}

			int[] next_max = new int[N+1];
			next_max[N] = -1;

			for(int j = N - 1; j >= 0; j--)
				next_max[j] = Math.max(prices[j], next_max[j+1]);

			long profit = 0;
			long num_stocks = 0;

			for(int j = 0; j < N; j++)
			{
				int price = prices[j];
				int max_price = next_max[j+1];

				if(price > max_price)
				{
					profit += num_stocks * price;
					num_stocks = 0;
				}
				else if (price < max_price)
				{
					num_stocks += 1;
					profit -= price;
				}
			}

			System.out.println(profit);

		}
	}
}
