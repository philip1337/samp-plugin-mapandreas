# Yet Another SA:MP Plugin Boilerplate

## Introduction

I recently started a new plugin and I thought I'd write a bit about the project
layout while it's bare as I've put some effort into ensuring it's a good
boilerplate to start from. The project includes a quick and simple way to test
plugins as well as a CMake setup and Y_Less' plugin-natives usage.

It's in no way an exhaustive "tutorial" per se but it should be a good place to
get started. I noticed the tutorial by Kyosaur (which is a fantastic tutorial
still) was showing a bit of age - that being said, you should still read it!

## Prerequisites

### Required

#### Visual Studio

I tested with 2017 but 2015 should work too.

#### CMake 3+

This is used for generating the project files. If you're using VS 2017, you can
also directly open the CMakeLists.txt file from `File > Open > CMake...`.

#### Basic Command-Line Knowledge

I use Git-Bash for Windows but PowerShell or Cmd will work just as well.

### Optional

#### Docker

this means you can compile the plugin for Linux while using a Windows machine (I
assume most users here are on Windows). You could use a VM for this but Docker
makes the process much simpler and automated via a couple of simple commands.

#### make

just because I put all the commands into a basic makefile for easier execution.
You don't need make as you can just open up the makefile and run the commands
listed there manually.

#### sampctl

This makes testing the plugin on a SA:MP server a lot easier because the copying
of the .dll and setup of the server is all automated. All you need to do is edit
the `.inc` and write some test code into `test.pwn` and run `make test-windows`
each time you edit the plugin!

## First Run Tasks

When you first clone the repo, you need to do some housework before you can
begin writing plugin code.

### Replacements

Because this is a template, there are certain parts that use a placeholder as a
project name. Do a find-and-replace (CTRL+Shift+F in most editors) across all
files for the following:

* `mapandreas`: your project name, should be lowercase and alphabetic only - is
  used in CMake project name, pawn.json repo name and in test files
* `mapandreas`: your project name but all uppercase - is used in preprocessor
  macros for include guards

Also rename `PAWN_INCLUDE.inc` to your project's preferred include name and edit
`test/gamemodes/test.pwn` for the new include filename.

### Prepare Pawn Tests

If you plan to use the server tests, you should pull the required Pawn deps for
both the package itself and the server instance that's nested in `test/`:

```powershell
make test-setup
```

This runs `sampctl server ensure` inside `test/` and `sampctl package ensure` in
the project root.

### Create a CMake Build Directory

If you plan to use the CMake command line, run:

```powershell
mkdir build
cd build
cmake ..
```

And that will generate a Visual Studio project inside `build/` ready for you to
open in Visual Studio.

Alternatively, you can simply open Visual Studio and click
`File > Open > CMake...` and just open the `CMakeLists.txt` file directly for a
slightly different development experience.

## Explanation of Every Important File

### `makefile`

The makefile is the starting point, but it's not related to the C++ code at all,
it's simply a task list for managing tests.

Run `make test-setup` before doing anything to get everything set up. You should
only need to do this once. This runs `sampctl server ensure` inside `test/`
which uses the declarative `samp.json` file to automatically set up a SA:MP
server instance inside of the `test` directory. Don't worry, the `.gitignore` is
already set up to ignore the server related files. It then runs
`sampctl package ensure` to download the necessary dependencies for building the
Pawn test script - this is just the SA:MP standard library and YSI for
y_testing.

Run `make test-windows` to:

* Copy the .dll file from `test/plugins/Debug` to `test/plugins` - an awkward
  side-effect of Visual Studio
* build the Pawn test script to an .amx with y_testing
* run the test script as a full SA:MP server instance

You should see `Function called` among the typical SA:MP boilerplate text and
y_testing output.

### `src`

This contains the C++ source code. Read the file head comments in order:

* `restful.cpp`
* `common.hpp`
* `natives.hpp`
* `natives.cpp`
* `impl.hpp`
* `impl.cpp`

`CMakeLists.txt` declares which files are relevant to the build process. I'm not
a CMake expert so I'll avoid going any further with this.

`plugin-natives` is a set of useful macros by Y_Less that make declaring plugin
native functions **way** easier than the old way. See the plugin-natives repo
for more info.

### `lib`

This contains external dependencies. These are libraries required by this
project, this includes `cmake-modules` by Zeex which provides some useful CMake
stuff for working with SA:MP plugins and `samp-plugin-sdk` which is the software
development kit for working with SA:MP itself. These are all declared as Git
submodules (`.gitmodules`) and are updatable with `git submodule update`.

#### How do I Add New Dependencies?

Because this project uses CMake, if you want to use a dependency that is also
using CMake you can simply `git submodule add <url> lib/<name>` then add it to
the top-level `CMakeLists.txt`. It's not always that straightforward though
annoyingly but that's just the way of the C++ world...

### `Dockerfile`

If you're new to docker, this file declares an "Image" which is an isolated
filesystem running a particular operating system - in our case it derives from
`maddinat0r/debian-samp` which is a Debian image built specifically for
compiling SA:MP plugins by maddinat0r. This means you can compile an .so on
Windows very easily by running `make build-linux`

## Conclusion

I hope someone found this useful for their next plugin, if there are any actual
problems in the boilerplate code/setup I shall create a new repo and cherry-pick
the commit over so it can be modified for future users.
