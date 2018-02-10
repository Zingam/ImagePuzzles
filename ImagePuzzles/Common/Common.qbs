import qbs 1.0

StaticLibrary {
    name: "Common"

    // Compiler flags and settings
    cpp.cxxLanguageVersion: {
        if (cpp.compilerName.contains("clang++")) {
            return "c++14";
        }
        else if (cpp.compilerName.contains("g++")) {
            return "c++14";
        }
        return "c++17"
    }

    Depends {
        name: "cpp"
    }

    files: [
        "src/common/apiexport.hpp",
        "src/common/cssstyles.hpp",
        "src/common/pixmap.cpp",
        "src/common/pixmap.hpp",
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
