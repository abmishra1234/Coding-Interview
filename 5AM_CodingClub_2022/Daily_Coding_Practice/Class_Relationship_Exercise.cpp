using namespace std;
#include<iostream>
/*
	Code having many duplicate chunk, next task is to make this code simple and modular.
*/

#define FORREF
#ifndef FORREF

class Event
{
private:
	// for title
	string title;

	// for date
	int DD;
	int MM;
	int YYYY;

	// for time
	int hr;
	int min;
	int sec;

public:
	Event() = default;
	// Event e("Birthday", 2, 28, 2021, 10, 30, 0);
	Event(string ti, int mm, int dd, int yyyy, int h, int m, int s)
	{
		title = ti;
		MM = mm;
		DD = dd;
		YYYY = yyyy;
		
		hr = h;
		min = m;
		sec = s;
	}

	string buildDate(int month, int date, int yr)
	{
		string output = "";
		if (month < 10)
		{
			output += '0';
			output += ('0' + month);
		}
		else
		{
			char days[2];
			int i = 1;
			while (month > 0)
			{
				int rem = month % 10;
				days[i--] = '0' + rem;
				month /= 10;
			}

			output += days[0];
			output += days[1];
		}
		output += '-';
		// day
		if (date < 10)
		{
			output += '0';
			output += ('0' + date);
		}
		else
		{
			char days[2];
			int i = 1;
			while (date > 0)
			{
				int rem = date % 10;
				days[i--] = '0'+rem;
				date /= 10;
			}

			output += days[0];
			output += days[1];
		}

		output += '-';

		// for year
		char days[4];
		int i = 3;
		while (yr > 0)
		{
			int rem = yr % 10;
			days[i--] = '0' + rem;
			yr /= 10;
		}

		output += days[0];
		output += days[1];
		output += days[2];
		output += days[3];
		return output;
	}

	string buildTime(int h, int m, int s)
	{
		string output = "";
		if (h < 10)
		{
			output += '0';
			output += ('0' + h);
		}
		else
		{
			char days[2];
			int i = 1;
			while (h > 0)
			{
				int rem = h % 10;
				days[i--] = '0' + rem;
				h /= 10;
			}

			output += days[0];
			output += days[1];
		}
		output += ':';
		// day
		if (m < 10)
		{
			output += '0';
			output += ('0' + m);
		}
		else
		{
			char days[2];
			int i = 1;
			while (m > 0)
			{
				int rem = m % 10;
				days[i--] = '0' + rem;
				m /= 10;
			}

			output += days[0];
			output += days[1];
		}
		output += ':';

		// for s
		if (s < 10)
		{
			output += '0';
			output += ('0' + s);
		}
		else
		{
			char days[2];
			int i = 1;
			while (s > 0)
			{
				int rem = s % 10;
				days[i--] = '0' + rem;
				s /= 10;
			}

			output += days[0];
			output += days[1];
		}
		return output;
	}

	// Birthday occurs on 02-28-2021 at 10:30:00
	void display()
	{
		cout << title << " occurs on " << buildDate(MM, DD, YYYY);
		cout << " at " << buildTime(hr, min, sec) << endl;
	}
};



int main()
{
	Event e("Birthday", 2, 28, 2021, 10, 30, 0);
	e.display();

	return 0;
}
#endif // !FORREF
