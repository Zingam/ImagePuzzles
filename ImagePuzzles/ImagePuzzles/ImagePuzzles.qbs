import qbs 1.0

CppApplication {
    name: "ImagePuzzles"
    type: "application" // To suppress bundle generation on Mac
    consoleApplication: false

    // Properties
    property string destinationDirectoryPath: qbs.buildVariant;

    // Compiler flags and settings
    cpp.cxxLanguageVersion: {
        if (cpp.compilerName.contains("clang++")) {
            return "c++17";
        }
        else if (cpp.compilerName.contains("g++")) {
            return "c++17";
        }
        return "c++17"
    }

    cpp.cxxFlags: {
        if (qbs.toolchain.contains("msvc"))
        {
            return [
                        // "/MT" needs to be commented out as Qbs uses "/MDd" by default and causes: warning: D9025 : overriding '/MDd' with '/MT'
                        //"/MT",     /* Creates a multithreaded executable file using LIBCMT.lib (statically linked). */
                        //"/nologo", /* Suppresses display of sign-on banner. */
                        "/Gm-",    /* Disables minimal rebuild.*/
                        //"/GR-",    /* Turn off run-time type information (RTTI). */
                        //"/EHa-",   /* Turn off exception-handling model that catches both asynchronous (structured) and synchronous (C++) exceptions. */
                        //"/Od",     /* Turns off all optimizations in the program and speeds compilation. */
                        "/Oi",     /* Generates intrinsic functions. */
                        "/WX",     /* Treat all compiler warnings as errors.  */
                        "/W4",     /* Set warning Level 4 (recommended for all new projects). */
                        //"/wd4201", /* Turn off warning C4201: nonstandard extension used : nameless struct/union */
                        "/FC",     /* Display full path of source code files passed to cl.exe in diagnostic text. */
                        "/Zi",     /* Generates complete debugging information. */
                        "/Fm",     /* Creates a mapfile. */
                    ]
        }
        else if (qbs.toolchain.contains("gcc"))
        {
            return [
                        "-Wall",
                        "-Werror",
                    ]
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
        "src/application/applicationinfo.hpp",
        "src/application/constants.hpp",
        "src/core/parseparameters.hpp",
        "src/core/puzzle.cpp",
        "src/core/puzzle.hpp",
        "src/core/puzzleloader.hpp",
        "src/main.cpp",
    ]

    Group {
        name: "Forms"
        files: [
            "src/forms/mainwindow.cpp",
            "src/forms/mainwindow.hpp",
            "src/forms/mainwindow.ui",
            "src/forms/dialogabout.cpp",
            "src/forms/dialogabout.hpp",
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
        // Assets to install
        name: "Assets"
        files: [
            "assets/icons/*.png",
            "assets/icons/*.jpg",
        ]
        qbs.install: true
        qbs.installDir: destinationDirectoryPath + "/assets/icons"
    }

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
        qbs.installDir: destinationDirectoryPath
    }
}
