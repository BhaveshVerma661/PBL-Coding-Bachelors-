#include "FileHasher.h"
#include <fstream>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

using namespace std;

string FileHasher::calculateHash(string filePath)
{
    ifstream file(filePath, ios::binary);

    if (!file)
    {
        return "";
    }

    SHA256_CTX context;
    SHA256_Init(&context);

    char buffer[4096];

    while (file.read(buffer, sizeof(buffer)))
    {
        SHA256_Update(&context, buffer, file.gcount());
    }

    if (file.gcount() > 0)
    {
        SHA256_Update(&context, buffer, file.gcount());
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &context);

    stringstream result;

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        result << hex << setw(2) << setfill('0') << (int)hash[i];
    }

    return result.str();
}
