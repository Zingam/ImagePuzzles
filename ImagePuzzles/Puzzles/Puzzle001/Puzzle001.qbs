import qbs

DynamicLibrary {
    property string projectName: "Puzzle001";

    // Project settings
    name: projectName

    Depends {
        name: "cpp"
    }

    Depends {
        name: "Common"
    }

    // Properties
    property string destinationDirectoryPath:  qbs.buildVariant + "/Puzzles";

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

    // Files groups
    Group {
        name: projectName
        prefix: "src/"
        files: [
            "main-" + projectName + ".cpp",
            projectName + ".cpp",
            projectName + ".hpp",
            projectName + "-CPlusPlus.cpp",
            projectName + "-OpenCL.cpp",
            projectName + "-OpenGL.cpp",
        ]
    }

    // Executables groups
    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
        qbs.installDir: destinationDirectoryPath
    }
}
