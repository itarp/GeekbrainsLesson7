#include <iostream>
#include <fstream>
#include <string>
#include "mylib.h"

void task1();
void task2();
void task3();
void task4();

void arrayShow(int* array, const size_t size);
void bubbleSort(int* array, const size_t size);


int main()
{
    //В заданиях использую динамические массивы.
    //Для удобочитаемости программу в заданиях на функции не разделяю. Если это не определено заданием.
    std::cout << "=================================== Task1 ===================================" << std::endl;
    task1();
    std::cout << "=================================== Task2 ===================================" << std::endl;
    task2();
    std::cout << "=================================== Task3 ===================================" << std::endl;
    task3();
    std::cout << "=================================== Task4 ===================================" << std::endl;
    task4();
}

void task1(){
    //Создайте проект из 2х cpp файлов и заголовочного(main.cpp,
    //mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции:
    //для инициализации массива(типа float), печати его на экран и
    //подсчета количества отрицательных и положительных
    //элементов.Вызывайте эти 3 - и функции из main для работы с
    //массивом.

    //Сделайте задание 1 добавив свой неймспейс во втором
    //модуле(первое задание тогда можно не делать)
    size_t size = 20;
    float* array = new float[size];
    mylib::arrayInit(array, size);
    mylib::arrayShow(array, size);
    mylib::countPositiveNegative(array, size);
    delete[] array;
}

#define INRANGE(num, limit) (((num) >= 0) && ((num) < (limit)) ? true : false)
void task2() {
    //Описать макрокоманду(через директиву define),
    //проверяющую, входит ли переданное ей число(введенное с
    //клавиатуры) в диапазон от нуля(включительно) до переданного
    //ей второго аргумента(исключительно) и возвращает true или
    //false, вывести на экран «true» или «false».
    int num(0), maxRange(0);
    std::cout << "Enter a number within the range: ";
    std::cin >> num;
    std::cout << "Enter the upper limit of the range: ";
    std::cin >> maxRange;
    std::cout << (INRANGE(num, maxRange) ? "true" : "false") << std::endl;
}

#define SIZE 10
#define SwapINT(a, b) a ^= b ^= a ^= b   
void task3() {
    //Задайте массив типа int. Пусть его размер задается через
    //директиву препроцессора #define.Инициализируйте его через
    //ввод с клавиатуры.Напишите для него свою функцию
    //сортировки(например Пузырьком).Реализуйте перестановку
    //элементов как макрокоманду SwapINT(a, b).Вызывайте ее из
    //цикла сортировки.
    int *array = new int[SIZE] {0};
    //Инициализация массива пользователем
    std::cout << "Enter " << SIZE << " integers to initialize the array: ";
    for (int i = 0; i < SIZE; i++)
        std::cin >> *(array + i);
    //Отобразить массив после инициализации
    arrayShow(array, SIZE);
    //Отсортировать массив в порядке возростания
    bubbleSort(array,SIZE);
    //Отобразить массив после сортировки
    arrayShow(array, SIZE);
    delete[] array;
}

void arrayShow(int* array, const size_t size) {
    for (int i = 0; i < size; i++)
        std::cout << *(array + i) << "   ";
    std::cout << std::endl;
}

void bubbleSort(int *array, const size_t size) {
    for (int i = 1; i < size; i++)
        for (int ii = size - 1; ii >= i; ii--) {
            if (*(array + ii - 1) > *(array + ii))
                SwapINT(*(array + ii - 1), *(array + ii));
        }
}

#pragma pack(push, 1)
struct employee {
    unsigned int ID;    //Идентификационный номер
    char name[32];      //ФИО сотрудника
    int age;            //Возраст
    char position[32];  //Специальность, должность
    char address[64];   //Адрес
    char email[24];     //Електронная почта 
    char phone[17];     //Номер телефона
    bool active;        //Действующий сотрудник
};
#pragma pack(pop)

void task4() {
    //Объявить структуру Сотрудник с различными полями.
    //Сделайте для нее побайтовое выравнивание с помощью
    //директивы pragma pack.Выделите динамически переменную
    //этого типа.Инициализируйте ее.Выведите ее на экран и ее
    //размер с помощью sizeof.Сохраните эту структуру в текстовый
    //файл.
    employee* empl = new employee;
    //Инициализировать структуру информацией о сотруднике
    empl->ID = 2;
    strcpy_s(empl->name, "Jon Smith");
    empl->age = 21;
    strcpy_s(empl->position, "Developer");
    strcpy_s(empl->address, "Russia, Moscow");
    strcpy_s(empl->email, "JonSmith@mail");
    strcpy_s(empl->phone, "+7(012)345-67-89");
    empl->active = true;

    //Вывести на экран данные о сотруднике
    std::cout << "---------- Employee data --------------" << std::endl;
    std::cout << "ID number: " << empl->ID << std::endl;
    std::cout << "Name: " << empl->name << std::endl;
    std::cout << "Age: " << empl->age<< std::endl;
    std::cout << "Position: " << empl->position << std::endl;
    std::cout << "Addres: " << empl->address << std::endl;
    std::cout << "Email: " << empl->email << std::endl;
    std::cout << "Phone: " << empl->phone << std::endl;
    std::cout << "Active: " << ((empl->active) ? "Yes" : "No") << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    //Вывести размер структуры
    std::cout << "Size struct employee: " << sizeof(*empl) << std::endl;

    //Записать структуру в текстовый файл
    std::ofstream fout("data.txt");

    fout << "---------- Employee data --------------" << std::endl;
    fout << "ID number: " << empl->ID << std::endl;
    fout << "Name: " << empl->name << std::endl;
    fout << "Age: " << empl->age << std::endl;
    fout << "Position: " << empl->position << std::endl;
    fout << "Addres: " << empl->address << std::endl;
    fout << "Email: " << empl->email << std::endl;
    fout << "Phone: " << empl->phone << std::endl;
    fout << "Active: " << ((empl->active) ? "Yes" : "No") << std::endl;
    fout << "---------------------------------------" << std::endl;
    fout.close();

    //Записать структуру в бинарный файл
    const std::string FileName = "data.bin";
    std::ofstream foutbin(FileName, std::ios_base::binary);
    if(foutbin.is_open()) {
        foutbin.write((char*)empl, sizeof(*empl));
        foutbin.close();
    }

    delete empl;
}
