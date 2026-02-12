/* cell.h
 *
 * implements cell class.
 *
 */

#ifndef CELL_H
#define CELL_H

#include <iostream>

class Cell
{
public:
    Cell() = default;

    explicit Cell(bool live) :
        m_live{ live }
    {
    }

    bool is_alive() const { return m_live; }

    void set_alive() { m_live = true; }

    friend std::ostream& operator<<(std::ostream& out, const Cell& c);

private:
    bool m_live{false};
};

#endif
