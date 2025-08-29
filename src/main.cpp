#include <iostream>
#include "vector3d.h"

void normalizeVector(std::shared_ptr<Vector3D> vec)
{
    if (!vec) // проверка на отсутствие инициализации указателя
    {
        std::cerr << "Vector: pointer is not initialized" << std::endl;
    }

    // расчет длины вектора
    double len = (*vec).length();

    if (len == 0)
    {
        std::cerr << "Vector: lenght is null" << std::endl;
    }
    for (int i = 0; i < 3; ++i)
    {
        // Делим все координаты на длину вектора
        (*vec)(i) /= len;
    }
    // vec->operator()(0) /= len;
    // vec->operator()(1) /= len;
    // vec->operator()(2) /= len;
}

int main()
{
    // Тестируем конструктор без параметров
    std::cout << "creating the first vector v0" << std::endl;
    Vector3D v0;

    //протестируем метод print
    std::cout << "testind the print() method" << std::endl;
    v0.print();

    //выведем вектор в консоль
    std::cout << std::endl;
    std::cout << "the vector v0 is "<< std::endl;
    std::cout << v0 << std::endl;

    //Тестируем конструктор с параметрами
    std::cout << "creating the second vector v1" << std::endl;
    Vector3D v1(1.5, 2.4, 3.1);
    std::cout << v1 << std::endl;
    
    //тестирование конструктора копирования
    Vector3D v2{v1};
    std::cout << "the vector v2 is "<< std::endl;
    std::cout << v2 << std::endl;

    //протестируем доступ к элементам вектора
    v2(0) = 1.;
    v2(1) = 2.;
    v2(2) = 3.;

    std::cout << "the new vector v2 is "<< std::endl;
    std::cout << v2 << std::endl;

    //тестирование оператора присваивания копированием
    Vector3D v3 = v2;
    std::cout << "the vector v3 is a copy of v2"<< std::endl;
    std::cout << v3 << std::endl;

    //тестируем конструктор перемещения
    Vector3D v4{std::move(v1)};
    std::cout << "the vector v4 is a moved v1"<< std::endl;
    std::cout << v4 << std::endl;
    std::cout << "what about the vector v1?"<< std::endl;
    std::cout << v1 << std::endl;

    //протестируем оператор присваивания с перемещением
    Vector3D v5 = std::move(v2);
    std::cout << std::endl;
    std::cout << "the vector v5 is "<< std::endl;
    std::cout << v5 << std::endl;
    std::cout << "what about the vector v2?"<< std::endl;
    std::cout << v2 << std::endl;


    // Создаем shared_ptr к вектору
    auto vec = std::make_shared<Vector3D>(2, 2, 2);
    //вывод по указателю
    std::cout << "source vector is: " << *vec << std::endl;
    
    //Тестирование функции для нормализации вектора
    normalizeVector(vec);
    std::cout << "normalized vector is: " << *vec << std::endl;

    //Найдем норму вектора
    std::cout << "a vector norm is: "<< (*vec).norm_vec() << std::endl;
    
    //протестируем метод для нормализации вектора
    // Создаем shared_ptr к вектору
    auto vec2 = std::make_shared<Vector3D>(2, 2, 2);
    //вывод по указателю
    std::cout << "source vector is: " << *vec2 << std::endl;
    (*vec2).normalize();
    std::cout << "normalized vector is: " << *vec2 << std::endl;

    



    return 0;


}