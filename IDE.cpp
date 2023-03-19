

#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    std::ifstream in("int.txt");
    if (!in) {
        std::cout << "Файл не найден\n";
        return 1;
    }
    std::ofstream out("out.txt");
    if (!out) {
        std::cout << "Файл не найден\n";
        return 1;
    }
    int size;
    in >> size;
    int* arr = new int[size];


    for (int i = 0; i < size; i++) {
        in >> arr[i];
    }

    int size2;
    in >> size2;
    int* arr2 = new int[size2];


    for (int i = 0; i < size2; i++) {
        in >> arr2[i];
    }

    int tmp2;
    tmp2 = arr2[size2 - 1];
    for (int i = size2 - 1; i > 0; --i)
    {
        arr2[i] = arr2[i - 1];

    }
    arr2[0] = tmp2;
    out << size2 << "\n";


    for (int i = 0; i < size2; ++i) {

        out << arr2[i] << ' ';

    }

    int tmp;
    tmp = arr[0];
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];

    }
    arr[size - 1] = tmp;
    out << "\n" << size << "\n";

    for (int i = 0; i < size; i++) {

        out << arr[i] << ' ';
        std::cout << "\n";
    }

    in.close();
    out.close();
    delete[] arr2;
    delete[] arr;
    return 0;
}