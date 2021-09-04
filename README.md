# Exa Man v1.0

In the year of 50XX, a cyborg known as an Exa Man was created. He has a mission to destroy powerful evil robots.

Programmer: Amir Karajko

## facebook pages

https://www.facebook.com/AmirProgrammer/
https://www.facebook.com/ExaManGame

## How to play

* A - Move Left
* D - Move right
* J - Jump
* K - Shoot
* Escape - Quit (exit) game

# Project Configuration

The project is created in SFML 2.5.1 and the tutorial for setting up SFML projects is also available online at: https://www.sfml-dev.org/tutorials/2.5/

## Setup

Go to project properties and open "VC++ Directories". Include the SFML 2.5.1 "include" directory and add SFML "lib" to library directories.

Linker -> Input -> Additional Dependencies:
* sfml-graphics-d.lib
* sfml-audio-d.lib
* sfml-window-d.lib
* sfml-system-d.lib

## Converting images to C source files

To convert images to C source files you will need **bin2c converter**.

Open CMD and change directory location to bin2c unzipped folder -> Type: bin2c -o MyImage.h Image.png

Download link: https://sourceforge.net/projects/bin2c

Tutorial: https://youtu.be/nMNBpQplgB0

# Credits

Music: https://opengameart.org/users/wyver9
Font: https://www.1001freefonts.com/computer-robot.font

## Copyright © 2018 - 2021
