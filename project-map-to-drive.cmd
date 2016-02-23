echo off
echo Map "ImagePuzzles" to W:\
:: Map current folder to drive letter
subst w: "%CD%"
:: Set name for the drive letter
label w: "ImagePuzzles"