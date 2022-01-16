#ifndef METADATASTUDY_HELPERS_H
#define METADATASTUDY_HELPERS_H

#include <any>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <typeindex>
#include <typeinfo>
#include <type_traits>

namespace details {

template<typename T>
struct Buffered { };

template<typename T>
struct IsBuffered : public std::false_type {
    using ValueType = T;
};

template<typename T, template<class> class Buffered>
struct IsBuffered<Buffered<T>> : public std::true_type {
    using ValueType = T;
};

template<class, template<class> class>
struct is_instance : public std::false_type { };

template<class T, template<class> class U>
struct is_instance<U<T>, U> : public std::true_type {
    using ValueType = T;
};

}

#endif //METADATASTUDY_HELPERS_H
