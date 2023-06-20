#include <iostream>
#include <string>

std::string a, b;
bool possible = false;
std::string current = "";
void solve (int i, int j){
    if (j == b.length() && i == a.length()){
        possible = true;
        return;
    }
    if (a[i] == b[j]){
        solve (i + 1, j + 1);
    }
    else if (a[i] > b[j]){
        possible = false;
        return;
    }
    else{
        if (i < a.length()){
            current += a[i++];
        }
        bool change = true;
        while (current.length() >= 1 && change){
            change = false;
            if (current[0] == b[j]){
                current = "";
                solve (i, j + 1);
                break;
            }
            if (i < a.length()){
                change = true;
                current += a[i++];
            }
            while (current.length() >= 2 && current[current.length() - 1] == current[current.length() - 2]){
                change = true;
                char next = current[current.length() - 1] + 1;
                if (next == '{'){
                    possible = false;
                    return;
                }
                else {
                    current.pop_back();
                    current.pop_back();
                    current += next;
                }
            }
        }
    }
}

int main (){
    int T;
    std::cin >> T;
    while (T--){  
        std::cin >> a >> b;
        if (b.length() > a.length()){
            std::cout << "NO\n";
            continue;
        }
        solve(0, 0);
        if (possible){
            std::cout << "YES\n";
        }
        else{
            std::cout << "NO\n";
        }
        possible = false;
        current = "";
    }
    return 0;
}