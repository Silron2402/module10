#Импорт класса
import vectors_class

#Создание вектора чере конструктор с параметрами
v1 = vectors_class.Vector(0.1, 0.5, 2.5)

#создание вектора через параметрический конструктор
v2 = vectors_class.Vector()
 
#вывод вектора c помощью метода print
v1.print()
v2.print()

#Тестирование метода для расчета длины вектора
print("len v1 is:", v1.length())

#Тестирование метода для расчета нормы вектора
print("norm v1 is:", v1.norm_vec())

#нормализация вектора
v1.normalize()

#Вывод нормализованного вектора
v1.print()

#Создадим новый вектор
v3 = vectors_class.Vector(3.0, 4.0, 5.1)

#Тестирование операции суммирования
v4 = vectors_class.add(v1, v3)
v4.print()

#Тестирование операции вычитания
v5 = vectors_class.substract(v1, v3)
v5.print()

#Тестирование операции скалярного произведения
dot_v = vectors_class.vector_dot(v1, v3)
print(dot_v)




