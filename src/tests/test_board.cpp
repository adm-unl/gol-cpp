/* test_board.cpp
 *
 * unit tests for board class.
 *
 */

#include "board.h"

#include <gtest/gtest.h>

class BoardTest : public testing::Test
{
protected:
    BoardTest()
    {
        //init glider
        m_b.at(1, 1).set_alive();
        m_b.at(2, 2).set_alive();
        m_b.at(2, 3).set_alive();
        m_b.at(3, 1).set_alive();
        m_b.at(3, 2).set_alive();
    }

    Board m_b{5, 5};
};

TEST_F(BoardTest, UpdateWorks)
{
    m_b.update();
    EXPECT_TRUE( m_b.at(1, 2).is_alive() );
    EXPECT_TRUE( m_b.at(2, 3).is_alive() );
    EXPECT_TRUE( m_b.at(3, 1).is_alive() );
    EXPECT_TRUE( m_b.at(3, 2).is_alive() );
    EXPECT_TRUE( m_b.at(3, 3).is_alive() );
}



