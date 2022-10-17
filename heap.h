#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
    /**
     * @brief Construct a new Heap object
     *
     * @param m ary-ness of heap tree (default to 2)
     * @param c binary predicate function/functor that takes two items
     *          as an argument and returns a bool if the first argument has
     *          priority over the second.
     */
    Heap(int m=2, PComparator c = PComparator()) : m_(m), c_(c) {}

    /**
    * @brief Destroy the Heap object
    *
    */
    ~Heap() {}

    /**
     * @brief Push an item to the heap
     *
     * @param item item to heap
     */
    void push(const T& item);

    /**
     * @brief Returns the top (priority) item
     *
     * @return T const& top priority item
     * @throw std::underflow_error if the heap is empty
     */
    T const & top() const;

    /**
     * @brief Remove the top priority item
     *
     * @throw std::underflow_error if the heap is empty
     */
    void pop();

    /// returns true if the heap is empty

    /**
     * @brief Returns true if the heap is empty
     *
     */
    bool empty() const;

    /**
   * @brief Returns size of the heap
   *
   */
    size_t size() const;

private:
    /// Add whatever helper functions and data members you need below
    PComparator c_;
    int m_;
    std::vector<T> vec;
    void trickledown(int position);
    void trickleup(int position);

};

// Add implementation of member functions here


template<typename T, typename PComparator>
void Heap<T, PComparator>::trickleup(int position)
{
    if(position == 0)
    {
        return;
    }
    if(!c_(vec[(position-1)/m_], vec[position]))            //If the parent element does not satisfy "comp" criteria, warranting trickling up
    {
        T temp = vec[(position-1)/m_];
        vec[(position-1)/m_] = vec[position];
        vec[position] = temp;
        trickleup((position-1)/m_);                 //Recurse trickle up
    }
    return;
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::trickledown(int position)
{
    if(position * m_+ 1 >= vec.size())            //There is no element in the subtree, nothing to trickle.
    {
        return;
    }
    T temp;
    int temploc = position;
    for(int i = 1; i <= m_ && i <= vec.size() - 1 - (position * m_) /* so i doesn't iterate over vec size cap */ ; i++)
    {
        if(!c_(vec[temploc], vec[position * m_ + i]))       //found new smaller/bigger element
        {
            temploc = position * m_ + i;
        }
    }
    if(temploc != position)                       //Found new element, so trickle
    {
        temp = vec[temploc];
        vec[temploc] = vec[position];
        vec[position] = temp;
        trickledown(temploc);               //Continue trickling down
    }
    return;
}

// We will start top() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
    // Here we use exceptions to handle the case of trying
    // to access the top element of an empty heap
    if(empty()){
        // ================================
        // throw the appropriate exception
        // ================================
        throw std::out_of_range("top() called on empty heap");
    }
    // If we get here we know the heap has at least 1 item
    // Add code to return the top element
    return vec[0];
}


// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
    if(empty()){
        // ================================
        // throw the appropriate exception
        // ================================

        throw std::out_of_range("pop() called on empty heap");
    }
    vec[0] = vec[vec.size()-1];
    vec.pop_back();
    trickledown(0);
    return;
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
    vec.push_back(item);
    trickleup(vec.size()-1);
    return;
}

template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
    return (vec.size() == 0);
}

template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
    return vec.size();
}

#endif

