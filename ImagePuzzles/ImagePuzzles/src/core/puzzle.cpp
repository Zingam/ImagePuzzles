#include "puzzle.h"

#include <iostream>

Puzzle::Puzzle(QString path):
    isLoaded(false),
    puzzleInfo(),
    library(path),
    run(nullptr),
    getPuzzleInfo(nullptr)
{
    library.load();

    this->isLoaded = library.isLoaded();
    if (this->isLoaded)
    {
        this->getPuzzleInfo =
                reinterpret_cast<getPuzzleInfo_t>(library.resolve("getPuzzleInfo"));
        this->run =
                reinterpret_cast<run_t>(library.resolve("run"));

        this->puzzleInfo = getPuzzleInfo();
    }
}

Puzzle::~Puzzle()
{
    delete this->puzzleInfo;
    std::cout << "Destroying object of: class Puzzle" << std::endl;
}

