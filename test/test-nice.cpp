// -*- coding:utf-8; mode:c++; mode:auto-fill; fill-column:80; -*-

/// @file      test-nice.cpp
/// @brief     Unit tests for the `nice` library.
/// @author    J. Arrieta <Juan.Arrieta@nablazerolabs.com>
/// @date      November 24, 2016
/// @copyright (c) 2016 Nabla Zero Labs
/// @license   The MIT License (MIT)

// C++ Standard Library
#include <vector>

// Google Test Library
#include <gtest/gtest.h>

// nice Library
#include <nice/linspace.hpp>
#include <nice/logspace.hpp>
#include <nice/slurp.hpp>

TEST(linspace, defaults_to_100_values) {
  auto vlin = nzl::nice::make_linspace<std::vector<double>>(-100, 100);
  EXPECT_EQ(vlin.size(), 100);
  EXPECT_EQ(vlin.front(), -100);
  EXPECT_EQ(vlin.back(), 100);
}

TEST(logspace, defaults_to_100_values) {
  auto vlog = nzl::nice::make_logspace<std::vector<double>>(0, 5);
  EXPECT_EQ(vlog.size(), 100);
  EXPECT_EQ(vlog.front(), 1);
  EXPECT_EQ(vlog.back(), std::pow(10, 5));
}

TEST(slurp, can_read_this_file){
  auto contents = nzl::nice::slurp(__FILE__);
  EXPECT_GT(contents.size(), 0);
}
