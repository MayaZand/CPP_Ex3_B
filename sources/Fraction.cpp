#include "Fraction.hpp"

using namespace ariel;

Fraction:: Fraction(): numerator(0), denominator(1){};
Fraction:: Fraction(int numerator, int denominator)
{   
    
    if (denominator == 0)
    {
        throw invalid_argument ("denominator can't be 0!");
    }

    
    int gcd_num = __gcd(numerator, denominator);
    numerator /= gcd_num;
    denominator /= gcd_num;

    this->numerator = numerator;
    this->denominator = denominator;


    if (this->denominator < 0)
    {
        this->numerator*=-1;
        this->denominator*=-1;
    }
}

Fraction:: Fraction(float number) 
{
    int numerator = (number * 1000);
    int denominator = 1000;
    int gcd_num = __gcd(numerator, denominator);
    numerator /= gcd_num;
    denominator /= gcd_num;

    this->numerator = numerator;
    this->denominator = denominator;

    if (this->denominator < 0)
    {
        this->numerator*=-1;
        this->denominator*=-1;
    }
}

// float Fraction::fracToFloat()
// {
//     float num = this->getNumerator() / this->getDenominator();

//     return round(num*1000)/1000;
// }

int Fraction:: getNumerator() const
{
    return this->numerator;
}

int Fraction:: getDenominator() const
{
    return this->denominator;
}

Fraction ariel:: operator+(const Fraction& fraction1, const Fraction& fraction2)
{   
    long num = static_cast<long>(fraction1.getNumerator()) * fraction2.getDenominator() + static_cast<long>(fraction2.getNumerator()) * fraction1.getDenominator();
    long denom = static_cast<long>(fraction1.getDenominator()) * fraction2.getDenominator();

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    if (num>max_int || num<min_int || denom>max_int || denom<min_int)
    {
        throw overflow_error ("overflow error!");
    }
    // int num = fraction1.getNumerator() * fraction2.getDenominator() + fraction2.getNumerator() * fraction1.getDenominator();
    // int denom = fraction1.getDenominator() * fraction2.getDenominator();
    int gcd = std::gcd(num, denom);

    return Fraction(num/gcd, denom/gcd); 
}

Fraction ariel:: operator-(const Fraction& fraction1, const Fraction& fraction2)
{
    long num = static_cast<long>(fraction1.getNumerator()) * fraction2.getDenominator() - static_cast<long>(fraction2.getNumerator()) * fraction1.getDenominator();
    long denom = static_cast<long>(fraction1.getDenominator()) * fraction2.getDenominator();
    

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    if (num>max_int || num<min_int || denom>max_int || denom<min_int)
    {
        throw overflow_error ("overflow error!");
    }
    // int num = fraction1.getNumerator() * fraction2.getDenominator() - fraction2.getNumerator() * fraction1.getDenominator();
    // int denom = fraction1.getDenominator() * fraction2.getDenominator();
    int gcd = std::gcd(num, denom);

    return Fraction(num/gcd, denom/gcd); 
}

Fraction ariel:: operator*(const Fraction& fraction1, const Fraction& fraction2)
{
    long num = static_cast<long>(fraction1.getNumerator()) * fraction2.getNumerator();
    long denom = static_cast<long>(fraction1.getDenominator()) * fraction2.getDenominator();
    
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    if (num>max_int || num<min_int || denom>max_int || denom<min_int)
    {
        throw overflow_error ("overflow error!");
    }
    // int num = fraction1.getNumerator() * fraction2.getNumerator();
    // int denom = fraction1.getDenominator() * fraction2.getDenominator();
    int gcd = std::gcd(num, denom);

    return Fraction(num/gcd, denom/gcd); 

}

Fraction ariel:: operator/(const Fraction& fraction1, const Fraction& fraction2)
{
    if ( fraction2.getNumerator() == 0) 
    {
        throw runtime_error("Illegal to divide by 0");
    }

    long num = static_cast<long>(fraction1.getNumerator()) * fraction2.getDenominator();
    long denom = static_cast<long>(fraction1.getDenominator()) * fraction2.getNumerator();
    
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    if (num>max_int || num<min_int || denom>max_int || denom<min_int)
    {
        throw overflow_error ("overflow error!");
    }
    // int num = fraction1.getNumerator() * fraction2.getDenominator();
    // int denom = fraction1.getDenominator() * fraction2.getNumerator();
    int gcd = std::gcd(num, denom);

    return Fraction(num/gcd, denom/gcd); 
}

bool ariel:: operator==(const Fraction& fraction1, const Fraction& fraction2)
{

    return fraction1.getNumerator() * fraction2.getDenominator() == fraction2.getNumerator() * fraction1.getDenominator();
}

bool ariel:: operator<(const Fraction& fraction1, const Fraction& fraction2)
{
    return fraction1.getNumerator() * fraction2.getDenominator() < fraction2.getNumerator() * fraction1.getDenominator();
}

bool ariel:: operator>(const Fraction& fraction1, const Fraction& fraction2)
{
    return fraction1.getNumerator() * fraction2.getDenominator() > fraction2.getNumerator() * fraction1.getDenominator(); 
}

bool ariel::  operator<=(const Fraction& fraction1, const Fraction& fraction2)
{
    return fraction1.getNumerator() * fraction2.getDenominator() <= fraction2.getNumerator() * fraction1.getDenominator(); 
}

bool ariel:: operator>=(const Fraction& fraction1, const Fraction& fraction2)
{
    return fraction1.getNumerator() * fraction2.getDenominator() >= fraction2.getNumerator() * fraction1.getDenominator(); 
}

Fraction& Fraction:: operator++() 
{
    this->numerator += this->denominator;
    int gcd = std::gcd(this->numerator, this->denominator);

    this->numerator = this->numerator/gcd;
    this->denominator = this->denominator/gcd;
    
    return *this;
}

Fraction Fraction:: operator++(int) 
{
    Fraction temp(*this);
    ++(*this);
    
    return temp;
}

Fraction& Fraction::  operator--() 
{
    this->numerator -= this->denominator;
    int gcd = std::gcd(this->numerator, this->denominator);

    this->numerator = this->numerator/gcd;
    this->denominator = this->denominator/gcd;
    
    return *this;
}

Fraction Fraction:: operator--(int) 
{
    Fraction temp(*this);
    --(*this);
    
    return temp;
}

ostream& ariel:: operator<<(ostream& ostream, const Fraction& other)
{
    return (ostream << other.getNumerator() << '/' << other.getDenominator());
}

istream& ariel:: operator>>(istream& istream, Fraction& other) 
{
    int numerator, denominator;

    istream >> numerator >> denominator;
    
    if (denominator == 0)
    {
        throw runtime_error ("denominator can't be zero");
    }

    if (istream.fail() == true)
    {
        throw runtime_error ("stream must include two arguments!");
    }

    other.numerator = numerator;
    other.denominator = denominator;

    return istream;
}

