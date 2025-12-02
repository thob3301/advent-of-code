#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>

using std::cout;
using std::ifstream;
using std::endl;
using std::vector;
using std::string;
using std::atoi;

int	main()
{
	vector<int>	dial;
	ifstream	file("./input.txt");
	int			zero_count = 0;

	dial.push_back(50);
	while (file)
	{
		int		i = dial.back();
		string	line;
		int		num;

		file >> line;
		num = atoi(&line[1]);
		if (line[0] == 'R')
		{
			zero_count += (dial.back() + num) / 100;
			dial.push_back( (i + num) % 100);
		}
		else if (line[0] == 'L')
		{
			zero_count += (dial.back() - num - 100) / -100;
				if (!dial.back()) --zero_count;
			dial.push_back( (i + (100 - (num % 100))) % 100);
		}
//		cout << dial.back() << "\t" << line << "\t" << zero_count << endl;
	}
	int	zero_count_part1 = 0;
	for (vector<int>::iterator p = dial.begin(); p!=dial.end(); ++p)
		if (!*p) ++zero_count_part1;
	cout << "Number of zeros for part 1: " << zero_count_part1 << endl;
	cout << "Number of zeros for part 2: " << zero_count << endl;
}
