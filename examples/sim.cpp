/* main.cpp
 *
 * implements main logic loop.
 *
 * command line arguments: density=0.5, n_rows=50, n_cols=50
 */

#include "board.h"

#include <iostream>
#include <chrono>
#include <thread>

int main(int argc, char* argv[])
{
    double density{ 0.5 };
    int x{ 50 };
    int y{ 50 };

    if (argc >= 4)
    {
        density = std::stod(argv[1]);
        x = std::stoi(argv[2]);
        y = std::stoi(argv[3]);
    }

    using namespace std::chrono_literals;
    Board board{x, y};
    board.randomise(density);

    while (true)
    {
        std::cout << board;
        board.update();
        std::this_thread::sleep_for(100ms);
    }

    return 0;
}
