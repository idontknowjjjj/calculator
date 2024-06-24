#include <cmath>
#include <iostream>
#include <windows.h>

using namespace std;

float number() // Функция number считывает число из ввода
{
    int result = 0;
    while (true) //бесконечный цикл
    {
        char num1 = cin.get(); //используется для считывания чисел
        if (num1 >= '0' && num1 <= '9')
            result = result * 10 + num1 - '0';
        else
        {
            cin.putback(num1);
            return result;
        }
    }
}
float expr();
// Функция для обработки выражения в скобках
float round_brackets()
{
    char num1 = cin.get(); //используется для считывания скобок
    if (num1 == '(')
    {
        float num2 = expr();
        cin.get();
        return num2;
    }
    else if (num1 == 's') //если num1 равен символу s, то считаем корень
    {
        float num2 = round_brackets();
        return sqrt(num2);
    }
        cin.putback(num1);
        return number();
    }
// Функция для обработки умножения и деления
float factor()
{
    float num2 = round_brackets();

    while (true) //бесконечный цикл
    {
        char num1 = cin.get(); //используется для считывания операторов
        switch (num1)
        {
        case '*':
            num2 *= round_brackets();
            break;
        case '/':
            num2 /= round_brackets();
            break;
        default:
            cin.putback(num1);
            return num2;
        }
    }
}

// Функция для обработки сложения и вычитания
float expr()
{
    float num2 = factor();
    while (true) //бесконечный цикл
    {
        char num1 = cin.get(); //используется для считывания операторов
        switch (num1)
        {
        case '+':
            num2 += factor();
            break;
        case '-':
            num2 -= factor();
            break;
        default:
            cin.putback(num1);
            return num2;
        }
    }
}

//основная функция в которой все действия и происходят
int main()
{
    system("mode con cols=50 lines=30");
    setlocale(LC_ALL, "Russian");
    cout << "--------------------------------------------------\n"
        "                    ПРИМЕЧАНИЕ!\n"
        "       ЕСЛИ ВЫ ХОТИТЕ ИСПОЛЬЗОВАТЬ КОРЕНЬ,\n"
        "     ТО НАДО ПИСАТЬ НАЗВАНИЕ ФУНКЦИИИ НАЧАЛЕ,\n"
        "                А ТОЛЬКО ПОТОМ ЧИСЛА\n"
        "--------------------------------------------------"<< endl;
    cout << "Введите выражение: (s = корень)";
    long double result = expr();
    cout << "Результат: " << result << endl;
}
