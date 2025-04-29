# Pico-Timer

Raspberry PI FreeRTOS Timer

[Here](Doc/readme.md) you can find the instructions on how to prepare the environment and how to build the project.

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
cmake..
```

Execute make:

```bash
make
```
