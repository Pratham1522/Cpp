#include <iostream>
#include <vector>
#include <utility>

template<typename Key, typename Value>
class Map {
private:
    std::vector<std::pair<Key, Value>> data;

public:
    // Insert key-value pair into the map
    void insert(const Key& key, const Value& value) {
        data.push_back(std::make_pair(key, value));
    }

    // Retrieve value associated with the given key
    Value& operator[](const Key& key) {
        for (auto& pair : data) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not found in map");
    }

    // Check if the map contains the given key
    bool contains(const Key& key) const {
        for (const auto& pair : data) {
            if (pair.first == key) {
                return true;
            }
        }
        return false;
    }

    // Remove the key-value pair associated with the given key
    void erase(const Key& key) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->first == key) {
                data.erase(it);
                return;
            }
        }
        throw std::out_of_range("Key not found in map");
    }
};

int main() {
    Map<std::string, int> myMap;

    myMap.insert("apple", 10);
    myMap.insert("banana", 20);
    myMap.insert("orange", 30);

    std::cout << "Value associated with key 'apple': " << myMap["apple"] << std::endl;
    std::cout << "Value associated with key 'banana': " << myMap["banana"] << std::endl;
    std::cout << "Value associated with key 'orange': " << myMap["orange"] << std::endl;

    std::cout << "Does map contain key 'banana'? " << (myMap.contains("banana") ? "Yes" : "No") << std::endl;
    std::cout << "Does map contain key 'grape'? " << (myMap.contains("grape") ? "Yes" : "No") << std::endl;

    myMap.erase("banana");

    std::cout << "Does map contain key 'banana' after erasing it? " << (myMap.contains("banana") ? "Yes" : "No") << std::endl;

    return 0;
}
