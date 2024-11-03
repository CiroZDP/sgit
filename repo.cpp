#include <Windows.h>
#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>

#include "repo.hpp"

using namespace std;
namespace fs = std::filesystem;

void Repository::init()
{
    if (isInitialized()) {
        std::cerr << "      The repository is already initialized!" << endl;
        exit(1);
    }

    fs::create_directory(sgitDir);
    createConfigFile(sgitDir / "config.xml");
    set_head("master");
    Sleep(750);
}

void Repository::restart()
{
    // 1. Delete .sgit folder
    fs::remove_all(sgitDir);

    // 2. Initialize the repo again
    init();
}

void Repository::commit(hash_t hash)
{
    fs::path commitsDir = sgitDir / "commits";
    if (!fs::exists(commitsDir))
        fs::create_directory(commitsDir);

    if (!isInitialized()) {
        std::cerr << "      No repository in this folder." << endl;
        exit(1);
    }

    ofstream commitf(commitsDir / hash);
    {
        // Write basic commit file
        commitf << "Commit!!!" << endl;
    }
    commitf.close();

}

void Repository::set_head(s_branch branch)
{
    const fs::path branch_dir = sgitDir / "refs" / "heads";
    const fs::path branch_path = branch_dir / branch;

    // Create folders if doesn't exists
    if (!fs::exists(branch_dir))
        fs::create_directories(branch_dir);

    // Write HEAD file
    ofstream headf(sgitDir / "HEAD");
    {
        headf << "ref: " << branch_path;
    }
    headf.close();
}

bool Repository::isInitialized()
{
    return fs::exists(sgitDir);
}

void Repository::createConfigFile(fs::path configPath)
{
    ofstream configFile(configPath);
    {
        // Write basic configuration file
        configFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        configFile << "<repo>\n";
        configFile << "    <description>Modify this field to add a description to your repo.</description>\n";
        configFile << "</repo>\n";
    }
    configFile.close();
}
