#include <iostream>
#include <string>
#include "FileHasher.h"

using namespace std;

int main()
{
    string file1, file2;

    cout << "===== FILE HASH COMPARISON =====\n";
    cout << "Enter path of first file: ";
    getline(cin, file1);

    cout << "Enter path of second file: ";
    getline(cin, file2);

    FileHasher hasher;

    string hash1 = hasher.calculateHash(file1);
    string hash2 = hasher.calculateHash(file2);

    if (hash1.empty())
    {
        cout << "Error: Could not read the first file. Check its path.\n";
        return 1;
    }

    if (hash2.empty())
    {
        cout << "Error: Could not read the second file. Check its path.\n";
        return 1;
    }

    cout << "\nFile 1: " << file1 << '\n';
    cout << "SHA-256 Hash: " << hash1 << "\n\n";

    cout << "File 2: " << file2 << '\n';
    cout << "SHA-256 Hash: " << hash2 << "\n\n";

    if (hash1 == hash2)
    {
        cout << "Result: The hashes match. The files have identical contents.\n";
    }
    else
    {
        cout << "Result: The hashes are different. The files have different contents.\n";
    }

    return 0;
}
