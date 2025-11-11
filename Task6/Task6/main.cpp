#include "Vector.h"
#include <iostream>
#include <vector>
#include <limits>

void printMenu() {
    std::cout << "\n=== Vector Operations Menu ===" << std::endl;
    std::cout << "1. Create new vector" << std::endl;
    std::cout << "2. Push back element" << std::endl;
    std::cout << "3. Push front element" << std::endl;
    std::cout << "4. Insert element at position" << std::endl;
    std::cout << "5. Erase element at position" << std::endl;
    std::cout << "6. Display current vector" << std::endl;
    std::cout << "7. Vector addition" << std::endl;
    std::cout << "8. Vector multiplication" << std::endl;
    std::cout << "9. Compare vectors" << std::endl;
    std::cout << "10. Show all vectors" << std::endl;
    std::cout << "11. Change current vector" << std::endl;
    std::cout << "12. Delete vector" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choose an option: ";
}

void showAllVectors(const std::vector<Vector>& vectors, int currentVectorIndex) {
    if (vectors.empty()) {
        std::cout << "No vectors created yet!" << std::endl;
    }
    else {
        std::cout << "\nAll vectors:" << std::endl;
        for (size_t i = 0; i < vectors.size(); ++i) {
            std::cout << "Vector #" << i << ": " << vectors[i]
                << " (size: " << vectors[i].get_size() << ")"
                << (i == currentVectorIndex ? " [CURRENT]" : "") << std::endl;
        }
    }
}

