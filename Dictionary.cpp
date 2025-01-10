#include "Dictionary.h"

Dictionary::Dictionary() : root(nullptr) {}

void Dictionary::insert(TreeNode*& node, const std::string& word, const std::string& meaning) {
    if (node == nullptr) {
        node = new TreeNode(word, meaning);
    } else if (word < node->word) {
        insert(node->left, word, meaning);
    } else {
        insert(node->right, word, meaning);
    }
}

void Dictionary::LoadDictionary(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        size_t pos = line.find('\t');
        if (pos != std::string::npos) {
            std::string word = line.substr(0, pos);
            std::string meaning = line.substr(pos + 1);
            insert(root, word, meaning);
        }
    }
}

void Dictionary::AddWord(const std::string& word, const std::string& meaning) {
    insert(root, word, meaning);
}

void Dictionary::SearchWord(const std::string& word) {
    TreeNode* current = root;
    while (current != nullptr) {
        if (word == current->word) {
            std::cout << "Meaning of " << word << ": " << current->meaning << std::endl;
            return;
        } else if (word < current->word) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    std::cout << "Word not found." << std::endl;
}

void Dictionary::UpdateWord(const std::string& word, const std::string& newMeaning) {
    TreeNode* current = root;
    while (current != nullptr) {
        if (word == current->word) {
            char confirmation;
            std::cout << "Do you want to update the word '" << word << "'? (Y/N): ";
            std::cin >> confirmation;

            if (confirmation == 'Y' || confirmation == 'y') {
                current->meaning = newMeaning;
                std::cout << "Word updated successfully." << std::endl;
            } else {
                std::cout << "Update canceled." << std::endl;
            }
            return;
        } else if (word < current->word) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    std::cout << "Word not found." << std::endl;
}

void Dictionary::DeleteWord(const std::string& word) {
    root = deleteNode(root, word);
}

TreeNode* Dictionary::deleteNode(TreeNode* node, const std::string& word) {
    if (node == nullptr) {
        std::cout << "Word not found." << std::endl;
        return node;
    }

    if (word < node->word) {
        node->left = deleteNode(node->left, word);
    } else if (word > node->word) {
        node->right = deleteNode(node->right, word);
    } else {
        // Word found
        char confirmation;
        std::cout << "Do you want to delete the word '" << word << "'? (Y/N): ";
        std::cin >> confirmation;

        if (confirmation == 'Y' || confirmation == 'y') {
            // Node with one child or no child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode* temp = node->right;
            while (temp && temp->left != nullptr) {
                temp = temp->left;
            }

            // Copy the inorder successor's content to this node
            node->word = temp->word;
            node->meaning = temp->meaning;

            // Delete the inorder successor
            node->right = deleteNode(node->right, temp->word);
        } else {
            std::cout << "Deletion canceled." << std::endl;
        }
    }
    return node;
}

void Dictionary::WordSuggestion(const std::string& prefix) {
    const int maxSuggestions = 10;
    std::string suggestions[maxSuggestions];
    int count = 0;

    suggestWords(root, prefix, suggestions, count);
    
    std::cout << "Suggestions for '" << prefix << "':" << std::endl;
    for (int i = 0; i < count && i < maxSuggestions; ++i) {
        std::cout << suggestions[i] << std::endl;
    }
}

void Dictionary::suggestWords(TreeNode* node, const std::string& prefix, std::string suggestions[], int& count) {
    if (node == nullptr || count >= 10) {
        return;
    }

    if (node->word.find(prefix) == 0) { // Check if the word starts with the prefix
        suggestions[count++] = node->word;
    }

    suggestWords(node->left, prefix, suggestions, count);
    suggestWords(node->right, prefix, suggestions, count);
}
