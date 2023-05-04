#include "Fraction.hpp"

using namespace ariel;

Fraction::Fraction() : numerator(0), denominator(1){};
Fraction::Fraction(int numerator, int denominator)
{

    if (denominator == 0) // denominator can't be zero
    {
        throw invalid_argument("denominator can't be 0!");
    }

    this->numerator = numerator;
    this->denominator = denominator;

    if (this->denominator < 0) // if the Fraction is negative - make numerator negative and denominator positive.
    {
        this->numerator *= -1;
        this->denominator *= -1;
    }
    
    reduceFrac();
}

Fraction::Fraction(float number)
{
    int numerator = (number * 1000);
    int denominator = 1000;

    this->numerator = numerator;
    this->denominator = denominator;
    
    reduceFrac();
}

void Fraction::reduceFrac()
{
    int gcd = std::gcd(this->numerator, this->denominator);
    this->numerator = this->numerator / gcd;
    this->denominator = this->denominator / gcd;
}

int Fraction::getNumerator() const
{
    return this->numerator;
}

int Fraction::getDenominator() const
{
    return this->denominator;
}

Fraction ariel::operator+(const Fraction &fraction1, const Fraction &fraction2)
{
    long num = static_cast<long>(fraction1.getNumerator()) * fraction2.getDenominator() + static_cast<long>(fraction2.getNumerator()) * fraction1.getDenominator();
    long denom = static_cast<long>(fraction1.getDenominator()) * fraction2.getDenominator();

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    if (num > max_int || num < min_int || denom > max_int || denom < min_int)
    {
        throw overflow_error("overflow error!");
    }

    return Fraction(num, denom);
}

Fraction ariel::operator-(const Fraction &fraction1, const Fraction &fraction2)
{
    long num = static_cast<long>(fraction1.getNumerator()) * fraction2.getDenominator() - static_cast<long>(fraction2.getNumerator()) * fraction1.getDenominator();
    long denom = static_cast<long>(fraction1.getDenominator()) * fraction2.getDenominator();

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    if (num > max_int || num < min_int || denom > max_int || denom < min_int)
    {
        throw overflow_error("overflow error!");
    }

    return Fraction(num, denom);
}

Fraction ariel::operator*(const Fraction &fraction1, const Fraction &fraction2)
{
    long num = static_cast<long>(fraction1.getNumerator()) * fraction2.getNumerator();
    long denom = static_cast<long>(fraction1.getDenominator()) * fraction2.getDenominator();

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    if (num > max_int || num < min_int || denom > max_int || denom < min_int)
    {
        throw overflow_error("overflow error!");
    }

    return Fraction(num, denom);
}

Fraction ariel::operator/(const Fraction &fraction1, const Fraction &fraction2)
{
    if (fraction2.getNumerator() == 0)
    {
        throw runtime_error("illegal to divide by 0");
    }

    long num = static_cast<long>(fraction1.getNumerator()) * fraction2.getDenominator();
    long denom = static_cast<long>(fraction1.getDenominator()) * fraction2.getNumerator();

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    if (num > max_int || num < min_int || denom > max_int || denom < min_int)
    {
        throw overflow_error("overflow error!");
    }

    return Fraction(num, denom);
}

bool ariel::operator==(const Fraction &fraction1, const Fraction &fraction2)
{

    return fraction1.getNumerator() * fraction2.getDenominator() == fraction2.getNumerator() * fraction1.getDenominator();
}

bool ariel::operator<(const Fraction &fraction1, const Fraction &fraction2)
{
    return fraction1.getNumerator() * fraction2.getDenominator() < fraction2.getNumerator() * fraction1.getDenominator();
}

bool ariel::operator>(const Fraction &fraction1, const Fraction &fraction2)
{
    return fraction1.getNumerator() * fraction2.getDenominator() > fraction2.getNumerator() * fraction1.getDenominator();
}

bool ariel::operator<=(const Fraction &fraction1, const Fraction &fraction2)
{
    return fraction1.getNumerator() * fraction2.getDenominator() <= fraction2.getNumerator() * fraction1.getDenominator();
}

bool ariel::operator>=(const Fraction &fraction1, const Fraction &fraction2)
{
    return fraction1.getNumerator() * fraction2.getDenominator() >= fraction2.getNumerator() * fraction1.getDenominator();
}

Fraction &Fraction::operator++()
{
    this->numerator += this->denominator;
    reduceFrac();

    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp(*this);
    ++(*this);

    return temp;
}

Fraction &Fraction::operator--()
{
    this->numerator -= this->denominator;
    reduceFrac();
    
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction temp(*this);
    --(*this);

    return temp;
}

ostream &ariel::operator<<(ostream &ostream, const Fraction &other)
{
    return (ostream << other.getNumerator() << '/' << other.getDenominator());
}

istream &ariel::operator>>(istream &istream, Fraction &other)
{
    int numerator, denominator;

    istream >> numerator >> denominator;

    if (denominator == 0)
    {
        throw runtime_error("denominator can't be zero");
    }

    if (istream.fail() == true)
    {
        throw runtime_error("stream must include two arguments!");
    }

    if (denominator < 0) // if the Fraction is negative - make numerator negative and denominator positive.
    {
        numerator *= -1;
        denominator *= -1;
    }

    other.numerator = numerator;
    other.denominator = denominator;
    other.reduceFrac();

    return istream;
}
