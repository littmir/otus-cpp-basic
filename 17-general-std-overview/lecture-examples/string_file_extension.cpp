#include <iostream>
#include <string>

// file file. file.any file.tmp

int main(int argc, char *argv[]) {
	// 0. Preliminary declarations
	std::string file_name;
	std::string ext_name;
	std::string tmp_name;

	const std::string suffix{".tmp"};

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
		}
		std::cout << file_name << " --> " << tmp_name << std::endl;
	}

	return 0;
}