int main() {
    std::vector<Vector> vectors;
    int currentVectorIndex = -1;
    int choice;

    std::cout << "Welcome to Vector Interactive Program!" << std::endl;

    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int sizeChoice;
            std::cout << "Create vector: 1) Empty 2) With size: ";
            std::cin >> sizeChoice;

            if (sizeChoice == 1) {
                vectors.emplace_back();
            }
            else if (sizeChoice == 2) {
                size_t size;
                std::cout << "Enter initial size: ";
                std::cin >> size;
                vectors.emplace_back(size);
            }
            else {
                std::cout << "Invalid choice!" << std::endl;
                break;
            }

            currentVectorIndex = vectors.size() - 1;
            std::cout << "Created vector #" << currentVectorIndex << ": " << vectors[currentVectorIndex] << std::endl;
            break;
        }

        case 2: {
            if (currentVectorIndex == -1) {
                std::cout << "No vector selected! Create one first." << std::endl;
                break;
            }

            int value;
            std::cout << "Enter value to push back: ";
            std::cin >> value;
            vectors[currentVectorIndex].push_back(value);
            std::cout << "Vector after push_back: " << vectors[currentVectorIndex] << std::endl;
            break;
        }

        case 3: {
            if (currentVectorIndex == -1) {
                std::cout << "No vector selected! Create one first." << std::endl;
                break;
            }

            int value;
            std::cout << "Enter value to push front: ";
            std::cin >> value;
            vectors[currentVectorIndex].push_front(value);
            std::cout << "Vector after push_front: " << vectors[currentVectorIndex] << std::endl;
            break;
        }

        case 4: {
            if (currentVectorIndex == -1) {
                std::cout << "No vector selected! Create one first." << std::endl;
                break;
            }

            size_t pos;
            int value;
            std::cout << "Enter position to insert: ";
            std::cin >> pos;
            std::cout << "Enter value: ";
            std::cin >> value;
            vectors[currentVectorIndex].insert(pos, value);
            std::cout << "Vector after insert: " << vectors[currentVectorIndex] << std::endl;
            break;
        }

        case 5: {
            if (currentVectorIndex == -1) {
                std::cout << "No vector selected! Create one first." << std::endl;
                break;
            }

            size_t pos;
            std::cout << "Enter position to erase: ";
            std::cin >> pos;
            vectors[currentVectorIndex].erase(pos);
            std::cout << "Vector after erase: " << vectors[currentVectorIndex] << std::endl;
            break;
        }

        case 6: {
            if (currentVectorIndex == -1) {
                std::cout << "No vector selected!" << std::endl;
            }
            else {
                std::cout << "Current vector #" << currentVectorIndex << ": " << vectors[currentVectorIndex] << std::endl;
                std::cout << "Size: " << vectors[currentVectorIndex].get_size() << std::endl;
            }
            break;
        }

        case 7: {
            if (vectors.size() < 2) {
                std::cout << "Need at least 2 vectors for addition!" << std::endl;
                break;
            }

            showAllVectors(vectors, currentVectorIndex);
            int idx1, idx2;
            std::cout << "Enter first vector index (0-" << vectors.size() - 1 << "): ";
            std::cin >> idx1;
            std::cout << "Enter second vector index (0-" << vectors.size() - 1 << "): ";
            std::cin >> idx2;

            if (idx1 >= 0 && idx1 < vectors.size() && idx2 >= 0 && idx2 < vectors.size() && idx1 != idx2) {
                Vector result = vectors[idx1] + vectors[idx2];
                vectors.push_back(result);
                currentVectorIndex = vectors.size() - 1;
                std::cout << "Addition result (saved as vector #" << currentVectorIndex << "): " << result << std::endl;
            }
            else {
                std::cout << "Invalid vector indices!" << std::endl;
            }
            break;
        }

        case 8: {
            if (vectors.size() < 2) {
                std::cout << "Need at least 2 vectors for multiplication!" << std::endl;
                break;
            }

            showAllVectors(vectors, currentVectorIndex);
            int idx1, idx2;
            std::cout << "Enter first vector index (0-" << vectors.size() - 1 << "): ";
            std::cin >> idx1;
            std::cout << "Enter second vector index (0-" << vectors.size() - 1 << "): ";
            std::cin >> idx2;

            if (idx1 >= 0 && idx1 < vectors.size() && idx2 >= 0 && idx2 < vectors.size() && idx1 != idx2) {
                Vector result = vectors[idx1] * vectors[idx2];
                vectors.push_back(result);
                currentVectorIndex = vectors.size() - 1;
                std::cout << "Multiplication result (saved as vector #" << currentVectorIndex << "): " << result << std::endl;
            }
            else {
                std::cout << "Invalid vector indices!" << std::endl;
            }
            break;
        }

        case 9: {
            if (vectors.size() < 2) {
                std::cout << "Need at least 2 vectors for comparison!" << std::endl;
                break;
            }

            showAllVectors(vectors, currentVectorIndex);
            int idx1, idx2;
            std::cout << "Enter first vector index (0-" << vectors.size() - 1 << "): ";
            std::cin >> idx1;
            std::cout << "Enter second vector index (0-" << vectors.size() - 1 << "): ";
            std::cin >> idx2;

            if (idx1 >= 0 && idx1 < vectors.size() && idx2 >= 0 && idx2 < vectors.size() && idx1 != idx2) {
                bool equal = vectors[idx1] == vectors[idx2];
                std::cout << "Vector #" << idx1 << " == Vector #" << idx2 << ": "
                    << (equal ? "true" : "false") << std::endl;
            }
            else {
                std::cout << "Invalid vector indices!" << std::endl;
            }
            break;
        }

        case 10: {
            showAllVectors(vectors, currentVectorIndex);
            break;
        }

        case 11: {
            if (vectors.empty()) {
                std::cout << "No vectors created yet!" << std::endl;
                break;
            }

            showAllVectors(vectors, currentVectorIndex);
            int newIndex;
            std::cout << "Enter vector index to select (0-" << vectors.size() - 1 << "): ";
            std::cin >> newIndex;

            if (newIndex >= 0 && newIndex < vectors.size()) {
                currentVectorIndex = newIndex;
                std::cout << "Now working with vector #" << currentVectorIndex << ": "
                    << vectors[currentVectorIndex] << std::endl;
            }
            else {
                std::cout << "Invalid vector index!" << std::endl;
            }
            break;
        }

        case 12: {
            if (vectors.empty()) {
                std::cout << "No vectors to delete!" << std::endl;
                break;
            }

            showAllVectors(vectors, currentVectorIndex);
            int indexToDelete;
            std::cout << "Enter vector index to delete (0-" << vectors.size() - 1 << "): ";
            std::cin >> indexToDelete;

            if (indexToDelete >= 0 && indexToDelete < vectors.size()) {
                if (vectors.size() == 1) {
                    vectors.clear();
                    currentVectorIndex = -1;
                    std::cout << "Vector deleted. No vectors remaining." << std::endl;
                }
                else {
                    vectors.erase(vectors.begin() + indexToDelete);
                    if (currentVectorIndex == indexToDelete) {
                        currentVectorIndex = 0;
                    }
                    else if (currentVectorIndex > indexToDelete) {
                        currentVectorIndex--;
                    }
                    std::cout << "Vector #" << indexToDelete << " deleted." << std::endl;
                    std::cout << "Now working with vector #" << currentVectorIndex << std::endl;
                }
            }
            else {
                std::cout << "Invalid vector index!" << std::endl;
            }
            break;
        }

        case 0: {
            std::cout << "Goodbye!" << std::endl;
            break;
        }

        default: {
            std::cout << "Invalid option! Please try again." << std::endl;
            break;
        }
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != 0);

    return 0;
}