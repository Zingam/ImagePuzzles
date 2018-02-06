#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include <QtCore/QLibrary>
#include <QtCore/QString>

#include "common/puzzlefunctions.hpp"
#include "common/puzzleinfo.hpp"

/* ****************************************************************************
 * CLASS DEFINITION
 * ***************************************************************************/
class Puzzle
{
public:
    explicit Puzzle(QString path);
    ~Puzzle();

    GetErrorCode(*getErrorCode);
    Run(*run);

public:
    bool isLoaded;

    PuzzleInfo* puzzleInfo;
    QString puzzleTitle;
    QString fullPathName;

private:
    GetPuzzleGUID(*getPuzzleGUID);
    GetPuzzleInfo(*getPuzzleInfo);

    QLibrary library;
    PuzzleGUID GUID;
};

#endif // PUZZLE_HPP
