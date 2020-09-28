### font-test

## Purpose
This repository was created to demonstrate a bug on MacOS which is a  
combination of factors between MacOS, JUCE and iZotope plug-ins, wherein
iZoptope RX plug-ins will crash when their GUIs are opened after a plug-in
loading fonts from memory is inserted after it.

## Recipe
- Using MacOSX Catalina (10.15)
- Open a DAW (tested in Logic Pro X (10.5.1) and Cubase (10.5.20))
- Insert any iZotope RX plug-in, from version 7 or 8
- Insert the FontTest plug-in in the next insert slot
- Close and open the RX GUI (sometimes takes two or three times to crash).

## Result
The RX GUI will crash the DAW.

## Ways to resolve the crash
- See `Source/PluginEditor.cpp` for one method to resolve the crash
- Change the OSX Deployment Target in each Xcode (MacOSX) exporter configuration (i.e. Debug and Release) from 10.8 to 10.7:
    This prevents the use of `CTFontManagerRegisterGraphicsFont` in `juce/modules/juce_graphics/native/juce_mac_Fonts.mm:540`. 
