#include "iostream"
#include "string"
#include "vector"
#include "tuple"

using namespace std;

int N, S;
vector<tuple<int, int, bool>> ball;
int a = 0;

void dfs(int pos, int speed, char direct){
    a++;
    if((direct == 'r' && pos > N - 1) || (direct == 'l' && pos < 0) || a > 3 * N){
        return;
    }
    if(get<0>(ball[pos]) == 0 && direct == 'r'){
        dfs(pos - speed - get<1>(ball[pos]), speed + get<1>(ball[pos]), 'l');
    }
    else if (get<0>(ball[pos]) == 0 && direct == 'l'){
        dfs(pos + speed + get<1>(ball[pos]), speed + get<1>(ball[pos]), 'r');
    }
    else if(get<0>(ball[pos]) == 1 && speed >= get<1>(ball[pos]) && direct == 'r'){
        get<2>(ball[pos]) = true;
        dfs(pos + speed, speed, direct);
    }
    else if(get<0>(ball[pos]) == 1 && speed >= get<1>(ball[pos]) && direct == 'l'){
        get<2>(ball[pos]) = true;
        dfs(pos - speed, speed, direct);
    }
    else if(get<0>(ball[pos]) == 1 && speed < get<1>(ball[pos]) && direct == 'r'){
        dfs(pos + speed, speed, direct);
    }
    else if(get<0>(ball[pos]) == 1 && speed < get<1>(ball[pos]) && direct == 'l'){
        dfs(pos - speed, speed, direct);
    }
}

int main(){
    cin >> N >> S;
    ball.resize(N);
    for(auto &i : ball){
        cin >> get<0>(i) >> get<1>(i);
    }
    dfs(S - 1, 1, 'r');
    int ans = 0;
    for(auto &i : ball){
        if(get<0>(i) == 1 && get<2>(i))
            ans++;
    }
    cout << ans << endl;
    return 0;
}