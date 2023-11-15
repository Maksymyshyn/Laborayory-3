#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowel(char c) {
    setlocale(LC_ALL, "ukr");
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int countVowels(const std::string& word) {
    setlocale(LC_ALL, "ukr");
    return std::count_if(word.begin(), word.end(), isVowel);
}

int countConsonants(const std::string& word) {
    setlocale(LC_ALL, "ukr");
    return std::count_if(word.begin(), word.end(), [](char c) {
        return std::isalpha(c) && !isVowel(c);
        });
}

bool isPalindrome(const std::string& word) {
    setlocale(LC_ALL, "ukr");
    std::string reversed = word;
    std::reverse(reversed.begin(), reversed.end());
    return word == reversed;
}

int main() {  
    setlocale(LC_ALL, "ukr");
    std::string inputText;
    cout << "Введіть текстовий рядок: ";
    std::getline(std::cin, inputText);

    std::vector<std::string> words;
    size_t start = 0, end = 0;

    while ((end = inputText.find(' ', start)) != std::string::npos) {
        words.push_back(inputText.substr(start, end - start));
        start = end + 1;
    }
    words.push_back(inputText.substr(start));

    int countMatchingWords = 0;
  
    std::string longestWord;
  
    std::vector<std::string> nonPalindromes;

    for (const auto& word : words) {
        int vowels = countVowels(word);
        int consonants = countConsonants(word);

        if (vowels == consonants) {
            countMatchingWords++;
        }

        if (word.length() > longestWord.length()) {
            longestWord = word;
        }

        if (!isPalindrome(word)) {
            nonPalindromes.push_back(word);
        }
    }

    cout << "Кількість слів з однаковою кількістю голосних і приголосних: " << countMatchingWords << std::endl;
    cout << "Найдовше слово: " << longestWord << std::endl;
    cout << "Текст без паліндромів: ";
    for (const auto& word : nonPalindromes) {
        cout << word << " ";
    }

    return 0;
}
