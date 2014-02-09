#include <iostream>

using namespace std;

void print_non_repeating(char *string, int num)
{
	cout << "[" << num-1 << "]" << string;
}

void print_repeating(char c, int num)
{
	cout << "[" << num+127 << "]" << c;
}

int main () 
{    
	char current = 0;
	char previous = 0;
	char string[129];
	int count = 0;
	bool repeating = false;

	string[128] = '\0';
	
	while(!cin.eof()) {
		//get first 2 characters before entering main loop
		do {
			//cout << "getting prev";
			cin.get(previous);
			if(cin.eof())
				return 0;
			if(previous == '\n')
				continue;	
			cin.get(current);
			if(current == '\n')
			{
				cout << "[0]" << previous << '\n';				
				continue;
			}
			if(current == previous)
				repeating = true;
			else
			{
				string[0] = previous;
				string[1] = current;
			}
			count = 2;
		} while(previous == '\n' || current == '\n' || previous == 0 || current == 0);

		//cout << "main loop";
		while (cin.get(current)) {		
			if(current == '\n') 
			{
				//finish current state
				if(repeating)
					print_repeating(previous, count);
				else
				{
					string[count] = '\0';
					print_non_repeating(string, count);
				}
				cout << '\n';
				//reset state
				current = 0;
				previous = 0;
				count = 0;
				repeating = false;			
				break;
			}

			if(repeating) {
				if(current == previous)
				{
					count++;
					if(count == 128)
					{
						print_repeating(current, count);
						count = 0;
						break;	
					}
				}
				else	//no longer repeating
				{
					print_repeating(previous, count);				
					string[0] = current;				
					repeating = false;					
					previous = current;							
					count = 1;
				}	
			}
			else	//non repeating case
			{
				if(current != previous)
				{
					string[count++] = current;
					previous = current;
					if(count == 128)	//max limit for non-repeating characters
					{					
						print_non_repeating(string, count);
						//reset
						count = 0;
						break;
					}
				}
				else	//changed to repeating
				{
					string[count-1] = '\0';	//replace the last character with string terminator since it is now part of a repeating series
					print_non_repeating(string, count-1);
					count = 2;
					repeating = true;
				}			
			}
		}
		if(cin.eof())
		{
			if(repeating)
				print_repeating(previous, count);
			else
			{
				string[count-1] = '\0';
				print_non_repeating(string, count);
			}
			cout << '\n';
			//reset state
			current = 0;
			previous = 0;
			count = 0;
			repeating = false;			
			break;
		}
	}	
}
