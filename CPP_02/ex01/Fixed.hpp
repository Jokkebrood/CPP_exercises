#include <string>
#include <iostream>
#include <math.h>

class Fixed
{
	private:
		int _fixedPointVal;
		static const int _fractBits;
	public:
		// A default constructor that initializes the fixed-point number value to 0
		Fixed();
		// A copy constructor
		Fixed(const Fixed &copy);
		Fixed(const int integer);
		Fixed(const float floater);
		// A destructor
		~Fixed();
		// A copy assignment operator overload
		Fixed &operator=(const Fixed &other);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
