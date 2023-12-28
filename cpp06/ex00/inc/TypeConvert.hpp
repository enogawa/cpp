#ifndef TYPECONVERT_HPP
#define TYPECONVERT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cfloat>

class TypeConvert
{
public:
	static void	converter(std::string argv);
	
private:
	static bool	SeudoLiterals(std::string argv);
	static bool	checkChar(std::string argv);
	static bool	checkInt(std::string argv);
	static bool	checkFloat(std::string argv);
	static bool	checkDouble(std::string argv);

	static void	convertChar(std::string argv);
	static void	convertInt(double argv);
	static void	convertFloat(float argv);
	static void	convertDouble(double argv);

	TypeConvert();
	TypeConvert(const TypeConvert &);
	~TypeConvert();

	TypeConvert	&operator=(const TypeConvert &);
};



#endif
