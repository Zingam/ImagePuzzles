#ifndef CONSTANTS
#define CONSTANTS

const auto res_fileName_ImageLogo = "assets/icons/icon.png";
const auto res_applicationTitle =   "ImagePuzzles";
const auto res_authorName =         "Roccoor Multimedia&trade;";

const auto res_PuzzlesPathName = "/Puzzles";

const auto res_MainWindow_action_Exit_QMessageBox_Text =
        "<style>"
        ".text {"
        "    color:         rgba(140, 20, 60, 255);"
        "    font-style:    italic;"
        "    font-weight:   bold;"
        "}"
        "</style>"
        "Do you really want to exit <span class='text'>%1</span>?";

const auto res_MainWindow_action_Exit_QMessageBox_InformativeText =
        "<style>"
        ".textFooter {"
        "    color:         rgba(20, 20, 140, 255);"
        "    font-size:     8px;"
        "    font-style:    italic;"
        "}"
        "</style>"
        "<span class='textFooter'>"
        "    &copy; 2015 %1 by %2"
        "</span>";

const auto res_MainWindow_action_Run_QMessageBox_InvalidParameters =
        "<style>"
        ".message {"
        "    color:         rgba(200, 20, 20, 255);"
        "    font-weight:   bold;"
        "}"
        ".info {"
        "    color:         rgba(20, 20, 200, 255);"
        "    font-style:    italic;"
        "}"
        "</style>";

const auto res_dialog_About_Text =
        "<style>"
        ".logo {"
        "    margin:        10px;"
        "}"
        ".textTitle {"
        "    color:         rgba(140, 20, 60, 255);"
        "    font-size:     20px;"
        "    font-weight:   bold;"
        "    font-variant:  small-caps;"
        "}"
        ".textLogo {"
        "    margin-left:   50px;"
        "    color:         rgba(20, 20, 140, 255);"
        "    font-size:     10px;"
        "    font-style:    italic;"
        "}"
        ".textAbout {"
        "    margin-top:    25px;"
        "    font-size:     12px;"
        "}"
        ".textFooter {"
        "    color:         rgba(20, 20, 140, 255);"
        "    font-size:     8px;"
        "}"
        "</style>"
        ""
        "<div class='logo'>"
        "    <p class='textTitle'>"
        "        %1"                        // Replace with a real value
        "    </p>"
        "    <p class='textLogo'>"
        "        by %2"                     // Replace with a real value
        "    </p>"
        "    <p class='textAbout'>"
        "        Solutions of image problems in the C/C++ language,"
        "        implemented as Dynamic Link Libraries with the help"
        "        of the <strong>Qt Framework</strong>."
        "    </p>"
        "    <p class='textFooter'><em>&copy; 2015 %2</em></p>"
        "</div>";

#endif // CONSTANTS

