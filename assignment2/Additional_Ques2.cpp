
#include <iostream>
using namespace std;

int sub(char *a, int length_a, char *b, int length_b){
    if(length_a > length_b) return 0;
    for(int p=0; p<length_a; p++)
        if(a[p] != b[p]) return 0;
    return 1;
}

int main() {
    char s[1000];
    cin >> s;

    int n = 0;
    while (s[n] != '\0') n++;

    bool ok = false;

    for(int i=1; i<n-1 && !ok; i++){
        for(int j=i+1; j<n && !ok; j++){
            char *x = s;
            char *y = s + i;
            char *z = s + j;
            int length_x = i, length_y = j-i, length_z = n-j;

            if ((length_x >= length_y && sub(y,length_y,x,length_x) && length_z >= length_y && sub(z,length_z,x,length_x)) ||
                (length_y >= length_x && sub(x,length_x,y,length_y) && length_z >= length_x && sub(z,length_z,y,length_y)) ||
                (length_z >= length_x && sub(x,length_x,z,length_z) && length_y >= length_z && sub(y,length_y,z,length_z)))
                ok = true;
        }
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
