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
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
		return;
	}

	else if(literal == "+inf" || literal == "+inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
		return;
	}
	else if(literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
		return;
	}
	else if(literal.length() == 1 && !std::isdigit(literal[0]))
	{
		char c = literal[0];

		std::cout << "char: '" << c << "'\n";
		std::cout << "int : " <<static_cast<int>(c)<<"\n";
		std::cout << "float : " <<static_cast<float>(c)<<".0f\n";
		std::cout << "double : " <<static_cast<double>(c)<<".0\n";
	}
	else if(isInt(literal))
	{
		errno = 0;
		char *end;
		long value = strtol(literal.c_str(), &end, 10);
		if(value < INT_MIN || value > INT_MAX || *end != '\0' || errno == ERANGE)
		{
			std::cout << "char: imppossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float : " << static_cast<float>(value) <<".0f\n";
			std::cout << "double : " << static_cast<double>(value)<<".0\n";
			return;
		}
		int intValue = value;

		if(intValue < 0 || intValue > 127)
		{
			std::cout << "char: impossible\n";
			std::cout << "int : "	 << static_cast<int>(value)<<"\n";
			std::cout << "float : "	 << static_cast<float>(value) <<".0f\n";
			std::cout << "double : " << static_cast<double>(value)<<".0\n";
		}
		else if(!std::isprint(intValue))
		{
			std::cout << "char: Non displayable\n";
			std::cout << "int : "	 << static_cast<int>(value)<<"\n";
			std::cout << "float : "	 << static_cast<float>(value) <<".0f\n";
			std::cout << "double : " << static_cast<double>(value)<<".0\n";
		}
		else
		{
		std::cout << "char: '"	 << static_cast<char>(value) << "'\n";
		std::cout << "int : "	 << static_cast<int>(value)<<"\n";
		std::cout << "float : "	 << static_cast<float>(value) <<".0f\n";
		std::cout << "double : " << static_cast<double>(value)<<".0\n";
		return;
		}
	}
	else {
		std::cout <<"xxxxxxxxxxxxxxxxxxxxxx\n";
	}
}
