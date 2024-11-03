#include <iostream>
#include <string>

#include "color.hpp"
#include "repo.hpp"
#include "hashutils.hpp"

using namespace std;
static Repository repo = Repository();

namespace sgit
{

    void init_repo()
    {
        std::cout << ricon(Symbols::REPO_REFRESH);
        std::cout << " Creating new repository...\r";

        repo.init();

        std::cout << ricon(Symbols::REPO_CREATE);
        std::cout << " Repository created!                \n";
    }

    void restart()
    {
        if (!repo.isInitialized())
        {
            std::cout << rerror();
            std::cout << " No repository in this folder." << endl;
            exit(1);
        }

        std::cout << "      Are you sure about restarting this repo (y/n)? ";
        string option = "n";
        std::cin >> option;

        if (tolower(option.at(0)) != 'y')
        {
            std::cout << rerror();
            std::cout << " Restarting cancelled!" << endl;
            exit(0);
        }

        std::cout << ricon(Symbols::REPO_REFRESH);
        std::cout << " Restarting repository...\r";

        repo.restart();

        std::cout << ricon(Symbols::REPO_REFRESH);
        std::cout << " Repository restarted successfully!\n";
        exit(0);
    }

    void checkout(s_branch branch)
    {
        repo.set_head(branch);
    }

    void commit(char *args[])
    {
        string option = args[2];
        if (option == "-m")
            std::cout << "Commit message: " << args[3] << endl;

        repo.commit(crypto::generateSHA(256));
    }

}

void usage();

int main(int argc, char *argv[])
{
    if (argc == 1)
        usage();

    string cmd = string(argv[1]);
    Repository repo = Repository();

    if (cmd == "commit")
        sgit::commit(argv);

    else if (cmd == "init")
        sgit::init_repo();

    else if (cmd == "restart")
        sgit::restart();
}

void usage()
{
    std::cout << "No le sabe cño" << endl;
    exit(0);
}
