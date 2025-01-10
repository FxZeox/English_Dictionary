#include "Dictionary.h"
#include <cstdlib> // Include for system()

int main() {
    Dictionary dictionary;
    dictionary.LoadDictionary("Dictionary.txt");

    std::string command, word;
    while (true) {
        system("clear"); // Clear the console screen
        std::cout<<"------------------------\n";
        std::cout << "Dictionary Application\n";
        std::cout << "------------------------\n";
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a word\n";
        std::cout << "2. Search for a word\n";
        std::cout << "3. Delete a word\n";
        std::cout << "4. Update a word\n";
        std::cout << "5. Suggest words\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> command;

        if (command == "1") {
            std::string word, meaning;
            std::cout << "Enter the word: ";
            std::cin >> word;
            std::cout << "Enter the meaning: ";
            std::cin.ignore(); // To ignore the newline character left in the buffer
            std::getline(std::cin, meaning);
            dictionary.AddWord(word, meaning);
            std::cout << "Word added successfully. Press Enter to continue...";
            std::cin.ignore(); // Wait for user to press Enter
            std::cin.get(); // Clear the input buffer
        } else if (command == "2") {
            std::cout << "Enter the word to search: ";
            std::cin >> word;
            dictionary.SearchWord(word);
            std::cout << "Press Enter to continue...";
            std::cin.ignore(); // Wait for user to press Enter
            std::cin.get(); // Clear the input buffer
        } else if (command == "3") {
            std::cout << "Enter the word to delete: ";
            std::cin >> word;
            dictionary.DeleteWord(word);
            std::cout << "Press Enter to continue...";
            std::cin.ignore(); // Wait for user to press Enter
            std::cin.get(); // Clear the input buffer
        } else if (command == "4") {
            std::cout << "Enter the word to update: ";
            std::cin >> word;
            std::cout << "Enter the new meaning: ";
            std::string newMeaning;
            std::cin.ignore(); // To ignore the newline character left in the buffer
            std::getline(std::cin, newMeaning);
            dictionary.UpdateWord(word, newMeaning);
            std::cout << "Press Enter to continue...";
            std::cin.ignore(); // Wait for user to press Enter
            std::cin.get(); // Clear the input buffer
        } else if (command == "5") {
            std::cout << "Enter the prefix for suggestions: ";
            std::cin >> word;
            dictionary.WordSuggestion(word);
            std::cout << "Press Enter to continue...";
            std::cin.ignore(); // Wait for user to press Enter
            std::cin.get(); // Clear the input buffer
        } else if (command == "6") {
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}
