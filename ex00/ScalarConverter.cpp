#include "ScalarConverter.hpp"

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Constructor called \n";
}

ScalarConverter::ScalarConverter(ScalarConverter const &oth)
{
	(void)oth;
	std::cout << "Copy Constructor called for ScalarConverter \n";
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &oth)
{
	(void)oth;
	std::cout << "Assignet Constructor called for ScalarConverter \n";
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called for \n";
}

void ScalarConverter::convert(const std::string &literal)
{
	if(literal == "nan" || literal == "nanf")
	{
		std::cout << "char: 	impossible\n";
		std::cout << "int:		impossible\n";
		std::cout << "float:	nanf\n";
		std::cout << "double:	nan\n";
		return;
	}

	else if(literal == "+inf" || literal == "+inff")
	{
		std::cout << "char: 	impossible\n";
		std::cout << "int:		impossible\n";
		std::cout << "float:	+inff\n";
		std::cout << "double:	+inf\n";
		return;
	}
	else if(literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: 	impossible\n";
		std::cout << "int:		impossible\n";
		std::cout << "float:	-inff\n";
		std::cout << "double:	-inf\n";
		return;
	}
	else if(literal.length() == 1 && !std::isdigit(literal[0]))
	{
		char c = literal[0];

		std::cout << "char: '" << c << "'\n";
		std::cout << "int : " <<static_cast<int>(c)<<"\n";
		std::cout << "float : " <<static_cast<float>(c)<<"\n";
		std::cout << "double : " <<static_cast<double>(c)<<"\n";
	}

}

static bool isInt(const std::string& literal)
{
	if(literal.empty())
		return false;
	int i = 0;
	if(literal[i] == '+' || literal[i] == '-')
	{
		i++;
		if(i == literal.length())
			return false;
	}
	int j = i;
	while (j < literal.length())
	{
		if(!std::isdigit(literal[j]))
			return false;
		j++;
	}
	return true;
}

static bool isDouble(const std::string& literal)
{
	if (literal.empty())
		return false;

	int i = 0;
	bool sawDot = false;
	bool hasDigitBeforeDot = false;
	bool hasDigitAfterDot = false;

	if (literal[i] == '+' || literal[i] == '-')
	{
		i++;
		if (i == literal.length())
			return false;
	}

	int j = i;
	while (j < literal.length())
	{
		if (std::isdigit(literal[j]))
		{
			if (sawDot == false)
				hasDigitBeforeDot = true;
			else
				hasDigitAfterDot = true;
		}
		else if (literal[j] == '.')
		{
			if (sawDot == true)
				return false;
			sawDot = true;
		}
		else
		{
			return false;
		}
		j++;
	}

	return (sawDot && hasDigitBeforeDot && hasDigitAfterDot);
}

static bool isFloat(const std::string& literal)
{
	if (literal.empty())
		return false;

	int i = 0;
	bool sawDot = false;
	bool hasDigitBeforeDot = false;
	bool hasDigitAfterDot = false;
	bool sawF = false;

	if (literal[i] == '+' || literal[i] == '-')
	{
		i++;
		if (i == literal.length())
			return false;
	}

	int j = i;
	while (j < literal.length())
	{
		if (std::isdigit(literal[j]))
		{
			if (sawDot == false)
				hasDigitBeforeDot = true;
			else
				hasDigitAfterDot = true;
		}
		else if (literal[j] == '.')
		{
			if (sawDot == true)
				return false;
			sawDot = true;
		}
		else if (literal[j] == 'f' && j == literal.length()-1)
		{
			sawF = true;
		}
		else
		{
			return false;
		}
		j++;
	}

	return (sawDot && hasDigitBeforeDot && hasDigitAfterDot && sawF);
}

