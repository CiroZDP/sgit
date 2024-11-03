#pragma once

#ifndef REPO_H
#define REPO_H 1

#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>

#include "hashutils.hpp"

using namespace std;
typedef string s_branch;
namespace fs = std::filesystem;

class Repository
{
public:
    fs::path path;
    fs::path sgitDir;

    Repository(const string& _path = "."): path(_path) {
        sgitDir = path / ".sgit";
    }

    void init();
    void restart();
    void commit(hash_t);
    void set_head(s_branch);

    bool isInitialized();

    void createConfigFile(fs::path);

};

#endif // REPO_H
