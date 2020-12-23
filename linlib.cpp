#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> mat;

mat random_mat(int n, int m){
    mat rand_mat(n,vl(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            rand_mat[i][j]=rand();
            if(rand()%2==0)
                rand_mat[i][j]*=-1;
        }
    }
    return rand_mat;
}

mat random_mat(int n, int m, int b){
    mat rand_mat(n,vl(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            rand_mat[i][j]=rand()%b;
            if(rand()%2==0)
                rand_mat[i][j]*=-1;
        }
    }
    return rand_mat;
}

vl sum_vecs(vl v1, vl v2){
    int length = v1.size();
    if(length!=v2.size())
        throw "Summing unequally sized vectors";

    vl retv(length);
    for(int i  = 0; i < length; i++){
        retv[i]=v1[i]+v2[i];
    }
    return retv;
}

ll dot_prod(vl v1, vl v2){
    int length = v1.size();
    if(length!=v2.size())
        throw "Dot-producting unequally sized vectors";

    ll sum = 0;
    for(int i  = 0; i < length; i++){
        sum+=v1[i]*v2[i];
    }
    return sum;
}

vl mat_times_vector(mat m, vl v){
    int length = v.size();
    if(v.size()!=m[0].size())
        throw "Multiplying matrix and vector with mismatched dimensions";
    
    vl retv(length);
    for(int i = 0; i < length; i++){
        retv[i]=dot_prod(m[i],v);
    }
    return retv;
}

void print_mat(mat m){
    int length = m.size();
    for(int i = 0; i < length; i++){
        if(i==0)
            cout << "⌈ ";
        else if (i==length-1)
            cout << "⌊ ";
        else
            cout << "| ";

        for(ll j: m[i]){
            cout << j << " ";
        }

        if(i==0)
            cout << "⌉";
        else if (i==length-1)
            cout << "⌋";
        else
            cout << "|";

        cout << endl;
    }
}

void print_mat(vl v){
    int length = v.size();
    for(int i = 0; i < length; i++){
        if(i==0)
            cout << "⌈ " << v[i] << " ⌉" << endl;
        else if (i==length-1)
            cout << "⌊ " << v[i] << " ⌋" << endl;
        else
            cout << "| " << v[i] << " |" << endl;
    }
}


