#include "../inc/TypeConvert.hpp"

TypeConvert::TypeConvert()
{
}

TypeConvert::TypeConvert(const TypeConvert &other)
{
	*this = other;
}

TypeConvert::~TypeConvert()
{
}

TypeConvert &TypeConvert::operator=(const TypeConvert &other)
{
	(void)other;
	return *this;
}

bool TypeConvert::SeudoLiterals(std::string argv)
{
	if (argv == "nan" || argv == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}
	else if (argv == "+inf" || argv == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return true;
	}
	else if (argv == "-inf" || argv == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return true;
	}
	return false;
}

bool	TypeConvert::checkChar(std::string argv)
{
	if (argv.length() != 1)
		return (false);
	if (isprint(argv[0]) && !isdigit(argv[0]))
		return (true);
	return (false);
	
}

bool TypeConvert::checkInt(std::string argv)
{
	if (argv[0] == '-')
	{
		argv.erase(0, 1);
	}
	for (size_t i = 0; i < argv.length(); i++)
	{
		if (!isdigit(argv[i]))
			return false;
	}
	return true;
}

bool TypeConvert::checkFloat(std::string argv)
{
	int i = 0;

	if (argv[i] == '-')
	{
		i++;
	}
	if (!isdigit(argv[i]))
		return false;
	while (isdigit(argv[i]))
		i++;
	if (argv[i++] != '.')
		return false;
	if (!isdigit(argv[i]))
		return false;
	while (isdigit(argv[i]))
		i++;
	if (argv[i++] != 'f')
		return false;
	if (argv[i])
		return false;
	return true;
}

bool TypeConvert::checkDouble(std::string argv)
{
	int i = 0;

	if (argv[i] == '-')
	{
		i++;
	}
	if (!isdigit(argv[i]))
		return false;
	while (isdigit(argv[i]))
		i++;
	if (argv[i++] != '.')
		return false;
	if (!isdigit(argv[i]))
		return false;
	while (isdigit(argv[i]))
		i++;
	if (argv[i])
		return false;
	return true;
}

void TypeConvert::convertChar(std::string argv)
{
	char ch = argv[0];
	int i = static_cast<int>(ch);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	std::cout << "char: '" << ch << "'" << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void TypeConvert::convertInt(double argv)
{
	int i = static_cast<int>(argv);
	char ch = static_cast<char>(argv);
	float f = static_cast<float>(argv);

	if (isprint(ch) && argv < 256 && argv > 0)
		std::cout << "char: '" << ch << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (argv <= INT_MAX && argv >= INT_MIN)
	{
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << argv << ".0" << std::endl;
	}
	else
	{
		std::cout << "int: Int overflow" << std::endl;
		std::cout << "float: Int overflow" << std::endl;
		std::cout << "double: Int overflow" << std::endl;
	}
}

void TypeConvert::convertFloat(float argv)
{
	double d = static_cast<double>(argv);
	int i = static_cast<int>(d);
	char ch = static_cast<char>(d);

	if (isprint(ch) && d < 256 && d > 0)
		std::cout << "char: '" << ch << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d <= std::numeric_limits<float>::max() && d >= std::numeric_limits<float>::min())
	{
		if (d <= INT_MAX && d >= INT_MIN)
			std::cout << "int: " << i << std::endl;
		else
			std::cout << "int: Int overflow" << std::endl;
		std::cout << "float: " << argv << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "int: Float overflow" << std::endl;
		std::cout << "float: Float overflow" << std::endl;
		std::cout << "double: Float overflow" << std::endl;
	}
}

void TypeConvert::convertDouble(double argv)
{
	int i = static_cast<int>(argv);
	char ch = static_cast<char>(argv);
	float f = static_cast<float>(argv);

	if (isprint(ch) && argv < 256 && argv > 0)
		std::cout << "char: '" << ch << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (argv <= INT_MAX && argv >= INT_MIN)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: Int overflow" << std::endl;
	if (argv <= std::numeric_limits<float>::max() && argv >= std::numeric_limits<float>::min())
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: Float overflow" << std::endl;
	std::cout << "double: " << argv << ".0" << std::endl;
}

void TypeConvert::converter(std::string argv)
{
	if (SeudoLiterals(argv) == false)
	{
		if (checkChar(argv))
			convertChar(argv);
		else if(checkInt(argv))
			convertInt(std::stod(argv));
		else if (checkFloat(argv))
			convertFloat(std::stof(argv));
		else if (checkDouble(argv))
			convertDouble(std::stod(argv));
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
	}
	return;
}