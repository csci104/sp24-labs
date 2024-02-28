#include "gtest/gtest.h"
#include "max_heap.h"

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <random>

template <typename T, typename U>
void check_heap_state(const MaxHeap<T>& heap, size_t size, U&& top) {
    EXPECT_EQ(size, heap.size());
    EXPECT_EQ(top, heap.top());
}

template <typename T>
void heap_should_be_empty(const MaxHeap<T>& heap) {
    EXPECT_TRUE(heap.size() == 0);
}

TEST(HeapTest, Empty) {
    MaxHeap<int> heap;
    heap_should_be_empty(heap);
}

TEST(HeapTest, String) {
    MaxHeap<std::string> heap;
    heap_should_be_empty(heap);
    heap.push("b");
    heap.push("a");
    check_heap_state(heap, 2, "b");
    heap.pop();
    check_heap_state(heap, 1, "a");
    heap.pop();
    heap_should_be_empty(heap);
}

TEST(HeapTest, OneElement) {
    MaxHeap<int> heap;
    heap.push(42);
    check_heap_state(heap, 1, 42);
    heap.pop();
    heap_should_be_empty(heap);
}

TEST(HeapTest, ReversePair) {
    MaxHeap<int> heap;
    heap.push(37);
    heap.push(42);
    check_heap_state(heap, 2, 42);
    heap.pop();
    check_heap_state(heap, 1, 37);
    heap.pop();
    heap_should_be_empty(heap);
}

TEST(HeapTest, FiveElements) {
    MaxHeap<int> heap;
    heap.push(23);
    heap.push(72);
    heap.push(-1);
    check_heap_state(heap, 3, 72);
    heap.pop();
    check_heap_state(heap, 2, 23);
    heap.push(42);
    heap.push(-8);
    check_heap_state(heap, 4, 42);
    heap.pop();
    check_heap_state(heap, 3, 23);
    heap.pop();
    check_heap_state(heap, 2, -1);
    heap.pop();
    check_heap_state(heap, 1, -8);
    heap.pop();
    heap_should_be_empty(heap);
}

TEST(HeapTest, RandomVectorSort) {
    MaxHeap<int> heap;
    std::vector<int> vec(23);
    std::iota(vec.begin(), vec.end(), 0);

    std::mt19937 rng(42);
    std::vector<int> random_vec = vec;
    std::shuffle(random_vec.begin(), random_vec.end(), rng);
    std::vector<int> result;
    for (int x : random_vec) {
        heap.push(x);
    }
    while (heap.size() > 0) {
        result.push_back(heap.top());
        heap.pop();
    }
    std::reverse(result.begin(), result.end());

    EXPECT_EQ(vec, result);
}