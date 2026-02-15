# gol-cpp

gol-cpp is a modern C++ library for simulating [Conway's game of life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life), a cellular automaton devised by John Horton Conway in 1970.

This project provides a reusable library implementation, an example application, and unit tests using Google Test.

## Installation

Clone the repository with submodules.

```bash
git clone --recurse-submodules https://github.com/adm-unl/gol-cpp.git
cd gol-cpp
```

## Build Instructions

Build the project with CMake and run tests with CTest.
```bash
cmake -S . -B build
cmake --build build

ctest --test-dir build
```



## Usage

```c++
#include "board.h"
#include <chrono>
#include <thread>

using namespace std::chromo_literals;

int main()
{
    int rows{ 50 };
    int cols{ 50 };
    double density{ 0.5 };

    Board b{ rows, cols };
    board.randomise(density);

    while (true)
    {
        board.display();
        board.update();
        std::this_thread::sleep_for(200ms);
    }
    return 0;
}
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
