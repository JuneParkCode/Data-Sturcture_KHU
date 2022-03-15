#include <fstream>

void	convert_file_mac_to_windows(const char *input_file_name, const char *output_file_name);
void	convert_file_windows_to_mac(const char *input_file_name, const char *output_file_name);
int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (1);
	convert_file_mac_to_windows(argv[1], argv[2]);
	//convert_file_windows_to_mac(argv[1], argv[2]);
	return (0);
}

void	convert_file_mac_to_windows(const char *input_file_name, const char *output_file_name)
{
	std::ifstream	input_file(input_file_name);
	std::ofstream	output_file(output_file_name);
	char			ch;

	while (!input_file.eof())
	{
		input_file.get(ch);
		if (input_file.bad() || input_file.eof())
			break ;
		if (ch == '\r')
		{
			output_file << '\r';
			output_file << '\n';
		}
		else
			output_file << ch;
	}
	input_file.close();
	output_file.close();
}

void	convert_file_windows_to_mac(const char *input_file_name, const char *output_file_name)
{
	std::ifstream	input_file(input_file_name);
	std::ofstream	output_file(output_file_name);
	char			ch;
	bool			flag;

	flag = 0;
	while (!input_file.eof())
	{
		input_file.get(ch);
		if (input_file.bad() || input_file.eof())
			break ;
		if (!(flag && ch == '\n'))
			output_file << ch;
		flag = (ch == '\r');
	}
	input_file.close();
	output_file.close();
}
