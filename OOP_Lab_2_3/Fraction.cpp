#include "Fraction.h"
#include <sstream>
#include <iomanip>
#include <cmath>

// Конструктор за умовчанням
Fraction::Fraction() : integerPart(0), fractionalPart(0) {}

// Конструктор ініціалізації
Fraction::Fraction(long intPart, unsigned short fracPart) {
    SetIntegerPart(intPart);
    SetFractionalPart(fracPart);
}

// Конструктор копіювання
Fraction::Fraction(const Fraction& other)
    : integerPart(other.integerPart), fractionalPart(other.fractionalPart) {
}

// Геттери
long Fraction::GetIntegerPart() const { return integerPart; }
unsigned short Fraction::GetFractionalPart() const { return fractionalPart; }

// Сеттери з контролем коректності
void Fraction::SetIntegerPart(long intPart) {
    integerPart = intPart;
}

void Fraction::SetFractionalPart(unsigned short fracPart) {
    if (fracPart < FRAC_BASE) {
        fractionalPart = fracPart;
    }
    else {
        cerr << "Помилка: дробова частина має бути < " << FRAC_BASE << "! Встановлено 9999." << endl;
        fractionalPart = FRAC_BASE - 1;
    }
}

// Перетворення в double для зручності обчислень
double Fraction::ToDouble() const {
    double frac = (double)fractionalPart / FRAC_BASE;
    return integerPart >= 0 ? integerPart + frac : integerPart - frac;
}

// Відновлення об'єкта з double
void Fraction::FromDouble(double val) {
    integerPart = (long)trunc(val);
    fractionalPart = (unsigned short)abs(round((val - integerPart) * FRAC_BASE));
}

// Операція присвоєння
Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        integerPart = other.integerPart;
        fractionalPart = other.fractionalPart;
    }
    return *this;
}

// Приведення типу (перетворення у рядок)
Fraction::operator string() const {
    stringstream ss;
    if (integerPart == 0 && ToDouble() < 0) ss << "-"; // Обробка випадку -0.xxxx
    ss << integerPart << "." << setfill('0') << setw(4) << fractionalPart;
    return ss.str();
}

// Оператор виводу
ostream& operator<<(ostream& out, const Fraction& f) {
    out << string(f);
    return out;
}

// Оператор вводу
istream& operator>>(istream& in, Fraction& f) {
    long intP;
    unsigned short fracP;
    cout << "Введіть цілу частину: ";
    in >> intP;
    cout << "Введіть дробову частину (від 0 до 9999): ";
    in >> fracP;
    f.SetIntegerPart(intP);
    f.SetFractionalPart(fracP);
    return in;
}

// Префіксний інкремент (збільшує цілу частину)
Fraction& Fraction::operator++() {
    ++integerPart;
    return *this;
}

// Префіксний декремент (зменшує цілу частину)
Fraction& Fraction::operator--() {
    --integerPart;
    return *this;
}

// Постфіксний інкремент (збільшує дробову частину)
Fraction Fraction::operator++(int) {
    Fraction temp(*this);
    double val = ToDouble() + 0.0100; // Додаємо 100 "десятитисячних"
    FromDouble(val);
    return temp;
}

// Постфіксний декремент (зменшує дробову частину)
Fraction Fraction::operator--(int) {
    Fraction temp(*this);
    double val = ToDouble() - 0.0100;
    FromDouble(val);
    return temp;
}

// Бінарне додавання (зовнішня дружня функція)
Fraction operator+(const Fraction& f1, const Fraction& f2) {
    Fraction result;
    result.FromDouble(f1.ToDouble() + f2.ToDouble());
    return result;
}

// Бінарне множення (зовнішня дружня функція)
Fraction operator*(const Fraction& f1, const Fraction& f2) {
    Fraction result;
    result.FromDouble(f1.ToDouble() * f2.ToDouble());
    return result;
}