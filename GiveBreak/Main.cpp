#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

class department{
public:
	int num_employees; //number of employees
	unsigned long total_payroll; //total
	department();
};

department::department()
{
	num_employees = 0;
	total_payroll = 0;
}

class school{
public:
	map<short, department> departments; //departments within the school
	int num_employees; //number of employees
	unsigned long total_school_payroll; //total
	school();
};

school::school()
{
	num_employees = 0;
	total_school_payroll = 0;
}

int main()
{
	char line[12]; //input
	char buff[3]; //for char* manipulations
	school school_list[10]; //list of schools
	short input_school_id; //school id from last input
	short input_depart_id; //department id from last input
	unsigned long input_payment; //payment from last input
	int absolute_total_employees = 0;
	unsigned long absolute_total_payroll = 0;

	cin >> line;
	while (strcmp(line, "9999999999")) //test for last line
	{
		input_school_id = (short)(*line - '0'); //convert single characters into shorts by subtracting '0'
		strncpy(buff, &line[1], 2); //prep buff for atoi
		buff[2] = '\0'; //add end character
		input_depart_id = (short)atoi(buff); //convert to (short)int
		input_payment = (unsigned long)atoi(&line[3]);

		cout << input_payment << endl;

		absolute_total_employees++;
		absolute_total_payroll += input_payment;
		school_list[input_school_id].num_employees++;
		school_list[input_school_id].total_school_payroll += input_payment;
		school_list[input_school_id].departments[input_depart_id].num_employees++;
		school_list[input_school_id].departments[input_depart_id].total_payroll += input_payment;

		cin >> line; //get next line
	}

	for (int i = 0; i < 10; i++) //for each school
	{
		if (school_list[i].num_employees) //test if school is used
		{
			for (auto it = school_list[i].departments.begin(); it != school_list[i].departments.end(); it++)
			{ //for each department within the school
				cout << i << " "
					<< it->first << " "
					<< it->second.num_employees << " "
					<< fixed << setprecision(2) << (it->second.total_payroll / 100.0) << endl;
			}
			cout << "School tots: "
				<< school_list[i].num_employees << " "
				<< fixed <<setprecision(2) << (school_list[i].total_school_payroll/100.0) << endl;
		}
	}

	cout << "abs tots: "
		<< absolute_total_employees << " "
		<< fixed << setprecision(2) << (absolute_total_payroll / 100.0) << endl;

	return 0;
}