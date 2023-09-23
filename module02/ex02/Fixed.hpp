#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>
# include <cmath>

class Fixed {
    public:
        Fixed(void);
        Fixed(Fixed const &src);
        Fixed(int const integer);
        Fixed(float const floating);
        ~Fixed(void);

        Fixed &operator=(Fixed const &rhs);

        bool operator>(Fixed const &rhs) const;
        bool operator<(Fixed const &rhs) const;
        bool operator>=(Fixed const &rhs) const;
        bool operator<=(Fixed const &rhs) const;
        bool operator==(Fixed const &rhs) const;
        bool operator!=(Fixed const &rhs) const;

        Fixed operator+(Fixed const &rhs) const;
        Fixed operator-(Fixed const &rhs) const;
        Fixed operator*(Fixed const &rhs) const;
        Fixed operator/(Fixed const &rhs) const;

        Fixed &operator++(void);
        Fixed operator++(int);

        Fixed &operator--(void);
        Fixed operator--(int);

        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
    private:
        int integer;
        static const int fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif