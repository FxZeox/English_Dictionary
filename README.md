# Dictionary Application

A simple dictionary application in C++ that allows users to add, search, delete, update, and suggest words based on a file input. The dictionary is implemented using a binary search tree (BST) structure.

## Features
- **Add a word**: Add a new word with its meaning to the dictionary.
- **Search for a word**: Look up the meaning of a word in the dictionary.
- **Delete a word**: Remove a word from the dictionary.
- **Update a word**: Modify the meaning of an existing word.
- **Word suggestions**: Get word suggestions based on a prefix.
- **Load dictionary from file**: The dictionary can be loaded from a text file.

## Requirements
- C++ compiler (C++11 or later)
- Standard C++ library

## Files
- `Dictionary.h`: Contains the class definitions and method declarations.
- `Dictionary.cpp`: Contains the class implementations for the dictionary functionality.
- `main.cpp`: The main program that interacts with the user and utilizes the `Dictionary` class.
- `Dictionary.txt` (Example): A text file containing words and their meanings (each word and its meaning are separated by a tab).

## How to Run
1. Clone the repository or download the files.
2. Compile the code using a C++ compiler:
   ```bash
   g++ main.cpp Dictionary.cpp -o dictionary

    Run the program:

    ./dictionary

    Follow the menu prompts in the terminal to interact with the dictionary:
            Add a word
            Search for a word
            Delete a word
            Update a word
            Suggest words
            Exit



How the Dictionary Works:

The dictionary is implemented using a Binary Search Tree (BST) where each node contains:

    A word (string)
    The meaning of the word (string)
    Pointers to the left and right child nodes for the tree structure.

Operations:

    Insert: Adds a new word to the tree, maintaining the sorted order.
    Search: Searches for a word in the tree and displays its meaning.
    Delete: Deletes a word from the tree.
    Update: Allows the user to update the meaning of a word.
    Word Suggestions: Suggests words that begin with a given prefix.
