// -*- coding:utf-8; mode:c++; mode:auto-fill; fill-column:80; -*-

/// @file      test-nice.cpp
/// @brief     Unit tests for the `nice` library.
/// @author    J. Arrieta <Juan.Arrieta@nablazerolabs.com>
/// @date      November 24, 2016
/// @copyright (c) 2016 Nabla Zero Labs
/// @license   The MIT License (MIT)

// C++ Standard Library
#include <iostream>
#include <vector>

// catch Library (a unit test framework)
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// nice Library (included within an anonymous namespace because there
// are collisions between `nice` and unistd.h in OS X).
namespace {
#include <nice/linspace.hpp>
#include <nice/logspace.hpp>
#include <nice/slurp.hpp>
}

TEST_CASE("linspace defaults to 100 values", "[linspace]") {
  auto vlin = nice::make_linspace<std::vector<double>>(-100, 100);
  REQUIRE(vlin.size() == 100);
  REQUIRE(vlin.front() == -100);
  REQUIRE(vlin.back() == 100);
}

TEST_CASE("logspace defaults to 100 values", "[logspace]") {
  auto vlog = nice::make_logspace<std::vector<double>>(0, 5);
  REQUIRE(vlog.size() == 100);
  REQUIRE(vlog.front() == 1);
  REQUIRE(vlog.back() == std::pow(10, 5));
}

TEST_CASE("slurp can read this file", "[slurp]") {
  auto contents = nice::slurp(__FILE__);  
  REQUIRE(contents.size() > 0);
}

