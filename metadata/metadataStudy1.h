//
// Created by Joao Henriques David Dos Reis on 01/04/2018.
//

#ifndef METADATASTUDY_METADATASTUDY1_H
#define METADATASTUDY_METADATASTUDY1_H

/*
 * https://www.codeproject.com/Articles/3743/A-gentle-introduction-to-Template-Metaprogramming
 * https://monoinfinito.wordpress.com/series/introduction-to-c-template-metaprogramming/
 * */


template< unsigned char byte > class BITS_SET
{
public:
    enum {
        B0 = (byte & 0x01) ? 1:0,
        B1 = (byte & 0x02) ? 1:0,
        B2 = (byte & 0x04) ? 1:0,
        B3 = (byte & 0x08) ? 1:0,
        B4 = (byte & 0x10) ? 1:0,
        B5 = (byte & 0x20) ? 1:0,
        B6 = (byte & 0x40) ? 1:0,
        B7 = (byte & 0x80) ? 1:0
    };
public:
    enum{RESULT = B0+B1+B2+B3+B4+B5+B6+B7};
};

// ---------------------------------
// Factorials
// ---------------------------------
template< int i >
class FACTOR{
public:
    enum {
        RESULT = i * FACTOR<i-1>::RESULT
    };
};

//Specialization and end:
template<>
class FACTOR< 1 >{
public:
    enum {RESULT = 1};
};

// ---------------------------------
//   Fibonacci
// ---------------------------------
template<unsigned long i>
class FIBONACCI {
public:
    enum { RESULT = FIBONACCI<i-1>::RESULT + FIBONACCI<i-2>::RESULT};
};

template<>
class FIBONACCI<0> {
public:
    enum { RESULT = 0};
};

template<>
class FIBONACCI<1> {
public:
    enum { RESULT = 1};
};



#endif //METADATASTUDY_METADATASTUDY1_H
