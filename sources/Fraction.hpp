/* During the preperation of this assignment I used the internet and chat GPT */
#pragma once
#include <iostream>
#include <numeric> 
#include <cmath>

using namespace std;
namespace ariel
{
   class Fraction
   {

    /*fields - private by default: */
    int numerator;
    int denominator;

    /*constructors, copy constructor and destructor: */
    public:
    Fraction(); // default constructor - ???
    Fraction(int numerator, int denominator);
    Fraction(float number); // this constructor will convert float into a Fraction

    /*methods: */

    /*getters: */

    /*
    @return the numerator of the Fraction.
    */
    int getNumerator() const;
    
    /*
    @return the denominator of the Fraction.
    */
    int getDenominator() const;




    /*
    this methods add two fractions and return their sum as another fraction in reduced form. 
    @param fraction1 is the first fraction, on the left side of the operator.
    @param fraction2 is the second fraction, on the right side of the operator.
    @return the sum of two fractions.
    */

   friend Fraction operator+(const Fraction& fraction1, const Fraction& fraction2);

    /*
    this method subtract two fractions and return their difference as another fraction in reduced form.
    @param fraction1 is the first fraction, on the left side of the operator.
    @param fraction2 is the second fraction, on the right side of the operator.
    @return the subtraction of two fractions.
    */
   friend Fraction operator-(const Fraction& fraction1, const Fraction& fraction2);

    /*
    this method multiply two fractions and return their product as another fraction in reduced form.
    @param fraction1 is the first fraction, on the left side of the operator.
    @param fraction2 is the second fraction, on the right side of the operator.
    @return the multiplication of two fractions.
    */
   friend Fraction operator*(const Fraction& fraction1, const Fraction& fraction2);

    /*
    this method divide two fractions and return their quotient as another fraction in reduced form.
    @param fraction1 is the first fraction, on the left side of the operator.
    @param fraction2 is the second fraction, on the right side of the operator.
    @return the division of two fractions.
    */
   friend Fraction operator/(const Fraction& fraction1, const Fraction& fraction2);

    /*
    this method compare two fractions for equality and return true or false.
    @param fraction1 is the first fraction, on the left side of the operator.
    @param fraction2 is the second fraction, on the right side of the operator.
    @return true if two fractions are equal, and false otherwise.
    */
   friend bool operator==(const Fraction& fraction1, const Fraction& fraction2);


    /*
    this method compare two products and return true if the first product is less than the second, and false otherwise.
    @param fraction1 is the first fraction, on the left side of the operator.
    @param fraction2 is the second fraction, on the right side of the operator.
    @return true if fraction1 is smaller than fraction2, and false otherwise.
    */
   friend bool operator<(const Fraction& fraction1, const Fraction& fraction2);


    /*
    this method compare two products and return true if the second product is less than the first, and false otherwise.
    @param fraction1 is the first fraction, on the left side of the operator.
    @param fraction2 is the second fraction, on the right side of the operator.
    @return true if fraction1 is bigger than fraction2, and false otherwise.
    */
    friend bool operator>(const Fraction& fraction1, const Fraction& fraction2);


    /*
    this method compare two products and return true if the first product is less or equal to the second, and false otherwise.
    @param fraction1 is the first fraction, on the left side of the operator.
    @param fraction2 is the second fraction, on the right side of the operator.
    @return true if fraction1 is smaller or equal to fraction2, and false otherwise.
    */
    friend bool operator<=(const Fraction& fraction1, const Fraction& fraction2);


    /*
    this method compare two products and return true if the second product is less or equal to the first, and false otherwise.
    @param fraction1 is the first fraction, on the left side of the operator.
    @param fraction2 is the second fraction, on the right side of the operator.
    @return true if fraction1 is bigger or equal to fraction2, and false otherwise.
    */
    friend bool operator>=(const Fraction& fraction1, const Fraction& fraction2);






/////////////////////////////////////////////////////////////////////////////////
    /*
    this method adds 1 to the fraction - prefix implementation
    */
    Fraction& operator++();
        
    /*
    this method adds 1 to the fraction - postfix implementation
    */
    Fraction operator++(int);

    /*
    this method substracts 1 from the fraction - prefix implementation
    */
    Fraction& operator--();

    /*
    this method substracts 1 from the fraction - postfix implementation
    */
    Fraction operator--(int);

    /*
    this method prints a fraction to an output stream in the format “numerator/denominator”.
    @param os is the output stream
    */
    friend ostream& operator<<(ostream& ostream, const Fraction& other);

    /*
    this method reads a fraction from an input stream by taking two integers as input.
    @param is is the input stream
    */
    friend istream& operator>>(std::istream& istream, const Fraction& other);

   }; 

}

