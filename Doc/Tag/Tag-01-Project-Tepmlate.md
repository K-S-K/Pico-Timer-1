# Pico-Timer Initial Project

Like any embedded project, this project begins from the project directory structure and the blinking LED.

Later on, the project, which is buildable and testable, must grow into something real.

**Note:** The components and infrastructure necessary for the project are described in the [article, dedicated to this subject](https://github.com/K-S-K/Pico-Timer/blob/main/Doc/Tag-00-Preparations.md). The developer computer must comply with these preparations.

## The project structure

Let's take a brief look at the repository's structure.
Some of its elements are critically necessary for the project, while others are developer culture-related and can vary individually or due to the company's style guide.

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

The directory for the developer tool configuration and all its content is **developer tool-related**. This means that if you use a different IDE or don't use an IDE, then this directory isn't needed or can be replaced with something specific to the developer. For instance, it can be **_.idea_**, if the developer uses JetBrains IDE.

The project was developed using the IDE Visual Studio Code. So, it created a directory named **_.vscode_**, which is the directory in which the IDE expects these configuration files.

VSCode must be configured to stop complaining about include instructions when it calls a compiler for IntelliSense functionality. So we need to create several IDE configuration files in .vscode directory in the root of our repository.

The **_c_cpp_properties.json_** file contains C++ extension configuration for Visual Studio Code. Some of the parameters of this file are:

- the list of include directories for the IDE to let it know where they are and not complain;
- Global defines are to be used during compiling;
- Path to the compiler;
- The language standard version.

The official description of this file format is written in the article: [C++ extension settings reference (https://code.visualstudio.com/docs/cpp/customize-cpp-settings)](https://code.visualstudio.com/docs/cpp/customize-cpp-settings).

The **_settings.json_** file describes workspace-related VSCode behavior. Important parameters for us at this stage are:

- _"C_Cpp.intelliSenseEngine": "default"_ - turns on the IntelliSenseEngine;
- _"C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools"_ - it delegates the configuration procedure to the CMake extension, which prepares, including but not limited to, the compile_commands.json file, which is necessary for the  proper work of the code navigation and intellisense;
- _"C_Cpp.default.compileCommands"_ points the location of the compile_commands.json file mentioned above;
- _"files.associations"_ parameter explains to VSCode how to interpret files in the project based on the file extension. The list of file associations is described in the dedicated VSCode [article about Language Identifiers](https://code.visualstudio.com/docs/languages/identifiers).

### Documentation

Having the documentation in the project is **not obligatory**. However, it is beneficial to have some description for colleagues or for the developer himself to understand what and why they did when they return to the project after some time.

### Source files

This workspace directory gathers all source files, and separates them from other workspace stuff. Not obligatory but good structuring practice when it is institutionalized.

### Git related files

If the project is under the Git based source control it leads to having some corresponding files in the repository:

- **_.gitignore_** is a necessary configuration file for separating what to put under control from what not to.
- **_LICENSE_** is traditionally present in the root of the git repositories. Usually never been read, even by the authors' code owners.
- **_README.md_** - Part of the documentation, the root documentation of the repository.

## How to build the target project

### Build the project by executing the following commands

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

### Copy the binary to the Pico

Primarily, locate the build result file at the Src/build directory. In this particular case, it should be called **_pico-timer.uf2_**.

After that, plug the Pico, holding its "BOOTSEL" button, into the developer's machine's USB port. The new attached drive will appear in the system.

Then, copy the located file directly to the drive. Once the copying procedure is complete, the drive will disconnect from the system automatically, and Pico will execute the just copied binary code.

## How does it work

![Blinking Led Pico Image](../Img/PT-001-01-pico-blink.gif)
