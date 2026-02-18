/* board.cpp
 *
 * implements Board class member functions.
 *
 */

#include "board.h"

std::ostream& operator<<(std::ostream& out, const Board& b)
{
    out << "\033[2j\033[H"; // clear console and moves cursor to top-left

    for (int i{0}; i < b.m_rows; ++i)
    {
        for (int j{0}; j < b.m_cols; ++j)
        {
            out << b.at(i, j);
        }
        out << '\n';
    }
    out << "Generation: " << b.m_generation
    << "\t Cells alive: " << b.m_living_cells << '\n';
    return out;
}

void Board::update()
{
    Board new_board{ m_rows, m_cols };
    int new_living_cells{};
    for (int i{0}; i < m_rows; ++i)
    {
        for (int j{0}; j < m_cols; ++j)
        {
            if (alive_next_gen(i, j))
            {
                new_board.at(i, j).set_alive();
                ++new_living_cells;
            }
        }
    }
    m_array = new_board.m_array;
    new_board.m_array = nullptr;
    ++m_generation;
    m_living_cells = new_living_cells;
}

bool Board::alive_next_gen(int row, int col) const
{
    int num_neighbours{};
    for (int i{0}; i < 3; ++i)
    {
        for (int j{0}; j < 3; ++j)
        {
            int r_idx{ (m_rows + row + i - 1) % m_rows };
            int c_idx{ (m_cols + col + j - 1) % m_cols };
            if (r_idx == row && c_idx == col)
                continue;
            if (at(r_idx, c_idx).is_alive())
                ++num_neighbours;
        }
    }

    if (at(row, col).is_alive())
        return (num_neighbours < 2 || num_neighbours > 3 ? false : true);
    else
        return (num_neighbours == 3 ? true : false);
}

constexpr int int_max{ std::numeric_limits<int>::max() };

void Board::randomise(double density)
{
    for (int i{0}; i < m_rows; ++i)
    {
        for (int j{0}; j < m_cols; ++j)
        {
            double test{ Random::get(0, int_max) / static_cast<double>(int_max) };
            if (test < density)
            {
                at(i, j).set_alive();
                ++m_living_cells;
            }
        }
    }
}
