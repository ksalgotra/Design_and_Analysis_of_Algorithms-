/*
Input:
Characters = [a, b, c, d, e, f]
Frequencies = [5, 9, 12, 13, 16, 45]

Output:
Character Huffman Code
a 1100
b 1101
c 100
d 101
e 111
f 0
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;


struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};


map<char, string> huffmanCodeMap;

// Left Child = "0", Right Child = "1"
void generateCodes(Node* root, string str) {
    if (!root) return;

    // If leaf node, store the code
    if (root->ch != '$') {
        huffmanCodeMap[root->ch] = str;
    }

    generateCodes(root->left, str + "0");
    generateCodes(root->right, str + "1");
}

void HuffmanCoding(int n, vector<char> data, vector<int> freq) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;


    for (int i = 0; i < n; ++i) {
        minHeap.push(new Node(data[i], freq[i]));
    }


    while (minHeap.size() != 1) {
        
        Node* left = minHeap.top();
        minHeap.pop();

        Node* right = minHeap.top();
        minHeap.pop();

        
        Node* top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

   
    generateCodes(minHeap.top(), "");

    cout << "Character Huffman Code" << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i] << " " << huffmanCodeMap[data[i]] << endl;
    }
}

int main() {
    
    int N = 6;
    vector<char> chars = { 'a', 'b', 'c', 'd', 'e', 'f' };
    vector<int> freq = { 5, 9, 12, 13, 16, 45 };

    HuffmanCoding(N, chars, freq);

    return 0;
}
