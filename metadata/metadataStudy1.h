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
    enum : unsigned long { RESULT = FIBONACCI<i-1>::RESULT + FIBONACCI<i-2>::RESULT};
};

template<>
class FIBONACCI<0> {
public:
    enum : unsigned long { RESULT = 0};
};

template<>
class FIBONACCI<1> {
public:
    enum : unsigned long { RESULT = 1};
};


//Fractions
template <int N, int D> struct Frak {
    static const long Num = N;
    static const long Den = D;
};

template <int N, typename X> struct ScalarMultiplication {
    //static const long Num = N * X::Num;
    //static const long Den = N * X::Den;
     typedef Frak<N*X::Num, N*X::Den> result;
};

//Simplification
template <int X, int Y> struct MCD {
    static const long result = MCD<Y, X % Y>::result;
};

//partial specialization
template <int X> struct MCD<X, 0> {
    static const long result = X;
};


//simple(fraction) = fraction / mcd(fraction)
template <class F> struct Simpl {
    static const long mcd = MCD<F::Num, F::Den>::result;
    typedef Frak< F::Num / mcd, F::Den / mcd > result;
    //static const long new_num = F::Num / mcd;
    //static const long new_den = F::Den / mcd;
    //typedef Frak<new_num, new_den> New_Frak;
};


template <typename X1, typename Y1> struct SameBase {
    typedef typename ScalarMultiplication< Y1::Den, X1>::result X;
    typedef typename ScalarMultiplication< X1::Den, Y1>::result Y;
};


template <typename X, typename Y> struct Sum {
    typedef SameBase<X, Y> B;
    static const long Num = B::X::Num + B::Y::Num;
    static const long Den = B::Y::Den; // == B::X::Den
    typedef typename Simpl< Frak<Num, Den> >::result result;
};


//Calculating the total result of the factorial e:
// e = S(1/n!) = 1/0! + 1/1! + 1/2! + ...

template <int N> struct E {
    static const long Den = FACTOR<N>::RESULT;
    typedef Frak< 1, Den > term;
    typedef typename E<N-1>::result next_term;
    typedef typename Sum< term, next_term >::result result;
};


template <> struct E<0> {
    typedef Frak<1, 1> result;
};









#endif //METADATASTUDY_METADATASTUDY1_H
