/* cell.cpp
 *
 * implements cell Class member functions.
 *
 */

#include "cell.h"

std::ostream& operator<<(std::ostream& out, const Cell& c)
{
    if (c.is_alive())
        out << " # ";
    else
        out << "   ";
    return out;
}
