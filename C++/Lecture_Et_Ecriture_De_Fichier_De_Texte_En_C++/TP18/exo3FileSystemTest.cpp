#include <iostream>
#include <filesystem>

int main(int argc, char* argv[]) {
    std::filesystem::path dirPath;

    if (argc == 1) {
        dirPath = std::filesystem::current_path();
    } else if (argc == 2) {
        dirPath = argv[1];
    } else {
        std::cerr << "Usage: " << argv[0] << " [directory_path]" << std::endl;
        return 1;
    }

    if (!std::filesystem::exists(dirPath) || !std::filesystem::is_directory(dirPath)) {
        std::cerr << "Error: \"" << dirPath << "\" is not a valid directory." << std::endl;
        return 1;
    }

    for (const auto& entry : std::filesystem::directory_iterator(dirPath)) {
        if (std::filesystem::is_directory(entry.status())) {
            std::cout << "D  " << entry.path().filename().string() << std::endl;
        } else if (std::filesystem::is_regular_file(entry.status())) {
            std::cout << "F  " << entry.path().filename().string() 
                      << " (" << std::filesystem::file_size(entry.path()) << " bytes)" << std::endl;
        } else {
            std::cout << "?  " << entry.path().filename().string() << std::endl;
        }
    }

    return 0;
}