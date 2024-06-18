#include <iostream>
#include <algorithm>
#include <random>
#include <Windows.h>

std::string reverse(const std::string& word) {
    std::string reversedWord = word;
    std::reverse(reversedWord.begin(), reversedWord.end());
    return reversedWord;
}

std::string removeVowels(const std::string& word) {
    std::string result;
    for (char c : word) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c;
        }
    }
    return result;
}

std::string removeConsonants(const std::string& word) {
    std::string result;
    for (char c : word) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            result += c;
        }
    }
    return result;
}

std::string shuffle(const std::string& word) {
    std::string shuffledWord = word;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffledWord.begin(), shuffledWord.end(), g);
    return shuffledWord;
}

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;

    std::cout << "Меню:\n";
    std::cout << "1. Вывести слово задом наперед.\n";
    std::cout << "2. Вывести слово без гласных.\n";
    std::cout << "3. Вывести слово без согласных.\n";
    std::cout << "4. Рандомно раскидать буквы заданного слова.\n";
    std::cout << "Выберите действие (1-4): ";

    int choice;
    std::cin >> choice;

    std::string modifiedWord;
    switch (choice) {
    case 1:
        modifiedWord = reverse(word);
        break;
    case 2:
        modifiedWord = removeVowels(word);
        break;
    case 3:
        modifiedWord = removeConsonants(word);
        break;
    case 4:
        modifiedWord = shuffle(word);
        break;
    default:
        std::cout << "Некорректный выбор.\n";
        return 0;
    }

    std::cout << "Измененное слово: " << modifiedWord << std::endl;

    return 0;
}