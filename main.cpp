#include "FileScanner.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string folderPath;
    cout << "=====================================\n";
    cout << "      FILE DEDUPLICATION SYSTEM\n";
    cout << "=====================================\n\n";
    cout << "Enter folder path: ";
    getline(cin, folderPath);
    FileScanner scanner;
    vector<FileInfo> files = scanner.scanFolder(folderPath);
    cout << "\nFiles found: " << files.size() << "\n\n";
    for (FileInfo file : files)
    {
        cout << "Name: " << file.getName() << endl;
        cout << "Path: " << file.getPath() << endl;
        cout << "Extension: " << file.getExtension() << endl;
        cout << "Size: " << file.getSize() << " bytes" << endl;
        cout << "-------------------------------------\n";
    }
    return 0;
}