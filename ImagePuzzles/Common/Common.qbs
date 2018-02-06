import qbs 1.0

StaticLibrary {
    name: "Common"

    files: [
        "src/common/apiexport.hpp",
        "src/common/pixmap.cpp",
        "src/common/pixmap.hpp",
        "src/common/cssstyles.hpp",
        "src/common/puzzlefunctions.hpp",
        "src/common/puzzleinfo.hpp",
        "src/common/puzzlepixmap.hpp",
    ]

    Export {
        Depends {
            name: "cpp"
        }
        cpp.includePaths: "src/."
    }
}
