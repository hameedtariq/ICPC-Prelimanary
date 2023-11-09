#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Customer {
    int x;
    int y;
    int pos;

    Customer(int x, int y, int pos){
        this->x = x;
        this->y = y;
        this->pos = pos;
    }
};

int main(){
    int N,D;
    cin >> N;
    cin >> D;
    int A,B;
    cin >> A;
    cin >> B;

    int happyCustomers = 0;

    vector<Customer> customers;

    for(int i =0; i<N; i++){
        int x,y;
        cin >> x;
        cin >> y;
        customers.push_back(Customer(x,y,i+1));
    }

    sort(customers.begin(), customers.end(), [A,B](const Customer& a, const Customer& b){
        return (a.x*A +a.y*B < b.x*A + b.y*B);
    });

    int i = 0;
    vector<int> happy;
    while(D>0 && i<N){
        if(customers[i].x*A + customers[i].y*B <= D){
            D -= customers[i].x*A + customers[i].y*B;
            happyCustomers++;
            happy.push_back(customers[i].pos);
        }
        i++;
    }

    cout << happyCustomers << endl;
    for(int i = 0; i<happy.size(); i++){
        cout << happy[i] << " ";
    }

    return 0;
}