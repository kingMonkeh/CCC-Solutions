#include <cstdio>
#include <iostream>
#include <map>
#include <string>

int main(){
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int N;
    std::cin >> N;
    std::map<char, int> total;
    for (int i = 0; i < N; i++){
        std::map<char, int> a_freq, b_freq;
        std::string a, b;
        std::cin >> a >> b;
        for (int j = 0; j < a.length(); j++){
            a_freq[a[j]]++;
        }
        for (int j = 0; j < b.length(); j++){
            b_freq[b[j]]++;
        }
        for (char letter = 'a'; letter <= 'z'; letter++){
            total[letter] += std::max(a_freq[letter], b_freq[letter]);
        }
    }   
    for (char letter = 'a'; letter <= 'z'; letter++){
        std::cout << total[letter] << '\n';
    }
    return 0;
}