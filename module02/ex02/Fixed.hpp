#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>

class Fixed {
    public:
        Fixed(void);
        Fixed(Fixed const &src);
        Fixed(int const integer);
        Fixed(float const floating);
        ~Fixed(void);

        Fixed &operator=(Fixed const &rhs);
        ostream &operator<<(ostream &o, Fixed const &rhs);

        bool operator>(Fixed const &rhs);
        bool operator<(Fixed const &rhs);
        bool operator>=(Fixed const &rhs);
        bool operator<=(Fixed const &rhs);
        bool operator==(Fixed const &rhs);
        bool operator!=(Fixed const &rhs);

        Fixed operator+(Fixed const &rhs);
        Fixed operator-(Fixed const &rhs);
        Fixed operator*(Fixed const &rhs);
        Fixed operator/(Fixed const &rhs);

        Fixed &operator++(void);
        Fixed operator++(int);

        Fixed &operator--(void);
        Fixed operator--(int);

        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
    private:
        int integer;
        static const int fractionalBits = 8;
}

#endif