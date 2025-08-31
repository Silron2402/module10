#include <iostream>
#include "vector3d.h"
#include <pybind11/pybind11.h>

//Сложение векторов
Vector3D addVector(std::shared_ptr<Vector3D> vec1, std::shared_ptr<Vector3D> vec2)
{
    return Vector3D((*vec1)(0) + (*vec2)(0),
                   (*vec1)(1) + (*vec2)(1),
                   (*vec1)(2) + (*vec2)(2));
}

//Вычитание векторов
Vector3D substractVector(std::shared_ptr<Vector3D> vec1, std::shared_ptr<Vector3D> vec2)
{
    return Vector3D((*vec1)(0) - (*vec2)(0),
                   (*vec1)(1) - (*vec2)(1),
                   (*vec1)(2) - (*vec2)(2));
}

//Скалярное произведение векторов
double dotVector(std::shared_ptr<Vector3D> vec1, std::shared_ptr<Vector3D> vec2)
{
    return (*vec1)(0) * (*vec2)(0) +
           (*vec1)(1) * (*vec2)(1) +
           (*vec1)(2) * (*vec2)(2);
}

namespace py = pybind11;

PYBIND11_MODULE(vectors_class, m)
{
    m.doc() = R"pbdoc(
      Pybind11 test
      -------------
    )pbdoc";
    //введено указание на то, что класс относится к shared_ptr
    py::class_<Vector3D,std::shared_ptr<Vector3D>>(m, "Vector")
        // Конструктор по умолчанию
        .def(py::init<>())

        // Параметризованный конструктор
        .def(py::init<double, double, double>(),
             py::arg("x") = 0.0, py::arg("y") = 0.0, py::arg("z") = 0.0)

        // Метод для расчета длины вектора
        .def("length", &Vector3D::length, "returns length of your vector")

        // Метод для расчета нормы вектора
        .def("norm_vec", &Vector3D::norm_vec, "return norm of your vector")

        // Метод для нормализации вектора
        .def("normalize", &Vector3D::normalize, "normalizes your vector")

        // Метод для вывода вектора
        .def("print", &Vector3D::print, "prints your vector")

        // Доступ к первому элементу вектора (геттер и сеттер, реализоанные через лямбда функцию) 
        .def_property("x", [](Vector3D &self)
                      { return self(0); }, [](Vector3D &self, double value)
                      { self(0) = value; })

        // Доступ ко второму элементу вектора (геттер и сеттер, реализоанные через лямбда функцию) 
        .def_property("y", [](Vector3D &self)
                      { return self(1); }, [](Vector3D &self, double value)
                      { self(1) = value; }) 

        // Доступ к третьему элементу вектора (геттер и сеттер, реализоанные через лямбда функцию) 
        .def_property("z", [](Vector3D &self)
                      { return self(2); }, [](Vector3D &self, double value)
                      { self(2) = value; });  



    m.def("add", &addVector, R"pbdoc( add two vectors)pbdoc", py::arg("v1"), py::arg("v2"));
    
    m.def("substract", &substractVector, R"pbdoc( substract two vectors)pbdoc", py::arg("v1"), py::arg("v2"));

    m.def("vector_dot", &dotVector, R"pbdoc( scalar multiplication of two vectors)pbdoc", py::arg("v1"), py::arg("v2"));
}