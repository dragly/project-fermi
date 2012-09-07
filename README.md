Project Fermi
============

Project Fermi is the code name for the great up-and-coming comp.phys. game.

Building
============

1. Download and install the Qt SDK - https://qt-project.org/downloads
1. Download the Box2D library, version 2.2.1 - http://code.google.com/p/box2d/downloads/list
1. Make sure you have some OpenGL development library installed, i.e. on Ubuntu run

    sudo apt-get install libgl1-mesa-dev

1. Create a project folder for this project.
1. Clone this project into < your folder > so you end up with

      < your folder >/project-fermi

   by using the command

      git clone git@github.com:dragly/project-fermi.git

1. Unpack the downloaded Box2D library zip into a subfolder named libs, so that it has the path

      < your folder >/project-fermi/libs/Box2D_v2.2.1/

1. Build Box2D in this directory by downloading premake4.4 and run

       ./premake4 gmake
       cd Build/gmake
       make Box2D

1. Open the < your folder >/project-fermi/src/project-fermi.pro file in Qt Creator and build the project

   or

1. Move to the unpacked folder and run the following in terminal

    qmake
    make

License
============

The project source code is licensed under the GNU GPLv3 license or later.
