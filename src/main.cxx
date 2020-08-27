#include <fmt/format.h>
#include <zlib.h>

int main() {
	fmt::print("zlib version is {}, and the header version is {}\n", zlibVersion(), ZLIB_VERSION);
}
