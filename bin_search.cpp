// Linear search algorithm to find the first occurrence of a given element in a CSV file
// csv_file - a CSV file object to be searched
// search_string - the element to be searched for
// Returns the first row index where the element is found, else returns -1

int linearSearch(std::ifstream& csv_file, const std::string& search_string) {
    std::string row; // Store each row of the CSV file
    int row_index = 0; // Keep track of the current row index
    while (std::getline(csv_file, row)) { // Read each row of the CSV file
        ++row_index;
        std::istringstream row_stream(row);
        std::string field;
        while (std::getline(row_stream, field, ',')) { // Search for the element in each field of the row
            if (field == search_string) { // If the element is found, return its row index
                return row_index;
            }
        }
    }
    // If the element is not found, return -1
    return -1;
}


// Binary search algorithm to find the first occurrence of a given element in a sorted CSV file
// csv_file - a sorted CSV file object to be searched
// search_string - the element to be searched for
// Returns the first row index where the element is found, else returns -1

int binarySearch(std::ifstream& csv_file, const std::string& search_string) {
    int low = 0; // Lower index of the search interval
    csv_file.seekg(0, std::ios::end);
    int high = csv_file.tellg(); // Upper index of the search interval
    while (low <= high) { // Continue searching while search interval is valid
        int mid = low + (high - low) / 2; // Compute the middle index
        csv_file.seekg(mid, std::ios::beg);
        std::getline(csv_file, search_string);
        int result = search_string.compare(0, search_string.find(','), search_string); // Compare the search string to the current row element
        if (result == 0) { // If the element is found, return its row index
            return mid;
        }
        else if (result < 0) { // If the element is less than the current row element, search the left half of the file
            high = mid - 1;
        }
        else { // If the element is greater than the current row element, search the right half of the file
            low = mid + 1;
        }
    }
    // If the element is not found, return -1
    return -1;
}
