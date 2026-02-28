#pragma once
#include <cstddef>

class IntArray {
public:
  // 1) Конструкторы
  IntArray() noexcept;                          // пустой массив
  explicit IntArray(std::size_t n, int value=0);// n элементов, заполнить value

  // 2) Правило пяти
  IntArray(const IntArray& other);              // deep copy
  IntArray& operator=(const IntArray& other);   // deep copy

  IntArray(IntArray&& other) noexcept;          // steal ptr, other -> empty
  IntArray& operator=(IntArray&& other) noexcept;

  ~IntArray();

  // 3) Доступ
  std::size_t size() const noexcept;
  int* data() noexcept;
  const int* data() const noexcept;

  int& operator[](std::size_t i) noexcept;
  const int& operator[](std::size_t i) const noexcept;

  // 4) Утилиты
  void swap(IntArray& other) noexcept;
  void resize(std::size_t new_size, int value = 0); // сохранить старые элементы

private:
  std::size_t n_ = 0;
  int* p_ = nullptr;
};
