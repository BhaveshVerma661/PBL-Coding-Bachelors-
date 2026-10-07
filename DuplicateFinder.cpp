#include "DuplicateFinder.h"
#include <iostream>
#include <unordered_map>
using namespace std;
void DuplicateFinder::findDuplicates(vector<FileInfo>& files)
{
    unordered_map<string, vector<string>> groups;
    for (int i = 0; i < files.size(); i++)
    {
        groups[files[i].getHash()].push_back(files[i].getPath());
    }
    cout << "\nDuplicate Files:\n";
    for (auto group : groups)
    {
        if (group.second.size() > 1)
        {
            cout << "\nDuplicate Group:\n";

            for (string path : group.second)
            {
                cout << path << endl;
            }
        }
    }
} 