# `nice` &mdash; a library of simple, *nice* utilities.

This library provides simple utilities that are *nice* to have.

## Using `linspace` and `logspace`

These modules are used to produce linear- or logarithmically-spaced
floating-point values. Normally you would just place the resulting
values inside a container such as `std::vector<T>`, but you can use
`nice::linspace_iterator` and `nice::logspace_iterator` directly to
iterate over the values without needing to store them.

As with most other implementations of `linspace` and `logspace`, the
default number of values generated is 100.

```c++
// C++ Standard Library
#include <iostream>
#include <vector>

// nice Library
#include <nice/linspace.hpp>
#include <nice/logspace.hpp>

int main()
{
  std::cout << "linspace(-1, 5, 7)\n";
  auto vlin = nzl::nice::make_linspace<std::vector<double>>(-1, 5, 7);
  for (const auto & item : vlin)  std::cout << item << "\n";

  std::cout << "logspace(1, 5, 7)\n";
  auto vlog = nzl::nice::make_logspace<std::vector<float>>(1, 5, 7);
  for (const auto & item : vlog) std::cout << item << "\n";
}
```

## Using `slurp`

The `slurp` function is used to read an entire file into an `std::string`.

```c++
#include <nice/slurp.hpp>
int main(int argc, char* argv[])
{
    // [error checking, etc...]
    auto contents = nzl::nice::slurp(argv[1]);
    // do something with "contents" (an std::string)
}
```
