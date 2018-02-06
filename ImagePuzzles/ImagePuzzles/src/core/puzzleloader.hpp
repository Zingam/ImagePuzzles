#ifndef PUZZLELOADER_HPP
#define PUZZLELOADER_HPP

#include "../application/constants.hpp"
#include "puzzle.hpp"

#include <QtCore/QDebug>
#include <QtCore/QDir>
#include <QtCore/QLibrary>
#include <QtCore/QList>

#include <iostream>

Puzzle* loadPuzzle(QFileInfo& file)
{
    bool isLibrary = QLibrary::isLibrary(file.filePath());

    if (isLibrary)
    {
        Puzzle* puzzle = new Puzzle(file.filePath());

        if (puzzle->isLoaded)
        {
            qDebug() << "Successully loaded:" << file.fileName();

            return puzzle;
        }
        else
        {
            qDebug() << "Failed to load:    " << file.fileName() << " (not a Puzzle)";
        }
    }

    return nullptr;
}

QList<Puzzle*> loadPuzzles()
{
    QString puzzlesPathName = QDir::currentPath() + res_PuzzlesPathName;
    QDir puzzlesPath(puzzlesPathName);
    QStringList fileNames = puzzlesPath.entryList(QDir::Files, QDir::Name);

    QList<Puzzle*> puzzles;

    for (QString& fileName: fileNames)
    {
        auto file = QFileInfo(puzzlesPathName + "/" + fileName);
        auto puzzle = loadPuzzle(file);
        if (nullptr != puzzle)
        {
            puzzles.push_back(puzzle);
        }
//        bool isLibrary = QLibrary::isLibrary(libraryPathName);

//        if (isLibrary)
//        {
//            Puzzle* puzzle = new Puzzle(libraryPathName);

//            if (puzzle->isLoaded)
//            {
//                qDebug() << "Successully loaded:" << fileName;

//                puzzles.push_back(puzzle);
//            }
//            else
//            {
//                qDebug() << "Failed to load:    " << fileName << "(not a Puzzle)";
//            }
//        }
    }

    return puzzles;
}

#endif // PUZZLELOADER_HPP
