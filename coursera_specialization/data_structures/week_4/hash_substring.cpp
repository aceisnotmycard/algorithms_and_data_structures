#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

size_t hash(string::const_iterator begin, string::const_iterator end, size_t x, size_t p) {
    size_t value = 0;
    for (auto it = begin; it != end; it++) {
        size_t it_pos = std::distance(begin, it);
        value += ((*it * (size_t) pow(x, it_pos)) % p + p) % p;
    }
    return value;
}

void print_occurrences(const std::vector<size_t>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<size_t> precompute_hashes(string text, size_t pattern_length, size_t p, size_t x) {
    std::vector<size_t> hashes(text.length() - pattern_length + 1);
    hashes[hashes.size() - 1] = hash(std::end(text) - pattern_length, std::end(text), x, p);
    size_t y = static_cast<size_t>(pow(x, pattern_length)) % p;
    for (size_t i = hashes.size() - 2; i >= 0 && i < hashes.size(); i--) {
        hashes[i] = ((x * hashes[i + 1] + text[i] - y*text[i + pattern_length]) % p + p) % p;
    }
    return hashes;
}

std::vector<size_t> get_occurrences(const Data& input) {
    const string& s = input.pattern;
    const string& t = input.text;
    std::vector<size_t> ans;
    size_t x = 1;
    size_t p = static_cast<size_t>(pow(10, 9)) + 7;
    size_t pattern_hash = hash(std::begin(s), std::end(s), x, p);
    std::vector<size_t> precomputed_hashes = precompute_hashes(t, s.length(), p, x);
    for (auto it = std::begin(t); it != std::end(t) - s.length() + 1; it++) {
        size_t it_pos = std::distance(std::begin(t), it);
        if (precomputed_hashes[it_pos] == pattern_hash && std::equal(std::begin(s), std::end(s), it)) {
            ans.push_back(it_pos);
        }
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
