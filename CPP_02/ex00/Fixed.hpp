#include <string>
#include <iostream>

class Fixed
{
	private:
		int _fixedPointVal;
		static const int _fractBits;
	public:
		// A default constructor that initializes the fixed-point number value to 0
		Fixed();
		// A copy constructor
		Fixed(Fixed &copy);
		// A destructor
		~Fixed();
		// A copy assignment operator overload
		Fixed &operator=(const Fixed &other);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};
