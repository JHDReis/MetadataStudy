//
// Created by Joao Henriques David Dos Reis on 09/07/2018.
//

#include <type_traits>  //This header is part of the type support library

#ifndef METADATASTUDY_METADATASTUDY3_H
#define METADATASTUDY_METADATASTUDY3_H

#endif //METADATASTUDY_METADATASTUDY3_H

/* https://www.fluentcpp.com/2017/06/02/write-template-metaprogramming-expressively/
*/

// std::false_type  Helper Classes, compile-time constant of specified type with specified value
// std::true_type



template< typename, typename = void >
struct is_incrementable : std::false_type { };


//td::declval<T&> -> converts any type T to a reference type

template< typename T >
struct is_incrementable< T, std::void_t<decltype( ++std::declval<T&>() )> > : std::true_type { };
