#include <iostream>
#include "vector3d.h"
#include <memory>

//функция доступа к элементам вектора
double &Vector3D::operator()(int row)
{
    if (row > 3)
    {
        std::cerr << "Vector: element number is out of bounds" << std::endl;
    };
    return coords[row]; 
}

/*
    const double &Vector3D::operator()(int index) const {
        if (index >= 3) {
            std::cerr << "Vector: element number is out of bounds" << std::endl;
        }
        return coords[index];
    }*/

// Метод, предназначенный для вывода вектора в консоль
void Vector3D::print()
{
    for (int i = 0; i < 3; ++i)
    {
        std::cout << coords[i] << " ";
    }
    std::cout << std::endl;
}

// Оператор присваивания копированием
Vector3D &Vector3D::operator=(const Vector3D &vect)
{
    // проверка отсутствия самоприсваивания
    if (&vect != this)
        for (int i = 0; i < 3; ++i)
        {
            this->coords[i] = vect.coords[i];
        }
    return *this;
}
//Оператор присваивания перемещением
Vector3D &Vector3D::operator=(Vector3D&& moved) //noexcept
{
    if (&moved != this) // избегаем самоприсваивания
    {
        coords = nullptr;
        coords = std::move(moved.coords);
        moved.coords = nullptr;
    }
    return *this;
}

// Метод для вычисления длины вектора
double Vector3D::length()
{
    return std::sqrt(coords[0] * coords[0] +
                     coords[1] * coords[1] +
                     coords[2] * coords[2]);
}
 
// Метод для вычисления нормы вектора (квадрата длины)
double Vector3D::norm_vec() const
{
    return coords[0] * coords[0] +
           coords[1] * coords[1] +
           coords[2] * coords[2];
}

//Метод для нормализации вектора 
void Vector3D::normalize()
{
    //рассчитаем длину вектора
    double len = length();

    if (len == 0)
    {
        std::cerr << "Vector: lenght is null" << std::endl;
    }
    for (int i = 0; i < 3; ++i)
    {
        // Делим все координаты на длину вектора
        coords[i] /= len;
    }

}

std::ostream &operator<<(std::ostream &out, const Vector3D &v)
{
    if (v.coords) //проверим существует ли указатель
    {
        out << "[ ";

        for (int i = 0; i < 3; ++i)
        {
            out << v.coords[i] << " ";
        }

        out << "]";

        out << std::endl;

        return out;
    }
    out << "this vector does not exist";
    return out;
}
