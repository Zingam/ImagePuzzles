import qbs 1.0


CppApplication {
    name: "ImagePuzzles"
    type: "application" // To suppress bundle generation on Mac
    consoleApplication: false

    property var destinationDirectoryPath: "../../../__build-output";

    cpp.cppFlags: {
        if (cpp.compilerName.contains("clang++")) {
            return "-std=c++14";
        }
        else if (cpp.compilerName.contains("g++")) {
            return "-std=c++14";
        }
    }

    Depends {
        name: "Qt";
        submodules: [ "core", "gui", "widgets" ]
    }

    Depends {
        name: "Common"
    }

    files: [
        "src/common/applicationinfo.h",
        "src/common/constants.h",
        "src/core/puzzle.cpp",
        "src/core/puzzle.h",
        "src/main.cpp",
    ]

    Group {
        name: "Forms"
        files: [
            "src/forms/mainwindow.cpp",
            "src/forms/mainwindow.h",
            "src/forms/mainwindow.ui",
            "src/forms/dialogabout.cpp",
            "src/forms/dialogabout.h",
            "src/forms/dialogabout.ui",
        ]
    }

    Group {
        name: "Resources"
        files: [
            "res/imagepuzzles.qrc",
        ]
    }

    Group {
        name: "Assets"
        // Set to the name of the root of the directory tree e.g "assets
        // that needs to be copied
        files: [
            "assets",
            "src/core/puzzleloader.h",
        ]
        qbs.install: true
        qbs.installDir: destinationDirectoryPath
    }

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
        qbs.installDir: destinationDirectoryPath
    }
}

