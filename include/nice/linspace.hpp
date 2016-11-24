// -*- coding:utf-8; mode:c++; mode:auto-fill; fill-column:80; -*-

/// @file      linspace.hpp
/// @brief     Generation of linearly-spaced floating-point values.
/// @author    J. Arrieta <Juan.Arrieta@nablazerolabs.com>
/// @date      November 24, 2016
/// @copyright (c) 2016 Nabla Zero Labs

#pragma once
#ifndef NICE_LINSPACE_HPP_HEADER_GUARDS
#define NICE_LINSPACE_HPP_HEADER_GUARDS

// C++ Standard Library
#include <limits>
#include <iterator>

namespace nice {

template<typename T>
class linspace_iterator
    : public std::iterator<std::input_iterator_tag, T> {

 public:

  linspace_iterator() noexcept(true);
  linspace_iterator(T begin, T end, std::size_t n = 100) noexcept(true);

  const T& operator*() const noexcept(true);
  const T* operator->() const noexcept(true);

  linspace_iterator& operator++() noexcept(true);
  linspace_iterator operator++(int) noexcept(true);

  bool operator==(const linspace_iterator<T>& other) const noexcept(true);
  bool operator!=(const linspace_iterator<T>& other) const noexcept(true);

 private:

  void advance() noexcept(true);
  bool is_valid() const noexcept(true);
  bool same_members(const linspace_iterator<T>& other) const noexcept(true);

  T m_current;
  T m_step;
  T m_end;
  std::size_t m_n;
};

template<typename Container>
Container make_linspace(typename Container::value_type begin,
                        typename Container::value_type end,
                        std::size_t n = 100)
{
  return Container(linspace_iterator<typename Container::value_type>(begin, end, n),
                   linspace_iterator<typename Container::value_type>());
}

// -----------------------------------------------------------------------------
//                           Implementation Section
// -----------------------------------------------------------------------------

template<typename T>
linspace_iterator<T>::linspace_iterator() noexcept(true)
    : m_current { std::numeric_limits<T>::quiet_NaN() },
      m_step { std::numeric_limits<T>::quiet_NaN() },
      m_end {  std::numeric_limits<T>::quiet_NaN() },
      m_n {  std::numeric_limits<decltype(m_n)>::max() }
{
  static_assert(std::is_floating_point<T>::value, "linspace_iterator only supports floating point types");
}

template<typename T>
linspace_iterator<T>::linspace_iterator(T begin, T end, std::size_t n) noexcept(true)
    : m_current { begin },
      m_step { (end - begin) / (n - 1) },
      m_end { end },
      m_n { n - 1 }
{
  static_assert(std::is_floating_point<T>::value, "linspace_iterator only supports floating point types");
}

template<typename T>
const T&
linspace_iterator<T>::operator*() const noexcept(true)
{
  return m_current;
}

template<typename T>
const T*
linspace_iterator<T>::operator->() const noexcept(true)
{
  return &(this->operator*());
}

template<typename T>
linspace_iterator<T>&
linspace_iterator<T>::operator++() noexcept(true)
{
  this->advance();
  return *this;
}

template<typename T>
linspace_iterator<T>
linspace_iterator<T>::operator++(int) noexcept(true)
{
  linspace_iterator<T> tmp = *this;
  this->advance();
  return tmp;
}

template<typename T>
bool
linspace_iterator<T>::operator==(const linspace_iterator<T>& other) const noexcept(true)
{
  return ((is_valid() == other.is_valid()) and
          ((not is_valid()) or (same_members(other))));
}

template<typename T>
bool
linspace_iterator<T>::operator!=(const linspace_iterator<T>& other) const noexcept(true)
{
  return not ((*this) == other);
}

template<typename T>
void
linspace_iterator<T>::advance() noexcept(true)
{
  if (this->is_valid()) {
    --m_n;
    if (m_n == 0) {
      m_current = m_end;
    } else {
      m_current += m_step;
    }
  } else {
    m_current = std::numeric_limits<T>::quiet_NaN();
  }
}

template<typename T>
bool linspace_iterator<T>::is_valid() const noexcept(true)
{
  return m_n < std::numeric_limits<decltype(m_n)>::max();
}

template<typename T>
bool linspace_iterator<T>::same_members(const linspace_iterator<T>& other) const noexcept(true)
{
  return ((m_current == other.m_current) and
          (m_step    == other.m_step) and
          (m_end     == other.m_end) and
          (m_n       == other.m_n));
}

}  // namespace nice

#endif // NICE_LINSPACE_HPP_HEADER_GUARDS
