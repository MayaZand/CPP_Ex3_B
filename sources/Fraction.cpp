#include "Fraction.hpp"

using namespace ariel;

Fraction:: Fraction(): numerator(0), denominator(1){};
Fraction:: Fraction(int numerator, int denominator)
{   
    
    if (denominator == 0)
    {
        throw invalid_argument ("denominator can't be 0!");
    }
    this->denominator=denominator;
    this->numerator=numerator;
}

Fraction:: Fraction(float number) 
{
    int numerator = round(number * 1000);
    int denominator = 1000;
    int gcd_num = __gcd(numerator, denominator);
    numerator /= gcd_num;
    denominator /= gcd_num;
}


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
    int num = fraction1.getNumerator() * fraction2.getDenominator() + fraction2.getNumerator() * fraction1.getDenominator();
    int denom = fraction1.getDenominator() * fraction2.getDenominator();
    int gcd = std::gcd(num, denom);

    return Fraction(num/gcd, denom/gcd);
}

Fraction ariel:: operator-(const Fraction& fraction1, const Fraction& fraction2)
{
    int num = fraction1.getNumerator() * fraction2.getDenominator() - fraction2.getNumerator() * fraction1.getDenominator();
    int denom = fraction1.getDenominator() * fraction2.getDenominator();
    int gcd = std::gcd(num, denom);

    return Fraction(num/gcd, denom/gcd); 
}

Fraction ariel:: operator*(const Fraction& fraction1, const Fraction& fraction2)
{
    int num = fraction1.getNumerator() * fraction2.getNumerator();
    int denom = fraction1.getDenominator() * fraction2.getDenominator();
    int gcd = std::gcd(num, denom);

    return Fraction(num/gcd, denom/gcd); 

}

Fraction ariel:: operator/(const Fraction& fraction1, const Fraction& fraction2)
{
    int num = fraction1.getNumerator() * fraction2.getDenominator();
    int denom = fraction1.getDenominator() * fraction2.getNumerator();
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
    //simplify();
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
    //simplify();
    return *this;
}

Fraction Fraction:: operator--(int) 
{
    Fraction temp(*this);
    --(*this);
    return temp;
}

ostream& ariel:: operator<<(ostream& os, const Fraction& other)
{
    return (os << other.getNumerator() << '/' << other.getDenominator());
}

istream& ariel:: operator>>(istream& is, const Fraction& other) 
{
    return is;
}

