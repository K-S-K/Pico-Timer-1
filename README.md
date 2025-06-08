# Pico-Timer for Raspberry PI Pico 1

Raspberry PI FreeRTOS Timer

[Here](Doc/readme.md) are the instructions on preparing the environment and building the project.

The structure of the initial empty project is described in the [article](Doc/Tag/Tag-01-Project-Tepmlate.md) dedicated to the description of the simplest working project.

It was very helpful to read [this article](https://embeddedcomputing.com/technology/open-source/linux-freertos-related/using-freertos-with-the-raspberry-pi-pico) to start the project. It is the first consistent example I've found.

## To build the project, run the following commands

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
cmake ..
```

Execute make:

```bash
make
```
