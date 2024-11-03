#pragma once

#ifndef COLOR_H
#define COLOR_H 1

#include <string>

using namespace std;

class Symbols
{
public:
    /* SEMICIRCLES */
    static const string O_SEMICIRCLE;
    static const string C_SEMICIRCLE;

    /* BRANCH */
    static const string BRANCH;
    static const string BRANCH_VERIFIED;
    static const string BRANCH_DELETE;
    static const string BRANCH_CREATE;
    static const string BRANCH_REFRESH;
    
    /* REPO (DATABASE) */
    static const string REPO;
    static const string REPO_REFRESH;
    static const string REPO_CREATE;

    /* ERROR/WARNINGS */
    static const string ERROR;

};

class Colors
{
public:
    class Foreground
    {
    public:
        static const string BLUE;
        static const string WHITE;
        static const string RED;
    };

    class Background
    {
    public:
        static const string BLUE;
        static const string RED;
    };
    
    static const string RESET, EMPTY;
};

/* --- Symbols --- */

/* SEMICIRCLES */
const string Symbols::O_SEMICIRCLE = "\xee\x82\xb6";
const string Symbols::C_SEMICIRCLE = "\xee\x82\xb4";

/* BRANCH */
const string Symbols::BRANCH          = "\xef\x84\xA6";
const string Symbols::BRANCH_VERIFIED = "\xf3\xb1\x93\x8f";
const string Symbols::BRANCH_DELETE   = "\xf3\xb1\x93\x8b";
const string Symbols::BRANCH_CREATE   = "\xf3\xb1\x93\x8a";
const string Symbols::BRANCH_REFRESH  = "\xf3\xb1\x93\x8d";

/* REPO */
const string Symbols::REPO        = "\xef\x87\x80";
const string Symbols::REPO_REFRESH = "\xf3\xb0\x97\x82";
const string Symbols::REPO_CREATE = "\xf3\xb0\x86\xba";

/* ERROR/WARNINGS */
const string Symbols::ERROR = "\xee\xaa\x87";

/* --- Colors --- */
const string Colors::RESET = "\033[0m";
const string Colors::EMPTY = "";

/* FOREGROUND */
const string Colors::Foreground::BLUE  = "\033[0;36m";
const string Colors::Foreground::WHITE = "\033[0;37m";
const string Colors::Foreground::RED   = "\033[0;31m";

/* BACKGROUND */
const string Colors::Background::BLUE  = "\033[0;46m";
const string Colors::Background::RED   = "\033[41m";

/* --- Functions --- */

/**
 * Makes the icon to be between two semicircles.
 * 
 * @param ic The icon       (Symbols)
 * @param f1 The foreground (Colors::Foreground)
 * @param b1 The background (Colors::Background)
 * @param f2 The background (Colors::Foreground)
 */
string ricon(string ic, string f1, string b1, string f2)
{
    return 
        f2               // Apply background as foreground to paint the semicircle
        + Symbols::O_SEMICIRCLE
        + b1             // Apply background to paint the space
        + " "            // Space
        + f1             // Foreground to paint the icon
        + b1             // Background
        + ic             // The icon itself (branch, repo,...)
        + " "            // Space
        + f2             // Apply background as foreground to paint the semicircle
        + Symbols::C_SEMICIRCLE
        + Colors::RESET
        ;
}

string ricon(string ic)
{
    return ricon(ic,
        Colors::Foreground::WHITE,
        Colors::Background::BLUE,
        Colors::Foreground::BLUE
    );
}

string rerror()
{
    return ricon(
        Symbols::ERROR,
        Colors::Foreground::WHITE,
        Colors::Background::RED,
        Colors::Foreground::RED
    );
}

#endif // COLOR_H