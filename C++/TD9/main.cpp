#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

struct Date {
    int day;
    int month;
    int year;
};

struct FileRecord {
    Date date;
    std::string sha;
    std::string filename;
};

void slice(std::istream& is, int& day, int& month, int& year) {
    char sep1, sep2;
    is >> day >> sep1 >> month >> sep2 >> year;
    if (is && (sep1 != '-' || sep2 != '-')) {
        std::cerr << "Invalid date format" << std::endl;
    }
}

std::vector<FileRecord> loadFileRecords(const std::string& filepath) {
    std::vector<FileRecord> records;
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filepath << std::endl;
        return records;
    }
    while(file) {
        FileRecord record;
        slice(file, record.date.day, record.date.month, record.date.year);
        if (!file) break;
        file >> record.sha >> record.filename;
        records.push_back(record);
    }
    file.close();
    return records;
}

void afficher(const std::vector<FileRecord>& records) {
    for (const auto& record : records) {
        std::cout << record.date.day << "/" << record.date.month << "/" << record.date.year
                  << " " << record.sha << " " << record.filename << std::endl;
    }
}

int main() {
    const std::string filepath = "/home/bakame03/Documents/BUT1/Folders_Linked_With_GitHub/C_Plus_Plus_Projects/C++/TD9/data.txt"; // Replace with your actual file path
    std::vector<FileRecord> records = loadFileRecords(filepath);
    afficher(records);
    return 0;
}   
