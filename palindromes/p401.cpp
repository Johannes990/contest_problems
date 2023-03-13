#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(std::string& str) {
    // check if str and the reverse of str are the same string

    std::string copy(str);
    std::reverse(copy.begin(), copy.end());
    
    if (str == copy)
        return true;
    return false;
}

std::string reverseString(std::string& str) {
    // create an element-wise reversed string based on the given character mapping

    std::string returnString = "";
    std::string character = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    std::string reverse = "A---3--HIL-JM-O---2TUVWXY51SE-Z--8-";

    for (auto ch: str)
        for (int i = 0; i < character.length(); ++i)
            if (ch == character[i])
                returnString += reverse[i];

    return returnString;
}

bool isMirror(std::string& str) {
    // check if str and its mirror string are the same string

    std::string reversed = reverseString(str);

    if (reversed.find('-') == std::string::npos) {
        std::string reversedCopy(reversed);
        std::reverse(reversedCopy.begin(), reversedCopy.end());

        if (reversedCopy == str)
            return true;
        return false;
    } else {
        return false;
    }
}

int main() {
    std::string word = "";
    while (std::cin >> word) {
        bool palindrome = isPalindrome(word);
        bool mirror = isMirror(word);

        if (!(palindrome) && !(mirror))
            std::cout << word << " -- is not a palindrome.\n" << std::endl;
            //std::cout << std::endl;
        if (palindrome && !(mirror))
            std::cout << word << " -- is a regular palindrome.\n" << std::endl;
            //std::cout << std::endl;
        if (!(palindrome) && mirror)
            std::cout << word << " -- is a mirrored string.\n" << std::endl;
            //std::cout << std::endl;
        if (palindrome && mirror)
            std::cout << word << " -- is a mirrored palindrome.\n" << std::endl;
            //std::cout << std::endl;
    }
}