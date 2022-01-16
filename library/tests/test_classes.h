#ifndef METADATASTUDY_TEST_CLASSES_H
#define METADATASTUDY_TEST_CLASSES_H

namespace tests
{
template<typename T>
struct TestA{};

template<>
struct TestA<int> {
    int t;
    static char im() { return 'A';}
};

template<typename B>
struct TestB {
    B t;
    static char im() { return 'B';}
};

}


#endif //METADATASTUDY_TEST_CLASSES_H
