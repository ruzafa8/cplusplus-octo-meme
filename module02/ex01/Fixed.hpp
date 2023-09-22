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
        std::ostream &operator<<(std::ostream &o);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
    private:
        int integer;
        static const int fractionalBits = 8;
};

#endif