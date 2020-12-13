#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

string get_word(istream& t)  // видобуваєм введений текст з t.txt
{
    string w;
    t >> w;
    return w;
}

string search()
{
    ifstream t("t.txt"); 
    if (!t) {
        cerr << " Error! " << endl;
    }
    
    string word, max_word;
    size_t len, max_len = 0;
    
    while (t)
    {
        word = get_word(t);
        if (word.length() == 0)
            break;

        len = word.length();

        if (len > max_len) {
            max_len = len;
            max_word = word;
        }
    }
    return max_word;
}

int main()
{  
    string word;
    cout << " Input text: "; getline(cin, word); // вводимо тект

    ofstream t;
    t.open("t.txt");
    if (t.is_open())
    {
        t << word << endl; // записуємо введений текст в файл t.txt
    }


    string max_word = search();
    cout << " Count of symbols: " << max_word.length() << endl;
    cout << " The longest word: " << max_word << endl;
    
    ofstream h;
    h.open("h.txt");
    if (h.is_open()) // записуємо результат в інший файл h.txt
    {
        h << max_word << endl;
        h << max_word.length() << endl;
    }

    return 0;
}