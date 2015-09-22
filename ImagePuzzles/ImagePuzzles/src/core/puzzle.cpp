#include "puzzle.h"

#include <cstring>
#include <iostream>

Puzzle::Puzzle(QString path):
    getErrorCode(nullptr),
    run(nullptr),
    isLoaded(false),
    puzzleInfo(),
    puzzleTitle(),
    fullPathName(path),
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
            PuzzleGUID lpuzzleGUID = getPuzzleGUID();
            int result = strcmp(this->GUID, lpuzzleGUID);
            // If the GUIDs are equal then it should be a puzzle
            bool isPuzzle = (result == 0);
            if (isPuzzle)
            {
                this->getErrorCode =
                        reinterpret_cast<getErrorCode_t>(library.resolve("getErrorCode"));
                if (nullptr == getErrorCode)
                    this->isLoaded = false;

                this->getPuzzleInfo =
                        reinterpret_cast<getPuzzleInfo_t>(library.resolve("getPuzzleInfo"));
                if (nullptr == this->getPuzzleInfo)
                    this->isLoaded = false;

                this->run =
                        reinterpret_cast<run_t>(library.resolve("run"));
                if (nullptr == this->run)
                    this->isLoaded = false;

                // Get the information about the puzzle
                if (this->isLoaded)
                {
                    this->puzzleInfo = getPuzzleInfo();

                    this->puzzleTitle =
                            puzzleInfo->number
                            + QString(" - ")
                            + puzzleInfo->name;
                }
            }
            else
            {
                // This is not a valid puzzle
                this->isLoaded = false;

            }
        }
    }

    // Unload the library if there was an error
    if (!(this->isLoaded) &&
            (this->library.isLoaded()))
    {
        this->library.unload();
    }
}

Puzzle::~Puzzle()
{
    delete this->puzzleInfo;
}

