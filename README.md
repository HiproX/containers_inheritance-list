# Котейнеры. Наследование от списка.
> В.В. Лаптев: "C++. Объектно-ориентированное программирование: Учебное пособие. Задачи и упражнения" 2007 г.

### Глава 5. Задание 65.
>Должны быть реализованы безаргументные и инициализирующие конструкторы, в том числе конструктор с двумя аргументами, итераторами, конструктор копирования, деструктор, операция присваивания, ввод-вывод. Подходящие операции реализуются как методы класса, а остальные - как внешние дружественные функции. Должна быть поддержка обработки исключений по нехватки памяти: все конструкторы обязаны иметь спецификацию исключений bad_alloc.

>Использовать выделение памяти массивом, размер заранее не известен. Элементы могут вставляться в любое место массива; может быть удален любой элемент или группа элементов.

Реализовать класс Set (множество) типа double **используя наследование от класса List (см. листинг 5.4)**. Множество должно обеспечивать включение элемента в множество, исключение элемента из множества, объединение, пересечение и вычитание множеств, отслеживание количества элементов в множестве, проверку присутствия элемента в множестве, проверку включения одного множества в другое.
