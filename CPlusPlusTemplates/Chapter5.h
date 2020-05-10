//
// Created by HEJ on 10/05/2020.
//

#ifndef METADATASTUDY_CHAPTER5_H
#define METADATASTUDY_CHAPTER5_H

/// print elements of an STL container
template<typename T>
void printcoll (const T& coll)
{
    typename T::const_iterator pos;

    for(const auto& pos : coll)
    {
        std::cout << pos << ' ';
    }
    std::cout << std::endl;
}

#endif //METADATASTUDY_CHAPTER5_H
