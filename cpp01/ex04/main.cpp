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
	std::ofstream	outfile;

	if (ac != 4 || av[2] == std::string("") || av[3] == std::string(""))
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
	readFile.open(filename.c_str());
	line = filename + ".replace";
	if (readFile.is_open())
	{
		outfile.open(line.c_str());
		while (!readFile.eof())
		{
			getline(readFile, line);
			line = replace_line(line, find, replace);
			outfile << line;
			if (!readFile.eof())
			{
				if (find == "\n")
					outfile << replace;
				else
					outfile << std::endl;
			}
		}
		outfile.close();
	}
	else
	{
		std::cout<<"File open error"<<std::endl;
		return (1);
	}
	readFile.close();
	return (0);
}

std::string	replace_line(std::string line, std::string find, std::string replace)
{
	std::string	temp;
	int			start = 0;
	int			idx = 0;

	while (line.find(find, start) != std::string::npos)
	{
		idx = line.find(find, start);
		if (idx == 0)
			line = replace + line.substr(idx + find.length());
		else
			line = line.substr(0, idx) + replace + line.substr(idx + find.length());
		start += idx + replace.length();
	}
	return (line);
}
