#include "gtest/gtest.h"
#include "stones.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

TEST(StonesTest, Empty) {
	std::vector<int> stones{};
	EXPECT_EQ(0, lastStoneWeight(stones));
}

TEST(StonesTest, SingleElement) {
	std::vector<int> stones{6};
	EXPECT_EQ(6, lastStoneWeight(stones));
}

TEST(StonesTest, TwoElement1) {
	std::vector<int> stones{8, 3};
	EXPECT_EQ(5, lastStoneWeight(stones));
}

TEST(StonesTest, TwoElement2) {
	std::vector<int> stones{4, 9};
	EXPECT_EQ(5, lastStoneWeight(stones));
}

TEST(StonesTest, TwoElement3) {
	std::vector<int> stones{17, 17};
	EXPECT_EQ(0, lastStoneWeight(stones));
}

TEST(StonesTest, Nominal1) {
	std::vector<int> stones{2, 7, 4, 1, 8, 1};
	EXPECT_EQ(1, lastStoneWeight(stones));
}

TEST(StonesTest, Nominal2) {
	std::vector<int> stones{14, 15, 11, 12, 13};
	EXPECT_EQ(9, lastStoneWeight(stones));
}

TEST(StonesTest, Nominal3) {
	std::vector<int> stones{4, 26, 13, 30, 21, 8};
	EXPECT_EQ(0, lastStoneWeight(stones));
}

TEST(StonesTest, Stress) {
	std::vector<int> stones;
	for(int i = 1; i <= 65536; i++) {
		stones.push_back(i);
	}
	EXPECT_EQ(0, lastStoneWeight(stones));
}

