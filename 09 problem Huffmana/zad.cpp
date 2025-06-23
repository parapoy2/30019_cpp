#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    char character;
    int frequency;
    Node* left;
    Node* right;

    Node(char ch, int freq)
        : character(ch), frequency(freq), left(nullptr), right(nullptr) {}

    Node(char ch, int freq, Node* left, Node* right)
        : character(ch), frequency(freq), left(left), right(right) {}
};

struct compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

void printCodes(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->character] = str;
    }

    printCodes(root->left, str + "0", huffmanCode);
    printCodes(root->right, str + "1", huffmanCode);
}

void buildHuffmanTree(string text) {
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        int sum = left->frequency + right->frequency;
        pq.push(new Node('\0', sum, left, right));
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    printCodes(root, "", huffmanCode);

    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << "Character: '" << pair.first << "', frequency: " << freq[pair.first]
            << ", Huffman code: " << pair.second << "\n";
    }

    cout << "\nOriginal string:\n" << text << "\n";

    string str = "";
    for (char ch : text) {
        str += huffmanCode[ch];
    }
    cout << "\nEncoded string:\n" << str << "\n";

    auto decode = [&](string str) {
        cout << "\nDecoded string:\n";
        Node* curr = root;
        for (char bit : str) {
            if (bit == '0') curr = curr->left;
            else curr = curr->right;
            if (!curr->left && !curr->right) {
                cout << curr->character;
                curr = root;
            }
        }
        cout << "\n";
        };

    decode(str);

    int bityASCII = text.length() * 8;
    int bityHuffmana = 0;
    for (auto pair : freq) {
        bityHuffmana += pair.second * huffmanCode[pair.first].length();
    }
    double wspKompresji = (double)bityASCII / bityHuffmana;

    cout << "\nBits ASCII: " << bityASCII << endl;
    cout << "Bits Huffmana: " << bityHuffmana << endl;
    cout << "Compression ratio: " << wspKompresji << endl;
}

int main() {
    string text = R"(Za­sa­dził dzia­dek rzep­kę w ogro­dzie, 
        Cho­dził tę rzep­kę oglą­dać co dzień.
        Wy­ro­sła rzep­ka jędr­na i krzep­ka,
        Schru­pać by rzep­kę z ka­wał­kiem chleb­ka!
        Więc cią­gnie rzep­kę dzia­dek nie­bo­żę,
        Cią­gnie i cią­gnie, wy­cią­gnąć nie może.

        Za­wo­łał dzia­dek na pomoc bab­cię :
    „Ja zła­pię rzecz­kę, ty za mnie złap się!”
        I bied­ny dzia­dek z bab­cią nie­bo­gą
        Cią­gną i cią­gną, wy­cią­gnąć nie mogą.
        Bab­cia za dziad­ka,
        Dzia­dek za rzep­kę,
        Oj, przy­dał­by się ktoś na przy­czep­kę!

        Przy­le­ciał wnu­czek, babci się zła­pał,
        Poci się, stęka, aż się za­sa­pał!
        Wnu­czek za bab­cię,
        Bab­cia za dziad­ka,
        Dzia­dek za rzep­kę,
        Oj, przy­dał­by się ktoś na przy­czep­kę!
        Pocą się, sapią, stę­ka­ją srogo,
        Cią­gną i cią­gną, wy­cią­gnąć nie mogą.

        Za­wo­łał wnu­czek szcze­niacz­ka Mrucz­ka,
        Przy­le­ciał Mru­czek i cią­gnie wnucz­ka!
        Mru­czek za wnucz­ka,
        Wnu­czek za bab­cię,
        Bab­cia za dziad­ka,
        Dzia­dek za rzep­kę,
        Oj, przy­dał­by się ktoś na przy­czep­kę!
        Pocą się, sapią, stę­ka­ją srogo,
        Cią­gną i cią­gną, wy­cią­gnąć nie mogą!

        Na kurkę czy­hał kotek w ukry­ciu,
        Za­szcze­kał Mru­czek : „Pomóż nam, Kiciu!”
        Kicia za Mrucz­ka,
        Mru­czek za wnucz­ka,
        Wnu­czek za bab­cię,
        Bab­cia za dziad­ka,
        Dzia­dek za rzep­kę,
        Oj, przy­dał­by się ktoś na przy­czep­kę!
        Pocą się, sapią, stę­ka­ją srogo,
        Cią­gną i cią­gną, wy­cią­gnąć nie mogą!

        Więc woła Kicia kurkę z po­dwór­ka,
        Wnet przy­le­cia­ła usłuż­na kurka.
        Kurka za Kicię,
        Kicia za Mrucz­ka,
        Mru­czek za wnucz­ka,
        Wnu­czek za bab­cię,
        Bab­cia za dziad­ka,
        Dzia­dek za rzep­kę,
        Oj, przy­dał­by się ktoś na przy­czep­kę!
        Pocą się, sapią, stę­ka­ją srogo,
        Cią­gną i cią­gną, wy­cią­gnąć nie mogą!

        Szła sobie gąska ście­ży­ną wąską,
        Krzyk­nę­ła kurka : „Chodź no tu, gąsko!”
        Gąska za kurkę,
        Kurka za Kicię,
        Kicia za Mrucz­ka,
        Mru­czek za wnucz­ka,
        Wnu­czek za bab­cię,
        Bab­cia za dziad­ka,
        Dzia­dek za rzep­kę,
        Oj, przy­dał­by się ktoś na przy­czep­kę!
        Pocą się, sapią, stę­ka­ją srogo,
        Cią­gną i cią­gną, wy­cią­gnąć nie mogą!Le­ciał wy­so­ko bocian - długonos,
        „Fruń­że tu, boćku, do nas na pomoc!”
        Bo­ciek za gąskę,
        Gąska za kurkę,
        Kurka za Kicię,
        Kicia za Mrucz­ka,
        Mru­czek za wnucz­ka,
        Wnu­czek za bab­cię,
        Bab­cia za dziad­ka,
        Dzia­dek za rzep­kę,
        Oj, przy­dał­by się ktoś na przy­czep­kę!
        Pocą się, sapią, stę­ka­ją srogo,
        Cią­gną i cią­gną, wy­cią­gnąć nie mogą!

        Ska­ka­ła drogą zie­lo­na żabka,
        Zła­pa­ła boćka – rzad­ka to grat­ka!
        Żabka za boćka,
        Bo­ciek za gąskę,
        Gąska za kurkę,
        Kurka za Kicię,
        Kicia za Mrucz­ka,
        Mru­czek za wnucz­ka,
        Wnu­czek za bab­cię,
        Bab­cia za dziad­ka,
        Dzia­dek za rzep­kę,
        A na przy­czep­kę
        Kawka za żabkę,
        Bo na tę rzep­kę
        Też miała chrap­kę.

        Tak się za­wzię­li,
        Tak się na­dę­li,
        Że nagle rzep­kę
        Trr­rach!!– wy­cią­gnę­li!
        Aż wstyd po­wie­dzieć,
        Co było dalej!
        Wszy­scy na sie­bie
        Po­upa­da­li :

    Rzep­ka na dziad­ka,
        Dzia­dek na bab­cię,
        Bab­cia na wnucz­ka,
        Wnu­czek na Mrucz­ka,
        Mru­czek na Kicię,
        Kicia na kurkę,
        Kurka na gąskę,
        Gąska na boćka,
        Bo­ciek na żabkę,
        Żabka na kawkę
        I na ostat­ku
        Kawka na traw­kę. )"
    ;
    buildHuffmanTree(text);
    
    cin.get();
    return 0;
}