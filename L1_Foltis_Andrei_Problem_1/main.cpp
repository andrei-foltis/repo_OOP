#include <iostream>

//Funktion aproximiert Wurzel
float wurzel(float n) {
    float i=0;
    while (i*i<=n){
        if (i*i==n) {
            return i;
        }
        i++;
    }
    return i-1;
}

bool isprime(int x) {
    if (x<2) {
        return false;
    }
    for (int i=2; i<=x/2; i++) {
        if (x%i==0) {
            return false;
        }
    }
    return true;
}

//Funkton druckt den Elementen von st bis fin einer array
void print_array(int v[], int st, int fin) {
    while (st<=fin) {
        std::cout<<v[st]<<" ";
        st++;
    }
    std::cout<<"\n";
}

//Funktion bestimmt die langste Teilfolge von Zahlen deren Differenz eine Primzahl ist und druckt es aus
void teilfolge(int v[], int n) {
    int current_len=1;
    int current_st_pos=0;
    int st_pos=-1;
    int max_len=0;
    for (int i=0; i<n-1; i++) {
        if (isprime(v[i+1]-v[i])) {
            current_len++;
        }
        else {
            if (current_len>max_len) {
                st_pos=current_st_pos;
                max_len=current_len;
            }
            current_len=1;
            current_st_pos=i+1;
        }
    }
    if (current_len>max_len) {
        st_pos=current_st_pos;
        max_len=current_len;
    }
    // int* myarray = new int [n];
    // for (int i=0; i<max_len; i++) {
    //     myarray[i]=v[st_pos+i];
    // }
    print_array(v, st_pos, st_pos+max_len-1);
    // delete[] myarray;

}

void point_a() {
    std::cout<<"enter number to aproximate\n";
    float n;
    std::cin>>n;
    std::cout<<wurzel(n)<<'\n';
}

void point_b() {
    int len;
    std::cout<<"enter array length\n";
    std::cin>>len;
    int* vec = new int[len];
    for (int i=0; i<len; i++) {
        std::cin>>vec[i];
    }
    teilfolge(vec, len);
    delete[] vec;
}
int main() {
    point_a();
    point_b();
}