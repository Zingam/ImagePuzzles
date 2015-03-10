import qbs

DynamicLibrary  {
    // Project settings
    name: "Puzzle001"
//    type: "dynamiclibrary" // To suppress bundle generation on Mac

    Depends {
        name: "cpp"
    }

    Depends {
        name: "Common"
    }

    // Properties
    property var destinationDirectoryPath: "../../../__build-output/Puzzles/";

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
        name: "Puzzle001"
        prefix: "src/"
        files: [ "main-Puzzle001.cpp" ]
    }

    // Executables groups
    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
        qbs.installDir: destinationDirectoryPath
    }
}

