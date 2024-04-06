#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

bool isPalindrome(const string& str, int start, int end)
{
    
    if (start >= end)
        return true;

    while (!isalnum(str[start]) && start < end)
        ++start;
    while (!isalnum(str[end]) && end > start)
        --end;
        
    char c1 = tolower(str[start]);
    char c2 = tolower(str[end]);
    
    if (c1 != c2)
        return false;
    
    return isPalindrome(str, start + 1, end - 1);
}

string reverseString(const string& str, int index)
{

    if (index < 0)
        return "";

    return str[index] + reverseString(str, index - 1);
}

int main()
{
    string input;
    char choice;

    do
    {
        cout << "Enter a string: ";
        getline(cin, input);

        if (isPalindrome(input, 0, input.length() - 1))
            cout << "The string is a palindrome." << endl;
        else
            cout << "The string is not a palindrome." << endl;
        string reversed = reverseString(input, input.length() - 1);
        cout << "Reversed string: " << reversed << endl;

        cout << "Do you want to enter another string? (y/n): ";
        cin >> choice;
        cin.ignore();
    } 
    while (choice == 'y' || choice == 'Y');

    cout << "Goodbye!" << endl;

    return 0;
}
