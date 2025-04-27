# Pico-Timer

## How to prepare thhe environment and prerequisites

### Prepere the Raspberry PI Pico SDK and FreeRTOS image

Somewhere in the common directory (in my case it is HOME/SDK) prepare clone the next two repositories:

- [Pico-SDK](https://github.com/raspberrypi/pico-sdk)

- [FreeRTOS](https://github.com/FreeRTOS/FreeRTOS-Kernel)

### Prepare the environment variables for reference to these repositories

To have these variables in the environment, add the following lines to the.bashrc file:

```bash
nano .zshrc
```

In the.bashrc file, add the following lines:

```text
export PICO_SDK_PATH="$HOME/SDK/pico-sdk"
export FREERTOS_KERNEL_PATH="$HOME/SDK/FreeRTOS-Kernel"
```

Now,  you can check the environment variables:

```bash
echo $PICO_SDK_PATH
echo $FREERTOS_KERNEL_PATH
```

Have these variables in your system you can reference to them in the CMakeLists.txt files of all your projects.

## How to build

### To build the project, run the following commands

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
