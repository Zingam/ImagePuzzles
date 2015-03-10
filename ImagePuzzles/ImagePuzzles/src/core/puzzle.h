#ifndef PUZZLE_H
#define PUZZLE_H

#include <QtCore/QLibrary>
#include <QtCore/QString>

#include "common/types.h"


typedef PuzzleInfo* (*getPuzzleInfo_t)();
typedef void (*run_t)(const char*);


class Puzzle
{
public:
    explicit Puzzle(QString path);
    ~Puzzle();

    bool isLoaded;

    PuzzleInfo* puzzleInfo;

    run_t run;

private:
    getPuzzleInfo_t getPuzzleInfo;

    QLibrary library;
};

#endif // PUZZLE_H
