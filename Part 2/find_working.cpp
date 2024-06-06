#include <iostream>
#include <unordered_map>

int main() {
    // Create an unordered_map
    std::unordered_map<int, std::string> umap;

    // Insert some elements into the unordered_map
    umap[1] = "one";
    umap[2] = "two";
    umap[3] = "three";

    // Use find to search for a key
    int key = 2;
    auto it = umap.find(key);

    // Check if the key was found
    if (it != umap.end()) {
        std::cout << "Key " << key << " found with value: " << it->second << std::endl;
    } else {
        std::cout << "Key " << key << " not found" << std::endl;
    }

    // Try to find a key that doesn't exist
    key = 4;
    it = umap.find(key);

    if (it != umap.end()) {
        std::cout << "Key " << key << " found with value: " << it->second << std::endl;
    } else {
        std::cout << "Key " << key << " not found" << std::endl;
    }

    return 0;
}
