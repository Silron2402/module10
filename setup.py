from setuptools import setup, Extension
import pybind11
import os

# Определяем расширение
vector3d_module = Extension(
    'vectors_class',
    sources=[
        'src/main.cpp',  # Файл с обвязкой
        'src/vector3d.cpp'          # Реализация класса
    ],
    include_dirs=[
        pybind11.get_include(),     # Включаем директорию pybind11
        '.'                   # Директория с заголовочными файлами
    ],
    language='c++'
)

setup(
    name='vectors_class',
    version='0.1.0',
    author='Andrew',
    author_email='your.email@example.com',
    description='Python bindings for Vector3D C++ class',
    long_description='',
    ext_modules=[vector3d_module],
    install_requires=[
        'pybind11'
    ],
    classifiers=[
        'Programming Language :: Python :: 3',
        'Programming Language :: C++',
        'Operating System :: OS Independent'
    ]
)

