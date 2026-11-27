// HashMap.tpp -- implementation of HashMap<V>. Included at the end of HashMap.h.
//
// Name: Patrick Quan
// SDSU ID: 133858566
//
// Every function below is a stub that compiles but does nothing useful.
// Replace each TODO with your implementation.

#include "HashMap.h"

template <class V>
HashMap<V>::HashMap() : HashMap(DEFAULT_BUCKETS) {

}

//second constructor
//set every node to null bc when map is first created, it has no nodes, so therefore everything is null
template <class V>
HashMap<V>::HashMap(std::size_t initialBuckets) {
    buckets_.resize(initialBuckets, nullptr);
    size_ = 0;
}
// *POINTERS deconstructor, just delete any dynamically allocated memory in the map
template <class V>
HashMap<V>::~HashMap() {
    for (std::size_t i = 0; i < buckets_.size(); i++) {
        Node* current = buckets_[i];

        while (current != nullptr) { //while there is a node
            Node* next = current->next; //save the next node
            delete current; //delete the current node
            current = next; //go to the next node that got saved
        }
    }
}

template <class V>
bool HashMap<V>::put(const std::string& key, const V& value) {
    // TODO
    // need to handle two situations: Key exists, then replace value and if the key and value dont exist, then create new node and insert

    std::size_t index = hashString(key) % buckets_.size(); //want to find the correct bucket
    Node* current = buckets_[index];
    while (current != nullptr) {
        if (current->key == key) {
            current->value = value;
            return false;
        }
        current = current->next;
    }

    Node* newNode = new Node{key, value, buckets_[index]};
    buckets_[index] = newNode;
    size_++;

    return true;
}

template <class V>
std::optional<V> HashMap<V>::get(const std::string& key) const {
    // TODO
    (void)key;
    return std::nullopt;
}

template <class V>
bool HashMap<V>::contains(const std::string& key) const {
    // TODO
    (void)key;
    return false;
}

template <class V>
bool HashMap<V>::remove(const std::string& key) {
    // TODO
    (void)key;
    return false;
}

template <class V>
std::size_t HashMap<V>::size() const {
    return size_;
}

template <class V>
bool HashMap<V>::empty() const {
    return size_ == 0;
}

template <class V>
std::size_t HashMap<V>::bucketCount() const {
    return buckets_.size();
}

template <class V>
double HashMap<V>::loadFactor() const {
    // TODO
    return 0.0;
}

template <class V>
std::size_t HashMap<V>::longestChain() const {
    // TODO
    return 0;
}

template <class V>
std::size_t HashMap<V>::hashString(const std::string& s) {
    // TODO: design your own hash function. Do not call std::hash.
    // Justify your choice in your report.
    (void)s;
    return 0;
}

template <class V>
void HashMap<V>::rehash(std::size_t newBucketCount) {
    // TODO
    (void)newBucketCount;
}
