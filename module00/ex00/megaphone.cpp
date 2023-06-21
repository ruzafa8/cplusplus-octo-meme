#include <iostream>

void	print(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			std::cout << (char) toupper(str[i][j]);
			j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc >= 2)
		print(argv + 1);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
