#include <string>

#include "hashutils.hpp"

using namespace std;

hash_t crypto::generateSHA(int id)
{
    int hash_len = id / 4;

    string strHash = "";
    for (int i = 0; i < hash_len; i++)
        strHash += "0";

    return strHash;
}
