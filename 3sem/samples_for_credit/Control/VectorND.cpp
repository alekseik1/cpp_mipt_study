//
// Created by aleksei on 09.12.17.
//

#include "VectorND.hpp"

VectorND::VectorND(int n, std::initializer_list<double> coords) {
    _N = n;

    if(coords.size() == 0) {    // С пустым init_list мы заполним нулями
        for(int i = 0; i < n; i++) {
            _X[i] = 0;
        }
        return;
    }

    if(coords.size() != n) {
        throw("Not enough coords to unpack!");
    }
    unsigned i = 0;
    // TODO: Пользователь может скормить не double в init_list. Надо сделать на это проверку
    for(auto& coord : coords) {
        _X[i] = coord;
        i++;
    }
}

VectorND::VectorND(int n): VectorND(n, {})
{}

VectorND::~VectorND() {

}

int VectorND::getDim() const noexcept {
    return _N;
}