#include <iostream>
#include <cstdio>
using namespace std;

class StringOperations
{
public:
    int string_length(const char *str);
    void string_compare(const char *str1, const char *str2);
    void string_concatenate(const char *str1, const char *str2);
    bool tryAgain();
};

int StringOperations::string_length(const char *str) {
    int length = 0;
    while (*str != '\0') {
        str++;
        length++;
    }
    return length;
}

void StringOperations::string_compare(const char *str1, const char *str2) {
    int xlength = string_length(str1);
    int ylength = string_length(str2);
    if (xlength == ylength) {
        cout << "Both strings are equal";
    } else if (xlength > ylength) {
        cout << "First string is longer";
    } else if (xlength < ylength) {
        cout << "Second string is longer";
    }
}

void StringOperations::string_concatenate(const char *str1, const char *str2)
{

    int string1 = string_length(str1);
    int string2 = string_length(str2);
    int totalLength = string1 + string2;
    char *concatenated = new char[totalLength];
    int i = 0;

    while(*str1) {
        concatenated[i++] = *str1++;
    }

    while (*str2) {
        concatenated[i++] = *str2++;
    }

    concatenated[i] = '\0';
    cout << "Concatenated string is: " << concatenated << endl;
}

bool StringOperations::tryAgain() {
    char choice;
    cout << "Try again? [Y/N]: ";
    cin >> choice;
    cin.ignore();

    return (choice == 'Y' || choice == 'y');
}
int main()
{
    StringOperations operations;
    string choice;
    const int size = 100;
    char *x = new char[size];
    char *y = new char[size];
    bool running = true;
    do
    {
        const char *options[] = {"Find the string length", "Compare two strings", "Concatenate two strings", "Exit"};
        cout << "What do you want to do?\n";
        for (int i = 0; i < sizeof(options) / sizeof(options[0]); i++)
        {
            printf("%d. %s\n", i + 1, options[i]);
        }
        cout << "Enter your choice: ";
        getline(cin, choice);
        



        if (choice == "1")
        {
            cout << "Enter a string: ";
            cin.getline(x, size);
            cout << "Length of the string is: " << operations.string_length(x) << endl
                 << endl;
        }
        else if (choice == "2")
        {
            cout << "Enter the first string: ";
            cin.getline(x, size);
            cout << "Enter the second string: ";
            cin.getline(y, size);
            operations.string_compare(x, y);
        }
        else if (choice == "3")
        {
            cout << "Enter the first string: ";
            cin.getline(x, size);
            cout << "Enter the second string: ";
            cin.getline(y, size);
            operations.string_concatenate(x, y);
        }
        else if (choice == "4")
        {
            delete[] x;
            delete[] y;
            return 0;
        }
        else
        {
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            cin.clear();
        }
        running = operations.tryAgain();
        cout << endl;
    } while (running);
    return 0;
}