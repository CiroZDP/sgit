#pragma once

#ifndef HASHUTILS_H
#define HASHUTILS_H 1

#include <string>

typedef std::string hash_t;

namespace crypto
{

    hash_t generateSHA(int);

};

#endif // HASHUTILS_H
