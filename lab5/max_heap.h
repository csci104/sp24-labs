#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class MaxHeap {
private:
    std::vector<T> data;
public:
    void push(const T& item);
    // Removes the largest element in the heap
    void pop();
    // Returns the largest element in the heap (but does not remove it)
    T const& top() const;
    std::size_t size() const;
};

template <typename T>
void MaxHeap<T>::push(const T& item) {
    data.push_back(item);
    std::size_t index = data.size() - 1;
    while (index != 0) {
        std::size_t parent_index = (index - 1) / 2;
        T& current = data[index];
        T& parent = data[parent_index];
        if (current <= parent) {
            break;
        }
        std::swap(current, parent);
        index = parent_index;
    }
}

template <typename T>
void MaxHeap<T>::pop() {
    if (data.empty()) {
        throw std::out_of_range("heap is empty");
    }

    //swap the best with last leaf node
    std::swap(data[0], data[data.size() - 1]);

    //delete last leaf node which stores "best" item rn
    data.pop_back();

    //keep trickling down the top item until it's in right location
    std::size_t index = 0;

    while (true) {
        std::size_t c1 = 2*index + 1; //left child
        std::size_t c2 = 2*index + 2; //right child
        std::size_t largest = index; 

        //check if left child exist + greater than current
        if ((c1 < data.size()) && data[c1] > data[largest]) {
            largest = c1;
        }

        //check if right child exist + greater than current
        if ((c2 < data.size()) && (data[c2] > data[largest])) {
            largest = c2;
        }

        //largest isnt the current item, swap
        if (largest != index) {
            std::swap(data[index], data[largest]);
            index = largest;
        }
        else {
            break;
        }
        
    }
}

template <typename T>
T const& MaxHeap<T>::top() const {
    if (data.empty()) {
        throw std::out_of_range("heap is empty");
    }
    return data[0];
}

template <typename T>
std::size_t MaxHeap<T>::size() const {
    return data.size();
}
