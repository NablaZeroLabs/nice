// -*- coding:utf-8; mode:c++; mode:auto-fill; fill-column:80; -*-

/// @file      slurp.hpp
/// @brief     Slurp a file into an `std::string`.
/// @author    J. Arrieta <Juan.Arrieta@nablazerolabs.com>
/// @date      November 24, 2016
/// @copyright (c) 2016 Nabla Zero Labs
/// @license   The MIT License (MIT)

#pragma once
#ifndef NICE_SLURP_HPP_HEADER_GUARDS
#define NICE_SLURP_HPP_HEADER_GUARDS

// C++ Standard Library
#include <cstring>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>

namespace nzl {
namespace nice {

/// @brief Slurp a file into an `std::string`.
/// @param [in] filename Path to the file.
/// @return An `std::string` with the file contents.
/// @throws std::runtime_error If the file cannot be open or read.
/// @throws std::length_error If the file size is larger than `std::string.max_size()`,
/// @throws std::ios_base::failure If an error occurred while reading the file.
/// @note The implementation of this function is based on the answers to my
/// stackoverflow.com question `Read whole ASCII file into C++ std::string`
/// posted on April 08, 2010.
///
/// Example:
///
/// @code
/// #include <iostream>
/// #include <nice/slurp.hpp>
///
/// int
/// main()
/// {
///   auto contents = slurp(__FILE__);
///   std::cout << "read " __FILE__ " (size: " << contents.size() << ")\n";
/// }
///
/// @endcode
///
/// The example can be compiled with g++ or clang++ using either the
/// `-std=c++11` or `-std=c++14` flags (and it should compile on any compiler
/// supporting at least C++11).
inline std::string
slurp(const std::string& filename)
{
  std::ifstream fp(filename, std::ios::in | std::ios::binary);

  if (fp) {

    std::string contents;

    fp.seekg(0, std::ios::end);
    contents.resize(fp.tellg());
    fp.seekg(0, std::ios::beg);

    fp.read(&contents[0], contents.size());
    fp.close();

    return contents;

  } else {

    std::ostringstream msg;

    msg << "cannot slurp \""
        << filename
        << "\": " << std::strerror(errno);

    throw std::runtime_error(msg.str());
  }
}

} // namespace nice
} // namespace nzl

#endif // NICE_SLURP_HPP_HEADER_GUARDS
