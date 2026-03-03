#include <iostream>

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

//Funktion generiert die ersten n Primzahlen
void generate_prime(int n) {
    int i=2;
    while (n>0) {
        if (isprime(i)) {
            std::cout<<i<<" ";
            i++;
            n--;
        }
        else {
            i++;
        }
    }
    std::cout<<"\n";
}



// bool relativ_prime(int a, int b) {
//     for (int i=2; i<=a && i<=b; i++) {
//         if (a%i==0 && b%i==0) {
//             return false;
//         }
//     }
//     return true;
// }

//falls ggT(en: gcd)=1, dann sind die Zahlen relativ prim
int gcd(int a, int b) {
    while (b) {
        int remainder = a%b;
        a = b;
        b = remainder;
    }
    return a;
}

//Funkton druckt den Elementen von st bis fin einer array
void print_array(int v[], int st, int fin) {
    while (st<=fin) {
        std::cout<<v[st]<<" ";
        st++;
    }
    std::cout<<"\n";
}

//Funktion bestimmt die langste Teilfolge von aufeinanderfolgende Zahlen die relativ Prim sind und druckt es aus
void teilfolge(int v[], int n){
    int current_len=1;
    int current_st_pos=0;
    int st_pos=-1;
    int max_len=0;
    for (int i=0; i<n-1; i++) {
        if (gcd(v[i+1],v[i]) == 1) {
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
    int n;
    std::cout<<"enter number n\n";
    std::cin>>n;
    generate_prime(n);
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

int main(){
    point_a();
    point_b();
}