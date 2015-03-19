import qbs 1.0


StaticLibrary {
    name: "Common"
    
    files: [
        "src/common/apiexport.h",
        "src/common/cssstyles.h",
        "src/common/puzzlefunctions.h",
        "src/common/puzzleinfo.h",
        "src/common/puzzlepixmap.h",
    ]

    Export {
        Depends {
            name: "cpp"
        }
        cpp.includePaths: "src/."
    }
}

