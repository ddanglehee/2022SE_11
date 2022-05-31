cmake_minimum_required(VERSION 3.21)
project(hw3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw3
        main.cpp
        product.cpp
        product.h
        purchaseProduct.cpp
        purchaseProduct.h
        searchProduct.cpp
        searchProduct.h
        user.cpp
        user.h
        InquireProductsForSale.cpp
        InquireProductsForSale.h
        InquireSalesStatistics.cpp
        InquireSalesStatistics.h
        InquireSoldOutProduct.cpp
        InquireSoldOutProduct.h
        RegisterProduct.cpp
        RegisterProduct.h
        )
