# Scratch - A C++ Project Template

"Scratch" is a very simple C++ template I created to have a starting point for my ideas.
It provides a basic yet functioning setup of CMake, CTest, GoogleTest as well as Doxygen.exit

If you find it useful, great! If you have ideas, suggestions or found a bug then please open an
issue or make a pull request.

The way I organized this template is by no way mandatory and I've kept it minimal for that reason.
It should be easy to add, drop or rearange parts to your liking :).

Also I do not claim to follow all best practices. Like said above, I'm open for suggestions.

Cheers, Rafael

## Project Overview

What is included :

* Directory layout of a project consisting of an executable, a static library and a shared library.
    * Rudimentary and nonsensical code serving as placeholder for these targets.
* CMake configuration files for:
    * Building the project.
    * Downloading and building GoogleTest from sources.
    * Usage of CTest.
    * Generating documentation using Doxygen.

### What This Template Does Not Provide

* Installation configuration (e.g. **CMake INSTALL** target is not configured).
* Support for third-party libraries (e.g. no use of **Conan** or **CMake ExternalProject** etc. - 
not even an `extern/` directory :( - how you use third-party libraries is up to you !)
* Continuous integration etc. ...

### What This Template Might Provide in the Future

* Right now I'm looking into Conan.io, who knows ;)

## Building

Please note that atleast **CMake version 3.12** is required to build this project!

Building has been tested on **Visual Studio 2017 (Windows 10 Professional)** and **g++ 7.3.0 (Ubuntu 18.04.1)**.

### Building the Project

Same steps as in every cmake based project ;).

To build the project (executable and libraries) do the following:

1) In the root directory of this project, type these lines to configure the project using cmake.

        mkdir build
        cd build
        cmake ..

    Optionally you can pass more arguments to the call to `cmake` in the last line, like specifiying which generator to use, etc.

2) Now to build the project, type (while still being in directory `scratch/build/`):

        cmake --build .

CMake is configured to place the output binaires in `bin/`.

### Build the documentation

Note that doxygen documentation is not generated by default. If you want it to be built then type:

    cmake --build . --target doc_doxygen

This will generate HTML documentation in directory `scratch/doc/doxygen/html/`. Simply open file `index.html` in this directory with your browser.

#### Running the tests

To run the tests, in directory `build/` type:

    ctest .

## Building the Documentation

Further documentation can be found in the following files in `doc/`:

*   Description of the [project structure (doc/STRUCTURE.md)](doc/STRUCTURE.md) 

## Project Structure

### Directories

An overview of what files should go into which directory.

#### src/

`src/` is the directory where all source files and private header files should go. A target's files
should be grouped into a sub-directory bearing the target's name: `src/<target name>/` (compare
`src/app` for target *app*'s sources).

##### src/lib/

Libraries are an exception in this template as their source and private header
files reside in sub-directory `lib/` of directory `src`:

    src/lib/<target name>/
