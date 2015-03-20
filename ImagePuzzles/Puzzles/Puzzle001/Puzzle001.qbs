import qbs

DynamicLibrary  {
    property var projectName: "Puzzle001";

    // Project settings
    name: projectName
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
        name: projectName
        prefix: "src/"
        files: [
            "main-" + projectName + ".cpp",
            projectName + ".cpp",
            projectName + ".h",
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

