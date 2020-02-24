#ifndef _COMPETITION_IO_HPP_
#define _COMPETITION_IO_HPP_

#include <iostream>
#include <vector>

template<typename T>
inline std::vector<T> cin_vector(const size_t n) {
     std::vector<T> vec;
    vec.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        T element; std::cin >> element;
        vec.push_back(element);
    }
    return vec;
}

template<typename T>
inline std::vector< std::vector<T> > cin_matrix(const size_t m, const size_t n) {
    std::vector< std::vector<T> > matrix;
    matrix.reserve(m);
    for (size_t i = 0; i < m; ++i) {
        std::vector<T> vec = cin_vector<T>(n);
        matrix.push_back(vec);
    }
    return matrix;
}

template<typename T>
inline void cout_vector(const std::vector<T>& vec) {
    for (size_t i = 0; i < vec.size()-1; ++i) {
       std::cout << vec[i] << ' ';
    }
    std::cout << vec[vec.size()-1] << std::endl;
}

template<typename T>
inline void cout_matrix(const std::vector< std::vector<T> >& matrix) {
    for (const std::vector<T>& vec : matrix) {
         cout_vector<T>(vec);
    }
}

#endif // _COMPETITION_IO_HPP_
