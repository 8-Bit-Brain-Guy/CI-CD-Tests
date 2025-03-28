## This GIT Repository is used for testing the following:

    - CI/CD workflow using Actions
    - Unit Testing


## Automatic builds:
```
- Goto Actions and run:
    - CMake Build Linux for a Linux Build
    - CMake Build Linux for a Windows Build
    - CMake Multi-Platform C Build for a Linux and Windows Build
        - Sucessful builds are downloadable in "Build Artefakte hochladen (...)" -> "Artifact download URL: ..."
    - Unit Tests for running Unit Tests

```


## Manual builds:
```
- change into direcory "CI-CD-Tests"
- Linux:
    gcc -o build/program-linux src/main.c
- Windows (mingw64 is in path):
    gcc -o build/program-windows src/main.c
```


## Unit tests:
```
- change into directory "CI-CD-Tests/src"
- Linux:
    gcc -o test_math_funcs test_math_funcs.c math_funcs.c -lcriterion
    ./test_math_funcs --verbose
```
