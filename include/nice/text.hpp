// -*- coding:utf-8; mode:c++; mode:auto-fill; fill-column:80; -*-

/// @file      text.hpp
/// @brief     String and text processing functionality.
/// @author    J. Arrieta <Juan.Arrieta@nablazerolabs.com>
/// @date      November 25, 2016
/// @copyright (c) 2016 Nabla Zero Labs
/// @license   The MIT License (MIT)

#pragma once
#ifndef NICE_TEXT_HPP_HEADER_GUARDS
#define NICE_TEXT_HPP_HEADER_GUARDS

// C++ Standard Library
#include <cctype>
#include <string>
#include <algorithm>

namespace {

inline bool
is_not_space(char c)
{
  return not std::isspace(c);
}

}

namespace nzl {
namespace nice {

inline std::string&
trim_right(std::string& s)
{
  s.erase(std::find_if(s.rbegin(), s.rend(), is_not_space).base(), s.end());
  return s;
}

inline std::string&
trim_left(std::string& s)
{
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), is_not_space));
  return s;
}

inline std::string&
trim(std::string& s)
{
  return trim_right(trim_left(s));
}

inline std::string&
to_lower(std::string& s)
{
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

inline std::string&
to_upper(std::string& s)
{
  std::transform(s.begin(), s.end(), s.begin(), ::toupper);
  return s;
}

inline bool
semantic_equals(std::string lhs, std::string rhs)
{
  return trim(to_lower(lhs)) == trim(to_lower(rhs));
}

} // namespace nice
} // namespace nzl

#endif // NICE_TEXT_HPP_HEADER_GUARDS
