#include "puzzle.h"

#include <cstring>
#include <iostream>

Puzzle::Puzzle(QString path):
    isLoaded(false),
    puzzleInfo(),
    run(nullptr),
    getErrorCode(nullptr),
    getPuzzleGUID(nullptr),
    getPuzzleInfo(nullptr),
    library(path),
    GUID(puzzleGUID)
{
    library.load();

    this->isLoaded = library.isLoaded();
    if (this->isLoaded)
    {

        this->getPuzzleGUID =
                reinterpret_cast<getPuzzleGUID_t>(library.resolve("getPuzzleGUID"));

        if (nullptr != this->getPuzzleGUID)
        {
            // Check if the loaded library is a puzzle
            PuzzleGUID puzzleGUID = getPuzzleGUID();
            int result = strcmp(this->GUID, puzzleGUID);
            // If the GUIDs are equal then it should be a puzzle
            bool isPuzzle = (result == 0);
            if (isPuzzle)
            {
                this->getErrorCode =
                        reinterpret_cast<getErrorCode_t>(library.resolve("getErrorCode"));
                this->getPuzzleInfo =
                        reinterpret_cast<getPuzzleInfo_t>(library.resolve("getPuzzleInfo"));
                this->run =
                        reinterpret_cast<run_t>(library.resolve("run"));

                // Get the information about the puzzle
                this->puzzleInfo = getPuzzleInfo();
            }
            else
            {
                // This is not a valid puzzle
                isLoaded = false;
                this->library.unload();
            }
        }

    }
}

Puzzle::~Puzzle()
{
    delete this->puzzleInfo;
    std::cout << "Destroying object of: class Puzzle" << std::endl;
}

