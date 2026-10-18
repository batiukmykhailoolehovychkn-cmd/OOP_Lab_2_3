#include <iostream>
#include "Fraction.h"
#include <windows.h>

// Для перевірки розміру з вирівнюванням 1 байт
#pragma pack(push, 1)
class FractionPacked {
    long integerPart;
    unsigned short fractionalPart;
};
#pragma pack(pop)

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "--- Перевірка розміру класу ---" << endl;
    cout << "Розмір класу Fraction без #pragma pack(1): " << sizeof(Fraction) << " байт" << endl;
    cout << "Розмір класу з #pragma pack(1): " << sizeof(FractionPacked) << " байт\n" << endl;

    // 1. Демонстрація конструкторів
    Fraction f1;
    cout << "Конструктор за умовчанням (f1): " << f1 << endl;

    Fraction f2(5, 5000); // 5.5000
    cout << "Конструктор ініціалізації (f2): " << f2 << endl;

    Fraction f3(f2);
    cout << "Конструктор копіювання (f3 = f2): " << f3 << endl;

    // 2. Демонстрація створення масиву об'єктів
    cout << "\n--- Масив об'єктів ---" << endl;
    Fraction arr[3] = { Fraction(1, 2000), Fraction(-3, 5000), Fraction(10, 999) };
    for (int i = 0; i < 3; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    // 3. Перевірка методів доступу
    cout << "\n--- Перевірка методів доступу (Get/Set) ---" << endl;
    f1.SetIntegerPart(42);
    f1.SetFractionalPart(1500); // 42.1500
    cout << "f1 після Set: " << f1.GetIntegerPart() << " (ціла), " << f1.GetFractionalPart() << " (дробова)" << endl;

    cout << "Спроба ввести некоректну дробову частину:" << endl;
    f1.SetFractionalPart(15000); // Викличе помилку, бо >= 10000

    // 4. Демонстрація арифметичних операцій (дружні функції)
    cout << "\n--- Арифметичні операції (+, *) ---" << endl;
    Fraction a(2, 5000); // 2.5
    Fraction b(1, 5000); // 1.5
    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;

    // 5. Демонстрація унарних операцій (інкремент/декремент)
    cout << "\n--- Унарні операції (++, --) ---" << endl;
    cout << "Початкове значення a: " << a << endl;
    ++a;
    cout << "Префіксний ++a (додає 1 до цілої): " << a << endl;
    --a;
    cout << "Префіксний --a (віднімає 1 від цілої): " << a << endl;
    a++;
    cout << "Постфіксний a++ (збільшує дробову на 0.01): " << a << endl;
    a--;
    cout << "Постфіксний a-- (зменшує дробову на 0.01): " << a << endl;

    // 6. Введення з клавіатури та присвоєння
    cout << "\n--- Введення з клавіатури ---" << endl;
    Fraction f4;
    cin >> f4;
    cout << "Введений дріб: " << f4 << endl;

    Fraction f5;
    f5 = f4; // Перевірка operator=
    cout << "Перевірка присвоєння (f5 = f4): " << f5 << endl;

    return 0;
}