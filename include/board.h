/* board.h
 *
 * implements board class.
 *
 */

#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include "random.h"

#include <iostream>

constexpr int num_clear_console_lines{ 100 };

class Board
{
public:
    Board(int rows, int cols) :
        m_rows{ rows },
        m_cols{ cols }
    {
        m_array = new Cell[m_rows * m_cols]{};
    }

    ~Board()
    {
        delete[] m_array;
    }

    Cell& at(int r, int c) { return m_array[r * m_cols + c]; }
    const Cell& at(int r, int c) const { return m_array[r * m_cols + c]; }

    void update();

    void randomise(double density);

    friend std::ostream& operator<<(std::ostream& out, const Board& b);

private:
    int m_rows{};
    int m_cols{};
    int m_generation{};
    int m_living_cells{};
    Cell* m_array{};

    bool alive_next_gen(int row, int col) const;
};

#endif
