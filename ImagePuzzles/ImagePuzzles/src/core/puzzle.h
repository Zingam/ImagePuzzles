#ifndef PUZZLE_H
#define PUZZLE_H

#include <QtCore/QLibrary>
#include <QtCore/QString>

#include "common/puzzlefunctions.h"
#include "common/puzzleinfo.h"


/* ****************************************************************************
 * CLASS DEFINITION
 * ***************************************************************************/
class Puzzle
{
public:
    explicit Puzzle(QString path);
    ~Puzzle();

    Run(*run);

public:
    bool isLoaded;

    PuzzleInfo* puzzleInfo;
    QString puzzleTitle;

private:
    GetErrorCode(*getErrorCode);
    GetPuzzleGUID(*getPuzzleGUID);
    GetPuzzleInfo(*getPuzzleInfo);

    QLibrary library;
    PuzzleGUID GUID;
};

#endif // PUZZLE_H
