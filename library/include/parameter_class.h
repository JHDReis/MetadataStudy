#ifndef METADATASTUDY_PARAMETER_CLASS_H
#define METADATASTUDY_PARAMETER_CLASS_H

#include "iostream"

namespace library
{
//https://monkeywritescode.blogspot.com/2020/02/mixinish-classes-with-parameter-packs_18.html

using namespace std;

struct EnableFeatureA {
    template <typename T> static int apply(T *a) {
        return a->a();
    }
};

struct EnableFeatureB {
    template <typename T> static int apply(T *a) {
        return T::b();
    }
};

template <typename Impl, typename... Config>
struct Foo {
    Foo(){
        // Call apply() for each type in Config
        Impl *p = nullptr;
        int dummy[sizeof...(Config)] = { (Config::apply(p), 0)... };
    }
};

struct Bar;
using FwdFoo = Foo<Bar, EnableFeatureA, EnableFeatureB>;

struct Bar : FwdFoo {
    int a() { return 4; }
    static int b() { return 2; }
};

}

#endif //METADATASTUDY_PARAMETER_CLASS_H
