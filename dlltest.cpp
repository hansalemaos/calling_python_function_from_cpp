#include <iostream>
#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif
// zig c++ -shared -std=c++2a -O3 -g0 dlltest.cpp -o mytest.dll
extern "C" DLL_EXPORT void add_vecs_int(size_t endereco1,
size_t tamanho1, size_t endereco2, size_t tamanho2, int (*py_function)(int64_t)) {
    if (tamanho1 != tamanho2) {
        throw std::runtime_error("Arrays don't have the same size! Pay more attention, douchebag!");
        }
    int64_t* array1{ (int64_t*)endereco1 };
    int64_t* array2{ (int64_t*)endereco2 };
    for (size_t i{}; i < tamanho1; ++i) {
        if (array1[i] + array2[i] > 20) {
            py_function(array1[i] + array2[i]);
            }
        }
    }