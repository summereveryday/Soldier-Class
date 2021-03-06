// Daily_Summer_Mod8_Soldier.cpp : Defines the entry point for the console application.
// Author: Summer Daily
// Last Updated: 10/20/18
// Purpose: Class that processes rank, pay, and other info for soldiers. Illustrates class, overloaded operators, and vectors.

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class soldier
{
friend ostream& operator<<(ostream&, const soldier&);

public:
	soldier(string, int);
	string pay();
	string getName();
	string getRank();
	void toString();

	//overloaded operators//
	bool operator==(const soldier&);
	bool operator<(const soldier&);
	soldier operator++();
	soldier operator++(int);
	soldier operator--();
	soldier operator--(int);

private:
	string name;
	int rank;
	int classification;
	string str_classification[4] = {"none", "Enlisted", "Warrant", "Officer" };
	string str_rank[30] = { "none", "Private", "Private Second Class", "Private First Class", "Speciliast", "Corporal", "Sergeant", "Staff Seargeant", "Sergeant First Class", "Master Sergeant", 
		"First Sergeant Major", "Sergeant Major", "Command Sergeant Major", "Sergeant Major of the Army",  "Warrant Officer 1", "Chief Warrant Officer 2", "Chief Warrant Officer 3", 
		"Chief Warrant Officer 4", "Chief Warran Officer 5", "Second Lieutenant", "First Lieutenant", "Captain", "Major", "Lieutenant Colonel", "Colonel", "Brigadier General", "Major General", 
		"Lieutenant General", "General", "General of the Army" };
	string salary[30] = { "none", "$1,600 per month", "1,793 per month", "$22,630-$25,510 per year", "$25,067-$30,427 per year", "$25,067-$30,427 per year", "$27,338-$38,794 per year", 
		"$29,840-$46,220 per year", "$34,502-$62,010 per year", "$49,633-$70,787 per year", "$49,633-$70,787 per year", "$60,631-$94,136 per year", "$60,631-$94,136 per year", 
		"$60,631-$94,136 per year", "$35,597-$61,510 per year", "40,554-$67,687 per yaer", "$45,828-$80,392 per year", "$50,184-$93,478 per year", "$89,233-$116,770 per year", 
		"$36,418-$45,824 per year", "$41,958-$58,068 per year", "$48,560-$79,002 per year", "$55,231-$92,218 per year", "$64,012-$108,752 per year", "$76,784-$135,936 per year", 
		"$101,257-$151,283 per year", "$121,860-$175,676 per year", "$172,224-$186,998 per year", "$15,583 per month", "$15,583 per month" };
};

