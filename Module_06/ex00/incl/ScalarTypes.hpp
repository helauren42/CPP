#ifndef SCALARTYPES_HPP
#define SCALARTYPES_HPP

#include <iostream>

enum
{
	numChar,
	numFloat,
	numDouble,
	numInt,
	NAN,
	NEGINF,
	NEGINFF,
	POSINF,
	POSINFF
};

enum //error types
{
	VALID,
	ERROR,
};

class	ScalarTypes
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		ScalarTypes();
		~ScalarTypes();
		// virtual ~ScalarTypes() = 0;
		ScalarTypes(const ScalarTypes &s);
		/* ------------------- METHODS --------------------- */
		void		convert(std::string s);
		bool		isValidInput(std::string s);
		void		convertChar(std::string s);
		void		convertFloat(std::string s);
		void		convertDouble(std::string s);
		void		convertInt(std::string s);
		/* ------------------- SETTERS --------------------- */
		void		setUnvalid(std::string s);
		void		setLenDecimal(size_t value);
		void		setType(std::string s);
		/* ------------------- GETTERS --------------------- */
		int			getValid() const;
		bool		getValidChar() const;
		char		getChar() const;
		int			getInt() const;
		float		getFloat() const;
		double		getDouble() const;
		size_t		getLenDecimal() const;
		int			getType() const;
		/* ------------------ OVERLOADS -------------------- */
		ScalarTypes	&operator=(const ScalarTypes &);

	
	private:
		size_t	lenDecimal;
		int		valid;
		bool	isValidChar;

		char	character;
		int		integer;
		float	floating;
		double	doublefloat;
		int		type;
};

std::ostream	&operator<<(std::ostream &stream, ScalarTypes const &scalartypes);

#endif
