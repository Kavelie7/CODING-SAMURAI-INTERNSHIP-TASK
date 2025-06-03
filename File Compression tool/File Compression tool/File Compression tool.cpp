// HuffmanCompression.cpp
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// A Huffman tree node
struct Node {
    char ch;
    int freq;
    Node* left, * right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Compare two nodes (min heap based on frequency)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;  // Min heap
    }
};

// Recursively build the code map
void buildCode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right)
        huffmanCode[root->ch] = str;

    buildCode(root->left, str + "0", huffmanCode);
    buildCode(root->right, str + "1", huffmanCode);
}

// Encode a string using Huffman coding
void huffmanEncoding(string text) {
    // Count frequencies
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;

    // Priority queue (min heap) of tree nodes
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    // Root of the tree
    Node* root = pq.top();

    // Generate codes
    unordered_map<char, string> huffmanCode;
    buildCode(root, "", huffmanCode);

    cout << "\nHuffman Codes:\n";
    for (auto pair : huffmanCode)
        cout << pair.first << ": " << pair.second << endl;

    // Encode text
    string encoded = "";
    for (char ch : text)
        encoded += huffmanCode[ch];

    cout << "\nEncoded Data:\n" << encoded << endl;
}

int main() {
    string text;
    cout << "Enter text to compress: ";
    getline(cin, text);

    huffmanEncoding(text);

    return 0;
}