(e.g. you'll find the files of target **lib_ruben** in `src/lib/lib_ruben/`).

**Note:** Please don't confuse this directory with the directory where your *external*/*third party* libraries go - which most often is a directory at the project's root that is also called `lib/` or `extern/`. 

#### include/

Public header files of an executable or library should go into `include/scratch/<target name>` where
`<target name>` again is the name of the executable or library the files belong to.

**Note:** As you see the `include/` directory has one sub-directory with the same name as the
project. This is deliberate and a convention that should be followed to improve include statements.

#### doc/

This directory contains additional documentation (e.g. Markdown files like here) which are put here
to prevent the root directory of the project from getting too crowded.

Also doxygen generated documentation will go into `doc/doxygen/` (this directory is created when
building the *doc_doxygen* the first time).

#### build/

This directory is manually created by you when you configure CMake the first time.

#### bin/

Automatically generated directory for output binaries.

### Tests

As you probably have noticed: there is no `tests/` directory in the project.
A target's test files (sources and fixtures) reside in a `tests/` sub-directory within the
respective target's directory. E.g. the tests of target **app** are in `src/app/tests/` and the
tests of target **lib_ruben** can be found in `src/lib/lib_ruben/tests`.

### The Project's Targets

A quick glance at the targets defined in this project.

#### Executables

This project contains one executable **app**. Its source files and private header files reside in 
`src/app`. It does not have any public header files so there is no directory `/include/scratch/app`.

#### Libraries

The project contains two libraries: **lib_stanley** a dynamic library & **lib_ruben** a static one.

The respective source & private header files (for *lib_stanley*) are in `src/lib/<library name>`.

### CMake

There is one `CMakeLists.txt` file per target (unit tests for a target count as a separate target)
and one "main" `CMakeLists.txt` file at the project's root directory. The latter is responsible for
including the other `CMakeLists.txt` files.

The CMake files are well documented. Refer to them to see how they are set up to work in this
project.

#### version.hpp Files

Each target has a `version.hpp` file which is prior to running the CMake configuration step only 
present as a `version.hpp.in` file. This way you specify the version in the CMakeLists.txt file and
CMake will write the major, minor and patch number into preprocessor macros in said version files.

### CTest & GoogleTest

**GoogleTest** is used as a testing framework and its sources are downloaded and built automatically
by CMake. **CTest** is setup to discover GoogleTest-tests automatically.

### Doxygen

Note that the `Doxyfile` for configuring Doxygen is provided as a CMake "template" file
(`Doxyfile.in`)and only available after project configuration using CMake.
The "configured" Doxyfile is in `/build`.

#### Namespace Documentation

The most important thing here is that the project's main *namespace* `scratch` is
documented in file `include/scratch/scratch.dox` *outside of the sources*.

The libraries' (sub-) namespaces are documented in their respective `version.hpp` files (note that
these are generated by CMake and before configuration you only have `version.hpp.in` files).

#### Markdown Documentation

Doxygen is configured to include `doc/MAIN.md` as main page.

#### Doxygen Modules

You will notice that a the `version.hpp.in` (and their configured products `version.hpp` of course
as well) make use of the Doxygen command `defgroup`. The groups defined by these commands are then
used in the header files (via commands `ingroup` and `addtogroup`) to group the definitions in
these files together into the group which was declared by the `defgroup` command in the respective
`version.hpp` file. This is necessary to group a targets sources within the documentation generated
by Doxygen not only by the file they are in but also by the target they belong to. 

These groups are called "Modules" by Doxygen and can be inspected via the button "Modules" in the
navigation bar of the autogenerated documentation HTML files.

Pay attention to the "group closing commands" (the comment block with the curly braces) at the
bottom of each file whose contents should appear in a Doxygen Module.

#### Test Files

You also might have noticed that I use the `file` Doxygen command (and the file header) in header
files but also in unit test source (.cpp) files. This is because I want the unit tests to also
show up in the documentation generated by Doxygen.

#### Colliding File Names

If two or more files in a project share the same name (like `exceptions.hpp` does - of course in
different directories) I prefix the file name in the Doxygen `file` command by the directory name 
it lies in. E.g. `file lib_ruben\exceptions.hpp`. This way there are no issues with colliding file
names in Doxygen.

## Keep a Changelog !

If you haven't read [this guide](https://keepachangelog.com/en/1.0.0/) you should do it.
I recommend keeping a changelog also for your small and personal projects. 

Of course this template also has a changelog (a pretty empty one though): [Changelog](CHANGELOG.md)

## Version Numbers Found in This Template

A quick note about the meaningfulness of the version numbers found in this project (hint: there is mostly no meaning):

* The version numbers of the project's componenents are not really reflecting any real revision and 
are purely fictional to illustrate the fact that (stating the obvious here:) a project can of course consist of multiple components with varying versions.
* Only the version found in [CHANGELOG.md](CHANGELOG.md) as well as in CMakeLists.txt at this 
project's root directory really reflect the current version of this template as a whole.