#include <iostream>
#include <string>
#include <string_view>

// https://quick-bench.com/q/-6c8lOErVNyPoTDD9qGbJOeQx5s
void bench_pass_by_value(std::string_view copy) {
	copy;
}

void bench_pass_by_reference(const std::string_view& ref) {
	ref;
}

// https://quick-bench.com/q/NOnwTF30N51MPTPQG9FpigtNRiY
void bench() {
	std::string_view str{"Hello, World!"};

	bench_pass_by_value(str);      //  2.005
	bench_pass_by_reference(str);  //  1.005
}


// file file. file.any file.tmp

int main(int argc, char *argv[]) {
	// 0. Preliminary declarations
	std::string_view file_name;
	std::string_view ext_name;
	std::string tmp_name;

	const std::string_view suffix{".tmp"};

	// 1. Parse command line arguments
	for (int i = 1; i < argc; ++i) {
		file_name = argv[i];
		tmp_name = file_name;

		// 2. Filename does not contain any period
		const std::string::size_type idx = file_name.rfind('.');
		if (idx == std::string::npos) {
			tmp_name += suffix;
		} else {
			ext_name = file_name.substr(idx);

			if (ext_name.empty()) {
				tmp_name += suffix; // "qwerty." -> "qwerty.tmp"

			} else if (ext_name != suffix) {  // "qwerty.tmp" -> "qwerty.tmp"
				tmp_name.replace(idx, std::string::npos, suffix); // "qwerty.any" -> qwerty.tmp
			}

			// qwerty.tmp -> qwerty.tmp
		}
		std::cout << file_name << " --> " << tmp_name << std::endl;
	}

	return 0;
}