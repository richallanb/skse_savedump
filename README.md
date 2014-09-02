skse_savedump
=============

Simple C++ program that will scan SKSE save files from Skyrim and dump your current list of enabled mods.

Very useful if you have a long list of mods and somehow corrupt the order.


To compile:

g++ -o skse_dump skse_dump.cpp

To run:

skse_dump SKSE_SaveFile.save dump.txt
