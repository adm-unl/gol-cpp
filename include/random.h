/* random.h
 *
 * implements a self-seeding Mersenne Twister. Requires C++17 or newer.
 * courtesy of learncpp.com (https://www.learncpp.com/cpp-tutorial/global-random-numbers-random-h/)
 *
 */

#ifndef RANDOM_MT_H
#define RANDOM_MT_H

#include <chrono>
#include <random>

namespace Random
{
	inline std::mt19937 generate()
	{
		std::random_device rd{};

		// create seed_seq with clock and 7 random numbers from std::random_device
		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
				rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ ss };
	}

	inline std::mt19937 mt{ generate() };

	inline int get(int min, int max)
	{
		return std::uniform_int_distribution{min, max}(mt);
	}
}

#endif
