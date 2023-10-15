#include <iostream>
#include "Header.h" // Включаем обновленный заголовочный файл

int main()
{
    // Создаем объект ObjectMass<int> и заполняем его данными
    ObjectMass<int> intArray;
    std::cin >> intArray;

    // Создаем объект ObjectMass<int> и заполняем его данными(рандомными)
    ObjectMass<int> intRandomArray;
    intRandomArray.createMassiv(10);

    // Выводим содержимое массива
    std::cout << "генерация массива: " << intArray << std::endl;
    std::cout << "генерация массива рандомного: " << intRandomArray << std::endl;

    // Сортируем массив
    intArray.sortedMass();
    intRandomArray.sortedMass();

    // Выводим отсортированный массив
    std::cout << "сортированный массив: " << intArray << std::endl;
    std::cout << "сортированный массив: " << intRandomArray << std::endl;

    // Создаем объект ObjectMass<float> и заполняем его данными
    ObjectMass<float> floatArray;
    std::cin >> floatArray;

    // Создаем объект ObjectMass<float> и заполняем его данными(рандомными)
    ObjectMass<float> floatRandomArray;
    floatRandomArray.createMassiv(10);

    // Выводим содержимое массива
    std::cout << "генерация массива: " << floatArray << std::endl;
    std::cout << "генерация массива рандомного: " << floatRandomArray << std::endl;

    // Сортируем массив
    floatArray.sortedMass();
    floatRandomArray.sortedMass();


    // Выводим отсортированный массив
    std::cout << "сортированный массив: " << floatArray << std::endl;
    std::cout << "сортированный массив: " << floatRandomArray << std::endl;

    // Создаем объект ObjectMass<float> и заполняем его данными
    ObjectMass<char> charArray;
    std::cin >> charArray;

    // Создаем объект ObjectMass<char> и заполняем его данными(рандомными)
    ObjectMass<char> charRandomArray;
    charRandomArray.createMassiv(10);

    // Выводим содержимое массива
    std::cout << "генерация массива: " << charArray << std::endl;
    std::cout << "генерация массива рандомного: " << charRandomArray << std::endl;

    // Сортируем массив
    charArray.sortedMass();
    charRandomArray.sortedMass();

    // Выводим отсортированный массив
    std::cout << "сортированный массив: " << charArray << std::endl;
    std::cout << "сортированный массив: " << charRandomArray << std::endl;


    return 0;
}