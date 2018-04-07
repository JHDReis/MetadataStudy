//
// Created by Joao Henriques David Dos Reis on 02/04/2018.
//

#ifndef METADATASTUDY_METADATASTUDY2_H
#define METADATASTUDY_METADATASTUDY2_H

#endif //METADATASTUDY_METADATASTUDY2_H

//-------------------------------------
//There’s a way to trick the compiler into creating a type from a integral value

template <int N> struct Int {
    static const int value = N;
};



//--------- A LIST -------------------
/*
// A list is a tuple T of two values
List: [ ..., ... ]

// in which the first element, called head, is the first element of the list
List: [ Head, ... ]

// and the second element, called tail,
List: [ Head, Tail]

 // is either a list or the NULL element
List: [ Head, Tail]
Tail: List | Nil
 */

//


//We need here a NIL type to use as a list ending element
struct NIL{
    typedef NIL Head;
    typedef NIL Tail;
};

template <typename H, typename T = NIL>
struct Lst{
    typedef H Head;
    typedef T Tail;
};


template <typename LST> struct Length {
    typedef typename LST::Tail Tail;
    static const unsigned int tail_length = Length< Tail >::result;
    static const unsigned int result = 1 + tail_length;
};

template <> struct Length<NIL> {
    static const unsigned int result = 0;
};

//The Nth element
//Nth(0, lst) <- lst.head
//Nth(n, lst) <- Nth(n-1, lst.tail)

template <typename LST, int N> struct Nth {
    typedef typename LST::Tail Tail;
    typedef typename Nth<Tail, N-1>::result result;
};

template <typename LST> struct Nth<LST,0>{
    typedef typename LST::Head result;
};