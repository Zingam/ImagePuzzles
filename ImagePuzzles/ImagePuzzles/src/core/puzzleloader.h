#ifndef PUZZLELOADER_H
#define PUZZLELOADER_H

#include <QtCore/QDir>
#include <QtCore/QLibrary>
#include <QtCore/QList>

#include "../application/constants.h"
#include "puzzle.h"

Puzzle* loadPuzzle(QString fullPathName)
{
    bool isLibrary = QLibrary::isLibrary(fullPathName);

    if (isLibrary)
    {
        Puzzle* puzzle = new Puzzle(fullPathName);

        if (puzzle->isLoaded)
        {
            qDebug() << "Successully re-loaded:" << fullPathName;
            std::cout << "Problem!!!" << std::endl;
            return puzzle;
        }
        else
        {
            qDebug() << "Failed to re-load:    " << fullPathName << "(not a Puzzle)";
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
        QString libraryPathName = puzzlesPathName + "/" + fileName;
        bool isLibrary = QLibrary::isLibrary(libraryPathName);

        if (isLibrary)
        {
            Puzzle* puzzle = new Puzzle(libraryPathName);

            if (puzzle->isLoaded)
            {
                qDebug() << "Successully loaded:" << fileName;

                puzzles.push_back(puzzle);
            }
            else
            {
                qDebug() << "Failed to load:    " << fileName << "(not a Puzzle)";
            }
        }
    }

    return puzzles;
}

#endif // PUZZLELOADER_H

