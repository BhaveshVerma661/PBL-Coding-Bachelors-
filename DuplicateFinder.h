#pragma once
#include <vector>
#include <string>
#include "FileInfo.h"
using namespace std;
class DuplicateFinder
{
public:
    void findDuplicates(vector<FileInfo>& files);
};