# leetcode_learner
> Leetcode CMake template. For easy building, testing, and debugging with CMake, GTest, and VSCode.

## Requirements
- GCC/Clang and make

Run `sudo apt install build-essential cmake libgtest-dev` to install in Ubuntu> 20.04

## Usage

Run `./create_solution.sh <problem name>` to create a new problem directory in `problems`.

Every CPP file in this directory will be a **solution** to the problem and you can have several solutions for one problem.

Run `cmake .` then `make` in either top directory or problem directory to build either all or one problem.

It will compile a binary in the problem directory with the same name as the solution cpp file.
