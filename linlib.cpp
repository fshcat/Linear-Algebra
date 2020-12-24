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
            rand_mat[i][j]=(rand() % (2*b+1))-b;
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

vl const_times_mat(int c, vl v){
    for(ll &i: v){
        i*=c;
    }
    return v;
}

mat const_times_mat(int c, mat m){
    for(vl &v: m){
        v=const_times_mat(c,v);
    }
    return m;
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

mat mat_times_mat(mat m1, mat m2){
    int height = m1.size();
    int width = m2[0].size();
    int length = m2.size();

    if(length!=m1[0].size()){
        throw "Multiplying matrices with mismatched dimensions";
    }

    mat ret_m(height,vl(width));
    for(int i = 0; i < height; i++){
        vl sum_row(width,0);
        for(int j = 0; j < length; j++){
            sum_row = sum_vecs(sum_row,const_times_mat(m1[i][j],m2[j]));
        }
        ret_m[i]=sum_row;
    }
    return ret_m;
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


