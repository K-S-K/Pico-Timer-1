# Pico-Timer

## How to prepare the environment and prerequisites

### Prepare the Raspberry PI Pico SDK and FreeRTOS image

Somewhere in the common directory (in my case, it is HOME/SDK), prepare a clone of the next two repositories:

- [Pico-SDK](https://github.com/raspberrypi/pico-sdk)

- [FreeRTOS](https://github.com/FreeRTOS/FreeRTOS-Kernel)

### Prepare the environment variables for reference to these repositories

To have these variables in the environment, add the following lines to the bashrc file:

```bash
nano .zshrc
```

In the bashrc file, add the following lines:

```text
export PICO_SDK_PATH="$HOME/SDK/pico-sdk"
export FREERTOS_KERNEL_ORIG_PATH="$HOME/SDK/FreeRTOS-Kernel-Original"
```

Now,  you can check the environment variables:

```bash
echo $PICO_SDK_PATH
echo $FREERTOS_KERNEL_ORIG_PATH
```

Having these variables in your system, you can reference them in the CMakeLists.txt files of all your projects.

### Install PicoTools to communicate with the target device

Now, we can go to the prerequisites directory and clone the repository.

[Picotool](https://github.com/raspberrypi/picotool)

```bash
cd ~
git clone https://github.com/raspberrypi/picotool.git
cd picotool
mkdir build
cd build
cmake ..
make
sudo make install
```

To test Picotool, type the following command:

```bash
picotool --help
```

## How to build the target project

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
cmake ..
```

Execute make:

```bash
make
```
