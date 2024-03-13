#include <iostream>
#include <string>

using namespace std;

int chekChoose(int a, int b) // ������� �������� �������� ������ ������ ���� �� ���������
{
    int i; //������� �����
    string str;// �������� ������
    do
    {
        i = 1;
        cout << "�������� ���� �����:" << endl;
        if (cin.peek() == '\n')
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        getline(cin, str);

        if (str.find_first_not_of("0123456789") != std::string::npos)
        {
            cout << "�������� ����� - ������� �����������. ���������� ��� ���!" << endl;
            cout << "\n\n" << endl;
            i = 0;
            continue;
        }

        if (stoi(str) < a || stoi(str) > b) // �������� ��������(1, 2 ��� 3), ���� int
        {
            cout << "�������� ����� - ����������� ������ ������ �������� ���!" << endl;
            cout << "�������� �������� � ��������� ����� " << a << " � " << b << ". ���������� ��� ���!" << endl;
            cout << "\n\n" << endl;
            i = 0;
        }
    } while (i == 0);
    return stoi(str); // ���������� � int � ������� int
}


int chekInt() // ������� �������� ������������ ����� ���������� ��������
{
    int i; //������� �����
    string str;// �������� ������
    do
    {
        i = 1;
        cout << "������� ������������� ��������:";
        if (cin.peek() == '\n')
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        getline(cin, str);

        if (str.find_first_not_of("0123456789") != std::string::npos)
        {
            cout << "�������� ���� - ������� �����������. ���������� ��� ���!" << endl;
            cout << "\n\n" << endl;
            i = 0;
            continue;
        }
    } while (i == 0);
    return stoi(str); // ���������� � int � ������� int
}


int main()
{
    setlocale(LC_ALL, "");


    int Y, x, d, z;// Y � �������� �� ������; x � ������ ������; d � �������� ����/������, +/-; z - ��������� ������� �� ������ (�������� �����); 
    size_t size; // size � ������ �������� ������
    string stroka;
    do
    {
        Y = 0; // ������ � ������ ����� ������� False
        cout << "�������� ��������: " << endl;
        cout << "��� ������ �������� ���������� � �+� ��� ���������� �����, �������������� � �-� �������: 1;" << endl;
        cout << "��� ������ �������� ���������� � �-� ��� ���������� �����, �������������� � �+� �������: 2;" << endl;
        d = chekChoose(1, 2);


        cout << "������� ������ ������ (������������� ����� �����): " << endl;
        x = chekInt();

        cout << "������� ����� ��� ��������� (������!!! ��������� �������� � ���������): " << endl;
        getline(cin, stroka);

        size = stroka.length();

        z = (x % 26); // ���� ����� ����� ��� ������ 26 � ���� ���������� ��� �� ������, ������� ��������� ������� �� ������� (�������� ����� ������ ������ 26);

        if (z == 0) // ������ ���� ��� ��������� 26
        {
            cout << "�� ������� �������� ������ ����� �� ��������" << endl;
        }
        else
        {
            switch (d)
            {
            case 1: // ���������� + / ������ -
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
            case 2: // ���������� - / ������ +
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
        cout << "����� ����� ���������: " << endl << stroka << endl;

        cout << endl << "���������� ������: �� - 1, ��� - 0: " << endl;
        Y = chekChoose(0, 1); // ����� ������� �������� ���������� � ������������ ���������� 1 ��� ��� 0
    } while (Y > 0);


    cout << "�� ��������!" << endl;
    return 0;
}
