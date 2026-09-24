#include "FileInfo.h"
FileInfo::FileInfo(string n, string p, string e, long long s)
{
    name = n;
    path = p;
    extension = e;
    size = s;
}
string FileInfo::getName()
{
    return name;
}

string FileInfo::getPath()
{
    return path;
}

string FileInfo::getExtension()
{
    return extension;
}

long long FileInfo::getSize()
{
    return size;
}