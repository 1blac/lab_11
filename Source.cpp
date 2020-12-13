// Lab_11.1.cpp
// <Чорний Дмитро>
// Лабораторна робота № 11.1.
// Бінарні файли
// Варіант 30 
#include <iostream>
#include<fstream>
#include <Windows.h>
#include <time.h>

using namespace std;

void Create(const char* File_Name)
{
    ofstream First_File(File_Name, ios::binary);

    int x;

    for (int i = 0; i < 20; i++)
    {
        x = (2 * (20 * 1.)) * rand() / RAND_MAX - (20 * 1.);
        First_File.write((char*)&x, sizeof(x));
    }
}

void Print(const char* File_Name)
{
    cout << "Вміст файлу з усіма числами : ";

    ifstream First_File(File_Name, ios::binary);
    int x;

    while (First_File.read((char*)&x, sizeof(x)))
    cout << x << " ";
    cout << endl;
}

void Find(const char* File_Name, const char* File_Result_Parity, const char* File_Result_Oddness)
{
    ifstream First_File(File_Name, ios::binary);
    ofstream Second_File(File_Result_Parity, ios::binary);
    ofstream Third_File(File_Result_Oddness, ios::binary);
    int x;
    while (First_File.read((char*)&x, sizeof(x)))
    {
        if (x % 2 == 0)
            Second_File.write((char*)&x, sizeof(x));
        if (x % 2 != 0)
            Third_File.write((char*)&x, sizeof(x));
    }
}

void Print_Parity(const char* File_Result_Parity)
{
    cout << "Вміст файлу з парними числами: ";

    ifstream Second_File(File_Result_Parity, ios::binary);
    
    int x;

    while (Second_File.read((char*)&x, sizeof(x)))
        cout << x << " ";
    cout << endl;

}
void Print_Oddness(const char* File_Result_Oddness)
{
    cout << "Вміст файлу з непарними числами: ";

    ifstream Third_File(File_Result_Oddness, ios::binary);
    
    int x;

    while (Third_File.read((char*)&x, sizeof(x)))
        cout << x << " ";
    cout << endl;
}
int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Create("FirstFile.dat");
    Print("FirstFile.dat");

    Find("FirstFile.dat", "Result 1.dat", "Result 2.dat");
    Print_Parity("Result 1.dat");
    Print_Oddness("Result 2.dat");

    return 0;
}