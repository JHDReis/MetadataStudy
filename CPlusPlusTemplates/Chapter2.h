//
// Created by Joao Henriques David Dos Reis on 30/04/2020.
//

#ifndef METADATASTUDY_CHAPTER2_H
#define METADATASTUDY_CHAPTER2_H

template <typename T>
inline T const& max(const T& a, const T&b)
{
    return a < b ? b : a ;
}

//Overloading a function template

template <typename T>
inline T const& max(const T& a, const T& b, const T& c)
{
    return ::max( ::max(a,b), c);
}


#endif //METADATASTUDY_CHAPTER2_H
