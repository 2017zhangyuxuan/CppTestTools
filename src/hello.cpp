//
// Created by Admin on 2022/7/17.
//

#include "hello.h"
#include <iostream>

std::string hello() {
    static int a;
    std::cout << "hello world" << std::endl;
    return "hello world";
}

int GMockTest::func(int a) {
    return a;
}