int main()
{
	//Display Selection Chart of all Classes and Ranks//
	cout << "Enter" << setfill('.') << setw(29) << "Enlisted Rank" << setfill(' ') << setw(9) << "Enter" << setfill('.') << setw(30) << "Warrant Rank" << setfill(' ') << setw(9) << "Enter" << setfill('.') << setw(20) << "Officer Rank" << endl;
	cout << "1" << setfill('.') << setw(33) << "Private" << setfill(' ') << setw(6) << "14" << setfill('.') << setw(33) << "Warrant Officer 1" << setfill(' ') << setw(6) << "19" << setfill('.') << setw(24) << "2nd Lieutenant" << endl;
	cout << "2" << setfill('.') << setw(33) << "Private Second Class" << setfill(' ') << setw(6) << "15" << setfill('.') << setw(33) << "Chief Warrant Officer 2" << setfill(' ') << setw(6) << "20" << setfill('.') << setw(24) << "1st Lieutenant" << endl;
	cout << "3" << setfill('.') << setw(33) << "Private First Class" << setfill(' ') << setw(6) << "16" << setfill('.') << setw(33) << "Chief Warrant Officer 3" << setfill(' ') << setw(6) << "21" << setfill('.') << setw(24) << "Captain" << endl;
	cout << "4" << setfill('.') << setw(33) << "Specialist" << setfill(' ') << setw(6) << "17" << setfill('.') << setw(33) << "Chief Warrant Officer 4" << setfill(' ') << setw(6) << "22" << setfill('.') << setw(24) << "Major" << endl;
	cout << "5" << setfill('.') << setw(33) << "Corporal" << setfill(' ') << setw(6) << "18" << setfill('.') << setw(33) << "Chief Warrant Officer 5" << setfill(' ') << setw(6) << "23" << setfill('.') << setw(24) << "Lieutenant Colonel" << endl;
	cout << "6" << setfill('.') << setw(33) << "Sergeant" << setfill(' ') << setw(45) << "24" << setfill('.') << setw(24) << "Colonel" << endl;
	cout << "7" << setfill('.') << setw(33) << "Staff Sergeant" << setfill(' ') << setw(45) << "25" << setfill('.') << setw(24) << "Brigadier General" << endl;
	cout << "8" << setfill('.') << setw(33) << "Sergeant First Class" << setfill(' ') << setw(45) << "26" << setfill('.') << setw(24) << "Major General" << endl;
	cout << "9" << setfill('.') << setw(33) << "Master Sergeant" << setfill(' ') << setw(45) << "27" << setfill('.') << setw(24) << "Lieutenant General" << endl;
	cout << "10" << setfill('.') << setw(32) << "Firt Sergeant Major" << setfill(' ') << setw(45) << "28" << setfill('.') << setw(24) << "General" << endl;
	cout << "11" << setfill('.') << setw(32) << "Sergeant Major" << setfill(' ') << setw(45) << "29" << setfill('.') << setw(24) << "General of the Army" << endl;
	cout << "12" << setfill('.') << setw(32) << "Command Sergeant Major" << endl;
	cout << "13" << setfill('.') << setw(32) << "Sergeant Major of the Army" << endl << endl;

	vector<soldier> army;
	string newName;
	string temp;
	int newRank;

	//while loop used to enter as many new soldiers as user wants.//
	int i = 0;
	bool again = true;
	while (again == true)
	{
		cout << "Enter soldier's name or press X to quit: ";
		getline(cin, newName);
		if (newName == "X" || newName == "x")
		{
			again = false;
		}
		else
		{
			cout << "Enter the number that corresponds to soldier's rank: ";
			getline(cin, temp);
			newRank = stoi(temp);
			soldier newSoldier = soldier(newName, newRank);
			army.push_back(newSoldier);
			cout << "You entered " << army[i] << endl;
			i++;
		}
	}
	
	//Print highest ranking soldiers//
	cout << endl;
	int armySize = i - 1;
	int highestRanking = 0;
	for (int n = 0; n <= armySize; n++)
	{
		for (int m = 0; m<= armySize; m++)
		if (army[n] < army[m])
		{
			highestRanking = m;
		}
	}
	cout << "Highest Rank: " << endl;
	for (int n = 0; n <= armySize; n++)
	{
		if (army[n] == army[highestRanking])
		{
			cout << army[n].getName() << ", " << army[n].getRank() << endl;
		}
	}
	cout << endl;

	//attempting random promotion and demotion//
	if (0 <= armySize)
	{
		cout << "Attempting to promote " << army[0].getName() << "..." << endl;
		army[0] = army[0]++;
	}

	if (1 <= armySize)
	{
		cout << "Attempting to promote " << army[1].getName() << "..." << endl;
		army[1] = ++army[1];
	}

	if (3 <= armySize)
	{
		cout << "Attempting to demote " << army[3].getName() << "..." << endl;
		army[3] = army[3]--;
	}

	if (4 <= armySize)
	{
		cout << "Attempting to demote " << army[4].getName() << "..." << endl;
		army[4] = --army[4];
	}

	if (5 <= armySize)
	{
		cout << "Attempting to promote " << army[5].getName() << "..." << endl;
		army[5] = army[5]++;
	}

	if (6 <= armySize)
	{
		cout << "Attempting to promote " << army[6].getName() << "..." << endl;
		army[6] = ++army[6];
	}

	if (7 <= armySize)
	{
		cout << "Attempting to demote " << army[7].getName() << "..." << endl;
		army[7] = army[7]--;
	}

	cout << endl << "Final Name, Rank, Class, and Pay" << endl;
	for (int n = 0; n <= armySize; n++)
	{
		cout << army[n] << endl;
	}



	cout << "Press any key to continue...";
	cin.ignore();
	cin.get();
	return 0;
}

