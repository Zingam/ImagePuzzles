import qbs 1.0


StaticLibrary {
    name: "Common"
    
    files: [
        "src/common/library.h",
        "src/common/puzzleinfo.h",
    ]

    Export {
        Depends {
            name: "cpp"
        }
        cpp.includePaths: "src/."
    }
}

