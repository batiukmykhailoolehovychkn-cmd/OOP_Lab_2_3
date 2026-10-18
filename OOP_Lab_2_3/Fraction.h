#pragma once
#include <iostream>
#include <string>

using namespace std;

class Fraction {
private:
    long integerPart;              // Ціла частина із знаком
    unsigned short fractionalPart; // Дробова частина (від 0 до 9999)

    static const unsigned short FRAC_BASE = 10000; // База для дробової частини (4 знаки)

public:
    // Конструктори
    Fraction();
    Fraction(long intPart, unsigned short fracPart);
    Fraction(const Fraction& other);

    // Методи доступу
    long GetIntegerPart() const;
    unsigned short GetFractionalPart() const;
    void SetIntegerPart(long intPart);
    void SetFractionalPart(unsigned short fracPart);

    // Допоміжні методи для перетворень при математичних операціях
    double ToDouble() const;
    void FromDouble(double val);

    // Перевантаження обов'язкових операцій
    Fraction& operator=(const Fraction& other);
    operator string() const;

    // Дружні функції для вводу/виводу
    friend ostream& operator<<(ostream& out, const Fraction& f);
    friend istream& operator>>(istream& in, Fraction& f);

    // Унарні операції (як методи класу) - зміст визначено самостійно
    Fraction& operator++();    // Префіксний інкремент (+1 до цілої частини)
    Fraction& operator--();    // Префіксний декремент (-1 від цілої частини)
    Fraction operator++(int);  // Постфіксний інкремент (+100 до дробової частини)
    Fraction operator--(int);  // Постфіксний декремент (-100 від дробової частини)

    // Бінарні операції варіанту (як зовнішні дружні функції)
    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
};