soldier::soldier(string newName, int newRank)
{
	//do while loop used to process try/catch blocks//
	bool done = false;
	do
	{
		try
		{
			if (!cin)
			{
				int error = 404;
				throw error;
			}
			else if (newRank < 1 || newRank > 29)
			{
				string error = "Rank must be bewteen 1 and 29. ";
				throw error;
			}
			done = true;
			name = newName;
			if (newRank >= 1 && newRank <= 13)
			{
				rank = newRank;
				classification = 1;
			}
			else if (newRank >= 14 && newRank <= 18)
			{
				rank = newRank;
				classification = 2;
			}
			else if (newRank >= 19 && newRank <= 29)
			{
				rank = newRank;
				classification = 3;
			}
		}
		catch (string error)
		{
			string temp;
			cout << error;
			cout << "Enter rank again: ";
			getline(cin, temp);
			newRank = stoi(temp);
		}
		catch (int error)
		{
			string temp;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Woah! You entered something wacky. Enter soldier's name again: ";
			getline(cin, newName);
			cout << "Enter soldier's rank again: ";
			getline(cin, temp);
			newRank = stoi(temp);
		}
	} while (!done);
}
string soldier::pay()
{
	return salary[rank];
}
string soldier::getName()
{
	return name;
}
string soldier::getRank()
{
	return str_rank[rank];
}
void soldier::toString()
{
	cout << "Name: " << name << endl;
	if (rank >= 1 && rank <= 13)
	{
		cout << "Classification: " << str_classification[1] << endl;
	}
	else if (rank >= 14 && rank <= 18)
	{
		cout << "Classification: " << str_classification[2] << endl;
	}
	else if (rank >= 19 && rank <= 29)
	{
		cout << "Classification: " << str_classification[3] << endl;
	}
	cout << "Rank: " << str_rank[rank] << endl;
	cout << "Pay: " << salary[rank] << endl;
}
bool soldier::operator==(const soldier& thisSoldier)
{
	return(rank == thisSoldier.rank);
}
bool soldier::operator<(const soldier& thisSoldier)
{
	return(rank < thisSoldier.rank);
}
ostream& operator<<(ostream& osString, const soldier& thisSoldier)
{
	int classification;
	if (thisSoldier.rank >= 1 && thisSoldier.rank <= 13)
	{
		classification = 1;
	}
	else if (thisSoldier.rank >= 14 && thisSoldier.rank <= 18)
	{
		classification = 2;
	}
	else if (thisSoldier.rank >= 19 && thisSoldier.rank <= 29)
	{
		classification = 3;
	}

	osString << "Name: " << thisSoldier.name << endl
		<< "Classification: " << thisSoldier.str_classification[classification] << endl
		<< "Rank: " << thisSoldier.str_rank[thisSoldier.rank] << endl
		<< "Pay: " << thisSoldier.salary[thisSoldier.rank] << endl;
	return osString;
}
soldier soldier::operator++()
{
	string error;
	try
	{
		if (rank == 13)
		{
			throw error = "Sergeant Major of the Army already highest enlisted rank. Promotion aborted.";
		}
		else if (rank == 18)
		{
			throw error = "Chief Warrant Officer 5 already highest warrant rank. Promotion aborted";
		}
		else if (rank == 29)
		{
			throw error = "General of the Army already highest officer rank. Promotion aborted.";
		}
		++rank;
		cout << name << " promoted to " << str_rank[rank] << endl;
	}
	catch(string error)
	{
		cout << error << endl;
	}
	return *this;
}
soldier soldier::operator++(int u)
{
	string error;
	soldier temp = *this;
	try
	{
		if (rank == 13)
		{
			throw error = "Sergeant Major of the Army already highest enlisted rank. Promotion aborted.";
		}
		else if (rank == 18)
		{
			throw error = "Chief Warrant Officer 5 already highest warrant rank. Promotion aborted";
		}
		else if (rank == 29)
		{
			throw error = "General of the Army already highest officer rank. Promotion aborted.";
		}
		rank++;
		cout << name << " promoted to " << str_rank[rank] << endl;
	}
	catch (string error)
	{
		cout << error << endl;
	}
	return *this;
}
soldier soldier::operator--()
{
	string error;
	try
	{
		if (rank == 1)
		{
			throw error = "Private already lowest enlisted rank. Demotion aborted.";
		}
		else if (rank == 14)
		{
			throw error = "Warrant Officer 1 already lowest warrant rank. Demotion aborted";
		}
		else if (rank == 19)
		{
			throw error = "Second Lieutenant already lowest officer rank. Demotion aborted.";
		}
		--rank;
		cout << name << " demoted to " << str_rank[rank] << endl;
	}
	catch (string error)
	{
		cout << error << endl;
	}	
	return *this;
}
soldier soldier::operator--(int u)
{
	string error;
	soldier temp = *this;
	try
	{
		if (rank == 1)
		{
			throw error = "Private already lowest enlisted rank. Demotion aborted.";
		}
		else if (rank == 14)
		{
			throw error = "Warrant Officer 1 already lowest warrant rank. Demotion aborted";
		}
		else if (rank == 19)
		{
			throw error = "Second Lieutenant already lowest officer rank. Demotion aborted.";
		}
		--rank;
		cout << name << " demoted to " << str_rank[rank] << endl;
	}
	catch (string error)
	{
		cout << error << endl;
	}
	return *this;
}