//
// Created by Joao Henriques David Dos Reis on 01/05/2020.
//

#ifndef METADATASTUDY_CHAPTER3_H
#define METADATASTUDY_CHAPTER3_H

#include <vector>
#include <mutex>
#include <deque>


namespace chapter3
{
    template <typename T>
    class Stack {
    public:
        Stack()= default;
        Stack(const Stack<T>& stack) : _elems(stack._elems) {} //copy constructor
        Stack<T>& operator= (const Stack<T>& stack); //copy assigment

        void push(const T& elem);
        void pop();
        T top() const;
        bool empty() const;

    private:
        std::__1::vector<T> _elems;
        std::mutex _lock;
    };

    template<>
    class Stack<std::string> {
    public:
        void push(const std::string& elem);
        void pop();
        std::string top() const;
        bool empty() const;

    private:
        std::__1::deque<std::string> _elems;
    };
}

template<typename T>
void chapter3::Stack<T>::push(const T &elem) {
    std::lock_guard<std::mutex> lockGuard(_lock);
    _elems.push_back(elem);
}

template<typename T>
void chapter3::Stack<T>::pop() {
    std::lock_guard<std::mutex> lockGuard(_lock);

    if(_elems.empty())
        throw std::out_of_range("Stack<>::pop(): empty stack");
    _elems.pop_back();
}

template<typename T>
T chapter3::Stack<T>::top() const {

    if(_elems.empty())
        throw std::out_of_range("Stack<>::top(): empty stack");
    return _elems.back();
}

template<typename T>
bool chapter3::Stack<T>::empty() const {
    return _elems.empty();
}

template<typename T>
chapter3::Stack<T>& chapter3::Stack<T>::operator=(const chapter3::Stack<T> &stack) {
    return *this;
}


/// ------- Specialization -------

void chapter3::Stack<std::string>::push(const std::string &elem) {
    _elems.push_back(elem);
}

void chapter3::Stack<std::string>::pop() {
    if(_elems.empty())
        throw std::out_of_range("Stack<std::string>::pop(): empty stack");
    _elems.pop_back();
}

std::string chapter3::Stack<std::string>::top() const {
    if(_elems.empty())
        throw std::out_of_range("Stack<std::string>::top(): empty stack");
    return _elems.back();
}

bool chapter3::Stack<std::string>::empty() const {
    return _elems.empty();
}


/// ------- Partial Specialization -------

template <typename T1, typename T2>
class MyClass {
public:
    T1 sum(const T1& t1, const T2& t2) {
        return t1 + t2 ;
    }
};

template<typename T>
class MyClass<T, float> {
public:
    float sum(const T& t1, float t2) {
        return (float)(t1 + t2 + 1.1);
    }
};


/// ------- Default Template Arguments -------


template <typename T, typename CONT = std::vector<T> >
class Stack2 {
public:
    void push(const T& elem);
    void pop();
    T top() const;
    bool empty() const;

private:
    CONT _elems;
    std::mutex _lock;
};

template<typename T, typename CONT>
void Stack2<T, CONT>::push(const T &elem) {
    if(_elems.empty())
        throw std::out_of_range("Stack<std::string>::top(): empty stack");
    return _elems.back();
}

template<typename T, typename CONT>
void Stack2<T, CONT>::pop() {
    if(_elems.empty())
        throw std::out_of_range("Stack<std::string>::pop(): empty stack");
    _elems.pop_back();
}

template<typename T, typename CONT>
T Stack2<T, CONT>::top() const {
    if(_elems.empty())
        throw std::out_of_range("Stack<std::string>::top(): empty stack");
    return _elems.back();
}

template<typename T, typename CONT>
bool Stack2<T, CONT>::empty() const {
    return _elems.empty();
}

#endif //METADATASTUDY_CHAPTER3_H
