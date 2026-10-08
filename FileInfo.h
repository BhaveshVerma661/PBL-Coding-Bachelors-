#pragma once
#include <string>
using namespace std;
class FileInfo
{
private:
    string name;
    string path;
    string extension;
    long long size;
    string hash;
public:
    FileInfo(string n, string p, string e, long long s);
    string getName();
    string getHash();
}; //Bhavesh