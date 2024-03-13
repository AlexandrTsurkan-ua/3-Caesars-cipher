#include <iostream>
#include <string>

using namespace std;

int chekChoose(int a, int b) // функция проверки верности выбора пункта меню из диапазона
{
    int i; //счетчик цикла
    string str;// вводимая строка
    do
    {
        i = 1;
        cout << "Сделайте свой выбор:" << endl;
        if (cin.peek() == '\n')
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        getline(cin, str);

        if (str.find_first_not_of("0123456789") != std::string::npos)
        {
            cout << "Неверный выбор - символы недопустимы. Попробуйте еще раз!" << endl;
            cout << "\n\n" << endl;
            i = 0;
            continue;
        }

        if (stoi(str) < a || stoi(str) > b) // проверка значений(1, 2 или 3), если int
        {
            cout << "Неверный выбор - возможности выбора такого значения нет!" << endl;
            cout << "Выберите значение в диапазоне между " << a << " и " << b << ". Попробуйте еще раз!" << endl;
            cout << "\n\n" << endl;
            i = 0;
        }
    } while (i == 0);
    return stoi(str); // приведение к int и возврат int
}


int chekInt() // функция проверки корректности ввода численного значения
{
    int i; //счетчик цикла
    string str;// вводимая строка
    do
    {
        i = 1;
        cout << "Введите запрашиваемое значение:";
        if (cin.peek() == '\n')
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        getline(cin, str);

        if (str.find_first_not_of("0123456789") != std::string::npos)
        {
            cout << "Неверный ввод - символы недопустимы. Попробуйте еще раз!" << endl;
            cout << "\n\n" << endl;
            i = 0;
            continue;
        }
    } while (i == 0);
    return stoi(str); // приведение к int и возврат int
}


int main()
{
    setlocale(LC_ALL, "");


    int Y, x, d, z;// Y – работаем ли дальше; x – размер сдвига; d – операция шифр/дешифр, +/-; z - результат деления по модулю (реальный сдвиг); 
    size_t size; // size – размер вводимой строки
    string stroka;
    do
    {
        Y = 0; // задаем в каждом цикле условие False
        cout << "Выберите операцию: " << endl;
        cout << "Для выбора операции шифрования в «+» или дешифровки шифра, зашифрованного в «-» введите: 1;" << endl;
        cout << "Для выбора операции шифрования в «-» или дешифровки шифра, зашифрованного в «+» введите: 2;" << endl;
        d = chekChoose(1, 2);


        cout << "Введите размер сдвига (положительное целое число): " << endl;
        x = chekInt();

        cout << "Введите фразу для обработки (только!!! латинские строчные и заглавные): " << endl;
        getline(cin, stroka);

        size = stroka.length();

        z = (x % 26); // если сдвиг равен или кратен 26 – шифр возвращает тот же символ, поэтому вычисляем остаток от деления (реальный сдвиг всегда меньше 26);

        if (z == 0) // описал выше про кратность 26
        {
            cout << "По данному значению сдвига фраза не меняется" << endl;
        }
        else
        {
            switch (d)
            {
            case 1: // шифрование + / дешифр -
                for (int i = 0; i < size; i++)
                {
                    if ((stroka[i] > 64) && (stroka[i] < 91))
                    {
                        if ((stroka[i] + z) < 91)
                        {
                            stroka[i] += z;
                        }
                        else
                        {
                            stroka[i] = stroka[i] + z - 26;
                        }
                    }
                    if ((stroka[i] > 96) && (stroka[i] < 123))
                    {
                        if ((stroka[i] + z) < 123)
                        {
                            stroka[i] += z;
                        }
                        else
                        {
                            stroka[i] = stroka[i] + z - 26;
                        }
                    }
                }
                break;
            case 2: // шифрование - / дешифр +
                for (int i = 0; i < size; i++)
                {
                    if ((stroka[i] > 64) && (stroka[i] < 91))
                    {
                        if ((stroka[i] - z) > 64)
                        {
                            stroka[i] -= z;
                        }
                        else
                        {
                            stroka[i] = stroka[i] - z + 26;
                        }
                    }
                    if ((stroka[i] > 96) && (stroka[i] < 123))
                    {
                        if ((stroka[i] - z) > 96)
                        {
                            stroka[i] -= z;
                        }
                        else
                        {
                            stroka[i] = stroka[i] - z + 26;
                        }
                    }
                }
                break;
            }
        }
        cout << "Фраза после обработки: " << endl << stroka << endl;

        cout << endl << "Продолжить работу: да - 1, нет - 0: " << endl;
        Y = chekChoose(0, 1); // через функцию проверки спрашиваем у пользователя продолжать 1 или нет 0
    } while (Y > 0);


    cout << "До свидания!" << endl;
    return 0;
}
