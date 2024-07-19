#include <iostream>
#include <string>
#include <fstream>

std::string	replace_line(std::string line, std::string find, std::string replace);

int	main(int ac, char *av[])
{
	std::ifstream	readFile;
	std::string		filename;
	std::string		find;
	std::string		replace;
	std::string		line;
	std::ofstream		outfile;

	if (ac != 4)
	{
		std::cout<<"input is wrong!!"<<std::endl;
		return (1);
	}
	filename = av[1];
	find = av[2];
	replace = av[3];
	if (find == replace)
	{
		std::cout<<"input is wrong!!"<<std::endl;
		return (1);
	}
	readFile.open(filename);
	line = filename + ".replace";
	outfile.open(line);
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			getline(readFile, line);
			line = replace_line(line, find, replace);
			outfile << line;
			if (!readFile.eof())
				outfile << std::endl;
		}
	}
	else
		std::cout<<"File open error"<<std::endl;
	outfile.close();
	readFile.close();
	return (0);
}

std::string	replace_line(std::string line, std::string find, std::string replace)
{
	std::string	temp;
	int			f_len = find.length();

	for (int i = 0; (i + f_len) < (int)line.length(); i++)
	{
		temp = line.substr(i, f_len);
		if (temp == find)
		{
			line = line.substr(0, i) + replace + line.substr(i + f_len);
			i += replace.length() - 1;
		}

	}
	return (line);
}
