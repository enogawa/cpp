#ifndef TYPECONVERT_HPP
#define TYPECONVERT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cfloat>

class TypeConvert
{
private:
	std::string	literal_;
	char		minus_;
	std::string	Fval_;
	std::string	Dval_;

	bool	SeudoLiterals(void);
	bool	checkChar(void);
	bool	checkInt(void);
	bool	checkFloat(void);
	bool	checkDouble(void);

	void	convertChar(void);
	void	convertInt(void);
	void	convertFloat(void);
	void	convertDouble(void);
public:
	TypeConvert();
	TypeConvert(std::string literal);
	TypeConvert(const TypeConvert &);
	~TypeConvert();

	TypeConvert	&operator=(const TypeConvert &);
	void	converter();
	
};



#endif