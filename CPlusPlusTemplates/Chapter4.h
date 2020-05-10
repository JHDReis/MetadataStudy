//
// Created by Joao Henriques David Dos Reis on 07/05/2020.
//

#ifndef METADATASTUDY_CHAPTER4_H
#define METADATASTUDY_CHAPTER4_H

/* Non Type Template Parameters
 * */

namespace chapter4
{
/**
 * Stack with a fixed size of elements
 * @tparam T
 * @tparam MAXSIZE
 */
template<typename T, int MAXSIZE>
class Stack
{
private:
    T _elements[MAXSIZE];
    int _numElements;
public:
    Stack();

    void push( const T& elem );

    void pop();

    T top() const;

    bool empty() const
    {
        return _numElements == 0;
    }

    bool full() const
    {
        return _numElements == MAXSIZE;
    }
};

template<typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::push( const T& elem )
{
    if ( full() )
        throw std::out_of_range( "Stack<>::push(): stack is full" );
    _elements[_numElements] = elem;
    ++_numElements;
}

template<typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::pop()
{
    if ( _numElements <= 0 )
        throw std::out_of_range( "Stack<>::push(): stack is empty" );
    --_numElements;
}

template<typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::top() const
{
    if ( _numElements <= 0 )
        throw std::out_of_range( "Stack<>::top(): stack is empty" );
    return _elements[_numElements - 1];
}

template<typename T, int MAXSIZE>
Stack<T, MAXSIZE>::Stack(): _numElements(0)
{

}

/// Non Type Function Templates
template <typename T, int val>
T AddValue ( const T& x) {
    return x + val;
}

}

#endif //METADATASTUDY_CHAPTER4_H
