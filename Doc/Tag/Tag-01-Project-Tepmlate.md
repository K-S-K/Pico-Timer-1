# Pico-Timer Initial Project

## The project structure

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
cmake..
```

Execute make:

```bash
make
```

## How does it work

![Blinking Led Pico Image](../Img/PT-001-01-pico-blink.gif)
