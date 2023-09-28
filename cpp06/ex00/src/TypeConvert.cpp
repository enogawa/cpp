#include "../inc/TypeConvert.hpp"

TypeConvert::TypeConvert()
{

}


TypeConvert::TypeConvert(std::string literal): literal_(literal), minus_('\0'), Fval_("f")
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

bool TypeConvert::SeudoLiterals(void)
{
	if (literal_ == "nan" || literal_ == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}
	else if (literal_ == "+inf" || literal_ == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return true;
	}
	else if (literal_ == "-inf" || literal_ == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return true;
	}
	return false;
}

bool	TypeConvert::checkChar(void)
{
	if (literal_.length() != 1)
		return (false);
	if (isprint(literal_[0]) && !isdigit(literal_[0]))
		return (true);
	return (false);
	
}

bool TypeConvert::checkInt(void)
{
	if (literal_[0] == '-')
	{
		literal_.erase(0, 1);
		minus_ = '-';
	}
	for (size_t i = 0; i < literal_.length(); i++)
	{
		if (!isdigit(literal_[i]))
			return false;
	}
	return true;
}

bool TypeConvert::checkFloat(void)
{
	int i = 0;

	if (literal_[i] == '-')
	{
		i++;
		minus_ = '-';
	}
	if (!isdigit(literal_[i]))
		return false;
	while (isdigit(literal_[i]))
		i++;
	if (literal_[i++] != '.')
		return false;
	if (!isdigit(literal_[i]))
		return false;
	else if (literal_[i] == '0')
	{
		Fval_ = ".0f";
		Dval_ = ".0";
	}
	while (isdigit(literal_[i]))
		i++;
	if (literal_[i++] != 'f')
		return false;
	if (literal_[i])
		return false;
	return true;
}

bool TypeConvert::checkDouble(void)
{
	int i = 0;

	if (literal_[i] == '-')
	{
		i++;
		minus_ = '-';
	}
	if (!isdigit(literal_[i]))
		return false;
	while (isdigit(literal_[i]))
		i++;
	if (literal_[i++] != '.')
		return false;
	if (!isdigit(literal_[i]))
		return false;
	else if (literal_[i] == '0')
	{
		Fval_ = ".0f";
		Dval_ = ".0";
	}
	while (isdigit(literal_[i]))
		i++;
	if (literal_[i])
		return false;
	return true;
}

void TypeConvert::convertChar(void)
{
	char ch = literal_[0];
	int i = static_cast<int>(ch);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	std::cout << "char: '" << ch << "'" << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void TypeConvert::convertInt(void)
{
	double d = strtod(literal_.c_str(), NULL);
	int i = static_cast<int>(d);
	char ch = static_cast<char>(d);
	float f = static_cast<float>(d);

	if (isprint(ch) && d < 256 && d > 0)
		std::cout << "char: '" << ch << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d <= INT_MAX && d >= INT_MIN)
	{
		std::cout << "int: " << minus_ << i << std::endl;
		std::cout << "float: " << minus_ << f << ".0f" << std::endl;
		std::cout << "double: " << minus_ << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "int: Int overflow" << std::endl;
		std::cout << "float: Int overflow" << std::endl;
		std::cout << "double: Int overflow" << std::endl;
	}
}

void TypeConvert::convertFloat(void)
{
	double d = strtod(literal_.c_str(), NULL);
	int i = static_cast<int>(d);
	char ch = static_cast<char>(d);
	float f = static_cast<float>(d);

	if (isprint(ch) && d < 256 && d > 0)
		std::cout << "char: '" << ch << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d <= FLT_MAX && d >= FLT_MIN)
	{
		if (d <= INT_MAX && d >= INT_MIN)
			std::cout << "int: " << minus_ << i << std::endl;
		else
			std::cout << "int: Int overflow" << std::endl;
		std::cout << "float: " << minus_ << f << Fval_ << std::endl;
		std::cout << "double: " << minus_ << d << Dval_ << std::endl;
	}
	else
	{
		std::cout << "int: Float overflow" << std::endl;
		std::cout << "float: Float overflow" << std::endl;
		std::cout << "double: Float overflow" << std::endl;
	}
}

void TypeConvert::convertDouble(void)
{
	double d = strtod(literal_.c_str(), NULL);
	int i = static_cast<int>(d);
	char ch = static_cast<char>(d);
	float f = static_cast<float>(d);

	if (isprint(ch) && d < 256 && d > 0)
		std::cout << "char: '" << ch << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d <= INT_MAX && d >= INT_MIN)
		std::cout << "int: " << minus_ << i << std::endl;
	else
		std::cout << "int: Int overflow" << std::endl;
	if (d <= FLT_MAX && d >= FLT_MIN)
		std::cout << "float: " << minus_ << f << Fval_ << std::endl;
	else
		std::cout << "float: Float overflow" << std::endl;
	std::cout << "double: " << minus_ << d << Dval_ << std::endl;
}

void TypeConvert::converter(void)
{
	if (SeudoLiterals() == false)
	{
		if (checkChar())
			convertChar();
		else if(checkInt())
			convertInt();
		else if (checkFloat())
			convertFloat();
		else if (checkDouble())
			convertDouble();
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