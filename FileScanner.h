#pragma once
#include "FileInfo.h"
#include <vector>
#include <string>
using namespace std;
class FileScanner
{
public:
    vector<FileInfo> scanFolder(string folderPath);
};