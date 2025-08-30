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

    py::class_<Vector3D>(m, "Vector")
        .def(py::init<>())
        // Параметризованный конструктор
        .def(py::init<double, double, double>(),
             py::arg("x") = 0.0, py::arg("y") = 0.0, py::arg("z") = 0.0)
        .def("length", &Vector3D::length)
        .def("norm_vec", &Vector3D::norm_vec)
        .def("normalize",&Vector3D::normalize)
        .def("print", &Vector3D::print);

    
    
    m.def("add", &addVector, R"pbdoc( add two numbers)pbdoc");
}