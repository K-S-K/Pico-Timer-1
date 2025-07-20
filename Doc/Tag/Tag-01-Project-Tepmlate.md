# Pico-Timer Initial Project

Like any embedded project, this project begins from the project directory structure and the blinking LED.

Later on, the project, which is buildable and testable, must grow into something real.

**Note:** The components and infrastructure necessary for the project are described in the [article, dedicated to this subject](https://github.com/K-S-K/Pico-Timer/blob/main/Doc/Tag-00-Preparations.md). The developer computer must comply with these preparations.

## The project structure

Let's take a brief look onto the structure of the repository.
Some of it's elements are critically necessary bor the project, some of them are developer culture related and can vary individually or due to company style guide.

```text
Project root/
├── .vscode/
│   ├── c_cpp_properties.json
│   ├── compile_commands.json
│   ├── launch.json
│   ├── settings.json
│   ├── tasks.json
├── Doc/
│   ├── ...
├── Src/
│   ├── application/
│   │   ├── FreeRTOSConfig.h
│   │   ├── main.c
│   ├── build/
│   ├── CMakeLists.txt
├── .gitignore
├── LICENSE
├── README.md
```

### IDE Configuration files

The directory for the developer tool configuration and all its content is **developer tool related**. This means that if you use different IDE or don't use IDE than this directory isn't needed or can be replaced with something particular developer specific, for instance, it can be **_.idea_** if developer uses JetBrains IDE.

The project was developed using IDE Visual Studio Code, so this developer named **_.vscode_** - the directory in which the IDE expects these configuration files.

VSCode must be configured to make it not complaining on include instructions when it calls a compiler for the IntelliSense functionality. So we need to create several IDE configuration files in .vscode directory in the root of our repository.

The **_c_cpp_properties.json_** file contains C++ extension configuration for VSCode. Some of the parameters of this file are:

- the list of the include directories for IDE to let it know where they are and not complain;
- Global defines to be used during compiling;
- Path to the compiler;
- The language standard version.

The official description of this file format is written in the article: [C++ extension settings reference (https://code.visualstudio.com/docs/cpp/customize-cpp-settings)](https://code.visualstudio.com/docs/cpp/customize-cpp-settings).

The **_settings.json_** file describes workspace-related VSCode behavior. Important parameters for us at this stage are:

- _"C_Cpp.intelliSenseEngine": "default"_ - turns on the IntelliSenseEngine;
- _"C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools"_ - it delegates the configuration procedure to CMake extension, which prepares, including but not limited by, the compile_commands.json file, which is necessary for the  proper work of the code navigation and intellisense;
- _"C_Cpp.default.compileCommands"_ points the location of the compile_commands.json file mentioned above;
- _"files.associations"_ parameter explains to VSCode how to interpret files in the project based on the file extension. The list of the file associations described in the dedicated VSCode [article about Language Identifiers](https://code.visualstudio.com/docs/languages/identifiers).

### Documentation

To have the documentation in the project is **not obligatory**. But it is good to have some description to che colleagues or for the developer himself to understand what and why he did when he returns to the project after some time.

### Source files

This workspace directory gathers all source files, and separates them from other workspace stuff. Not obligatory but good structuring practice when it is institutionalized.

### Git related files

If the project is under the Git based source control it leads to having some corresponding files in the repository:

- **_.gitignore_** is necessary configuration file for separating what to put under control from what to not.
- **_LICENSE_** traditionally presents in the root of the git repositories. Usually never been reed even by authors code owners.
- **_README.md_** - Part of the documentation, the root documentation of the repository.

## How to build the target project

### Build the project, by executing the following commands

Prepare the build directory (if it is not done yet):

```bash
mkdir Src/build
```

Go to the build directory:

```bash
cd Src/build
```

Execute CMake:

```bash
cmake..
```

Execute make:

```bash
make
```

### Copy binary to the Pico

Primarily, locate the build result file at the Src/build directory. In this particular case, it should be called **_pico-timer.uf2_**.

After that, plug the Pico holding its "BOOTSEL" button to the developer's machine USB. The new attached drive will appear in the system.

Than, copy the located file directly to the drive. Once copying procedure complete, drive will disconnected from the system by itself, and Pico will execute the just copied binary code.

## How does it work

![Blinking Led Pico Image](../Img/PT-001-01-pico-blink.gif)
