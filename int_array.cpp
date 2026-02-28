#include "int_array.h"
#include <algorithm>  

IntArray::IntArray() noexcept
    : n_(0), p_(nullptr)  
{

}

IntArray::IntArray(std::size_t n, int value)
    : n_(n) 
{
    if (n_ == 0) {
        p_ = nullptr; 
    } else {
        p_ = new int[n_];

        for (std::size_t i = 0; i < n_; ++i) {
            p_[i] = value;
        }
    }
}

IntArray::IntArray(const IntArray& other)
    : n_(other.n_)
{
    if (n_ == 0) {
        p_ = nullptr; 
    } else {
        p_ = new int[n_]; 
        
        for (std::size_t i = 0; i < n_; ++i) {
            p_[i] = other.p_[i];
        }
    }
}

IntArray::IntArray(IntArray&& other) noexcept
    : n_(other.n_), p_(other.p_)
{
    other.n_ = 0;
    other.p_ = nullptr;
}

IntArray::~IntArray()
{
    delete[] p_;
}


IntArray& IntArray::operator=(const IntArray& other)
{
    if (this != &other) {
        IntArray temp(other);  
        swap(temp);            
    }
    return *this; 
}

IntArray& IntArray::operator=(IntArray&& other) noexcept
{
    if (this != &other) {
        delete[] p_;
        
        n_ = other.n_;
        p_ = other.p_;

        other.n_ = 0;
        other.p_ = nullptr;
    }
    return *this;
}


std::size_t IntArray::size() const noexcept
{
    return n_;
}

int* IntArray::data() noexcept
{
    return p_;
}

const int* IntArray::data() const noexcept
{
    return p_;
}


int& IntArray::operator[](std::size_t i) noexcept
{
    return p_[i];
}

const int& IntArray::operator[](std::size_t i) const noexcept
{
    return p_[i];
}


void IntArray::swap(IntArray& other) noexcept
{
    std::size_t temp_n = n_;
    n_ = other.n_;
    other.n_ = temp_n;
    
    int* temp_p = p_;
    p_ = other.p_;
    other.p_ = temp_p;
}

void IntArray::resize(std::size_t new_size, int value)
{
    if (new_size == n_) {
        return;
    }
    
    int* new_p = nullptr;
    if (new_size > 0) {
        new_p = new int[new_size];
    };
    
    std::size_t copy_size;
    if (n_ < new_size) {
        copy_size = n_;
    } else {
        copy_size = new_size;
    }

    for (std::size_t i = 0; i < copy_size; ++i) {
        new_p[i] = p_[i];
    }
    
    for (std::size_t i = copy_size; i < new_size; ++i) {
        new_p[i] = value;
    }
    
    delete[] p_;
    
    p_ = new_p;
    n_ = new_size;
}