#include "library.hpp"

#include <numeric>
#include <vector>

int returns_42()
{
    return 42;
}

int returns_37()
{
    return 36;
}

int sum_arithmetic_sequence_recursive(int term_count)
{
    if (term_count <= 0)
        return 0;
    return term_count + sum_arithmetic_sequence_closed_form(term_count - 1);
}

int sum_arithmetic_sequence_closed_form(int term_counts)
{
    return (term_counts + 1) * term_counts / 2;
}

int sum_arithmetic_sequence_loop(int term_count) {
    std::vector<int> terms(term_count);
    std::iota(terms.begin(), terms.end(), 1);
    int sum = 0;
    for (const auto term : terms) {
        sum += term;
    }
    return sum;
}
