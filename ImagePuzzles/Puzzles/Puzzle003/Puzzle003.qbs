import qbs


DynamicLibrary  {
    property var projectName: "Puzzle003";

    // Project settings
    name: projectName

    Depends {
        name: "cpp"
    }

    Depends {
        name: "Common"
    }

    // Properties
    property var destinationDirectoryPath:  qbs.buildVariant + "/Puzzles";

    // Compiler flags and settings
    cpp.cxxFlags: {
        // Clang should be detected first
        if (cpp.compilerName.contains("clang++")) {
            return [ "-std=c++14" ]
        }
        else if (cpp.compilerName.contains("g++")) {
            return [ "-std=c++14" ]
        }
    }

    // Files groups
    Group {
        name: projectName
        prefix: "src/"
        files: [
            "header-" + projectName + ".h",
            "main-" + projectName + ".cpp",
        ]
    }

    // Executables groups
    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
        qbs.installDir: destinationDirectoryPath
    }
}

