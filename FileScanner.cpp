#include "FileScanner.h"
#include <filesystem>
#include <iostream>
using namespace std;
namespace fs = std::filesystem;
vector<FileInfo> FileScanner::scanFolder(string folderPath)
{
    vector<FileInfo> files;
    if (!fs::exists(folderPath))
    {
        cout << "Folder does not exist.\n";
        return files;
    }
    if (!fs::is_directory(folderPath))
    {
        cout << "Path is not a folder.\n";
        return files;
    }
    for (const auto& entry : fs::recursive_directory_iterator(folderPath))
    {
        if (fs::is_regular_file(entry))
        {
            string name = entry.path().filename().string();
            string path = entry.path().string();
            string extension = entry.path().extension().string();

            long long size = fs::file_size(entry.path());

            FileInfo file(name, path, extension, size);

            files.push_back(file);
        }
    }
    return files;
}