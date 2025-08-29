#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Создадим класс для хранения координат вектора (coords)
class Vector3D
{
private:
    // Объявим закрытые переменные класса
    std::unique_ptr<double[]> coords; //умный указатель, который содержит массив значений double с неизвестным количеством элементов

public:
    // Конструктор без параметров
    Vector3D() : coords(std::make_unique<double[]>(3))
    {
        for (int i = 0; i < 3; ++i)
        {
            coords[i] = 0;
        }
        std::cout << "Called a default constructor" << std::endl;
    }

    // Конструктор с параметрами
    Vector3D(double x, double y, double z)
        : coords(std::make_unique<double[]>(3))
    {
        coords[0] = x;
        coords[1] = y;
        coords[2] = z;

        std::cout << "Called a constructor with parameters " << std::endl;
    }

    // Конструктор копирования
    Vector3D(const Vector3D &vec)
        : coords(std::make_unique<double[]>(3))
    {
        for (int i = 0; i < 3; ++i)
        {
            coords[i] = vec.coords[i];
        }
        std::cout << "Called a copy constructor" << std::endl;
    }

    // Конструктор перемещения
    Vector3D(Vector3D &&moved) noexcept
        : coords(std::move(moved.coords)) 
    {
        std::cout << "Called a move constructor" << std::endl;
    }

    // Деструктор*/
    ~Vector3D() { std::cout<<"Item destroyed\n"; }

    // перегрузка оператора доступа к элементам матрицы
    double &operator()(int row); // возврат значения по ссылке (знак &)
    
    //Метод для вывода элементов
    void print();


    //перегрузка оператора присваивания копированием
    Vector3D& operator= (const Vector3D &other);
    
    // перегрузка операции вывода
    friend std::ostream &operator<<(std::ostream &out, const Vector3D &v);

    Vector3D& operator= (Vector3D&& moved);

    // Метод для вычисления длины вектора
    double length();

    //Метод для вычисления нормы вектора
    double norm_vec() const;

    //Метод для нормализации ветора
    void normalize();


};