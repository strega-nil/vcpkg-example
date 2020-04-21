# Vcpkg Example

This is an example repository for how one might use vcpkg in the future.

## Building

Assuming you have `VCPKG_ROOT` in your environment variables, the following
will work in sh:

```sh
$ cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
$ cmake --build build
```

Change out the environment variable syntax for each system, and this
should work everywhere.
