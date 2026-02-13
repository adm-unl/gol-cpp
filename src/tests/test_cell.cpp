/* test_cell.cpp
 *
 * units tests for Cell class.
 *
 */

#include "cell.h"

#include <gtest/gtest.h>

TEST(CellTest, IsDeadInitially)
{
    Cell c{};
    EXPECT_FALSE( c.is_alive() );
}
