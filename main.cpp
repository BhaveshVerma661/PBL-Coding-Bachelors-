#include <iostream>
#include <vector>
#include <map>
#include "FileInfo.h"
#include "FileScanner.h"
#include "FileHasher.h"
using namespace std;
int main()
{
    string folderPath;
    cout << "Enter folder path: ";
    getline(cin, folderPath);
    FileScanner scanner;
    FileHasher hasher;
    vector<FileInfo> files = scanner.scanFolder(folderPath);
    map<string, vector<string>> duplicateGroups;
    for (FileInfo& file : files)
    {
        string hash = hasher.calculateHash(file.getPath());
        if (hash != "")
        {
            duplicateGroups[hash].push_back(file.getPath());
        }
    }
    cout << "\nDuplicate Files:\n";
    bool foundDuplicate = false;
    for (auto group : duplicateGroups)
    {
        if (group.second.size() > 1)
        {
            foundDuplicate = true;
            cout << "\nDuplicate Group:\n";
            for (string path : group.second)
            {
                cout << path << endl;
            }
        }
    }
    if (!foundDuplicate)
    {
        cout << "No duplicate files found.\n";
    }
    return 0;
}