#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>

class TreeNode {
public:
    std::string word;
    std::string meaning;
    TreeNode* left;
    TreeNode* right;

    TreeNode(std::string w, std::string m) : word(w), meaning(m), left(nullptr), right(nullptr) {}
};

class Dictionary {
private:
    TreeNode* root;

    void insert(TreeNode*& node, const std::string& word, const std::string& meaning);
    void loadFromFile(const std::string& filename);
    TreeNode* deleteNode(TreeNode* node, const std::string& word);
    void suggestWords(TreeNode* node, const std::string& prefix, std::string suggestions[], int& count); // Updated declaration

public:
    Dictionary();
    void LoadDictionary(const std::string& filename);
    void displayLoadingMessage();
    void AddWord(const std::string& word, const std::string& meaning);
    void DeleteWord(const std::string& word);
    void SearchWord(const std::string& word);
    void UpdateWord(const std::string& word, const std::string& newMeaning);
    void WordSuggestion(const std::string& prefix);
};

#endif // DICTIONARY_H
