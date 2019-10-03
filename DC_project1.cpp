#include <iostream>
#include <fstream>
using namespace std;

// gobal variable
int m, n;
int map[20][41] = {0};

int block_T1[4][3] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0};                  // num = 1
int block_T2[4][3] = {0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0};                  // num = 2
int block_T3[4][3] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1};                  // num = 3
int block_T4[4][3] = {0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0};                  // num = 4
int block_L1[4][3] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0};                  // num = 5
int block_L2[4][3] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0};                  // num = 6
int block_L3[4][3] = {0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0};                  // num = 7
int block_L4[4][3] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1};                  // num = 8
int block_J1[4][3] = {0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0};                  // num = 9
int block_J2[4][3] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1};                  // num = 10
int block_J3[4][3] = {0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0};                  // num = 11
int block_J4[4][3] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1};                  // num = 12
int block_S1[4][3] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0};                  // num = 13
int block_S2[4][3] = {0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0};                  // num = 14
int block_Z1[4][3] = {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1};                  // num = 15
int block_Z2[4][3] = {0 ,0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0};                  // num = 16
int block_I1[4][4] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0};      // num = 17
int block_I2[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1};      // num = 18
int block_O [4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0};      // num = 19

class Block
{
private:
    /* data */
    int col; // which col falling down 

public:
    int** block_type;
    void display(){
        if (sizeof(block_type) == 12) {
            for (int i=0; i<4; i++){
                for(int j=0; j<3; j++){
                    cout << block_type[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            for (int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    cout << block_type[i][j] << " ";
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    Block(int num, int col){
        this->col = col;
        if (num == 1) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_T1[i][j];
                }
            }
        }
        else if (num == 2) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_T2[i][j];
                }
            }
        }
        else if (num == 3) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_T3[i][j];
                }
            }
        }
        else if (num == 4) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_T4[i][j];
                }
            }
        }
        else if (num == 5) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_L1[i][j];
                }
            }
        }
        else if (num == 6) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_L2[i][j];
                }
            }
        }
        else if (num == 7) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_L3[i][j];
                }
            }
        }
        else if (num == 8) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_L4[i][j];
                }
            }
        }
        else if (num == 9) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_J1[i][j];
                }
            }
        }
        else if (num == 10) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_J2[i][j];
                }
            }
        }
        else if (num == 11) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_J3[i][j];
                }
            }
        }
        else if (num == 12) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_J4[i][j];
                }
            }
        }
        else if (num == 13) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_S1[i][j];
                }
            }  
        }
        else if (num == 14) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_S2[i][j];
                }
            }
        }
        else if (num == 15) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_Z1[i][j];
                }
            }
        }
        else if (num == 16) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[3];
                for (int j=0; j<3; j++){
                    block_type[i][j] = block_Z2[i][j];
                }
            }
        }
        else if (num == 17) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[4];
                for (int j=0; j<4; j++){
                    block_type[i][j] = block_I1[i][j];
                }
            }
        }
        else if (num == 18) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[4];
                for (int j=0; j<4; j++){
                    block_type[i][j] = block_I2[i][j];
                }
            }
        }
        else if (num == 19) {
            block_type = new int *[4];
            for (int i=0; i<4; i++){
                block_type[i] = new int[4];
                for (int j=0; j<4; j++){
                    block_type[i][j] = block_O[i][j];
                }
            }
        }
    }

    ~Block();
};


Block::~Block()
{
    for (int i=0; i<4; i++) delete [] block_type[i];
    delete [] block_type;
}

class dot
{
public:
    int i, j, live;
    dot(int row, int col, int live);
};

dot::dot(int row, int col, int live)
{
    i = row;
    j = col;
    this->live = live;
}

int update_map(int num, int** piece, int col){
    // check legal or not
    if (num > 0 && num <17) {
        for (int i=0; i<4; i++) {
            for (int j=0; j<3; j++) {
                if (piece[i][j] == 1) {
                    if ((j+col) > n) return 0;  // error : over bounded
                }
            }
        }
    } else {
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                if (piece[i][j] == 1) {
                    if ((j+col) > n) return 0;  // error : over bounded
                }
            }
        }
    }
    
    // put a piece into the top of map

    if (num == 1) { // T1
        map[3][col] = 1;
        dot a(3, col, 1);

        map[3][col+1] = 1;
        dot b(3, col+1, 1);

        map[3][col+2] = 1;
        dot c(3, col+2, 1);

        map[4][col+1] = 1;
        dot d(4, col+1, 1);

        // falling down
        int stop = 0;
        while(!stop){
            if ( (d.i+1) > (m+4) ) stop = 1;
            else if (a.live == 1 && b.live == 1 && c.live == 1 && d.live == 1 && (d.i+1) <= (m+4) ){ // T1丁字型
                if (map[d.i+1][d.j] == 0 && map[a.i+1][a.j] == 0 && map[c.i+1][c.j] == 0) { // Ｔ１只要判斷ａ,ｄ,ｃ下面有沒有方塊就好
                    // a
                    map[a.i][a.j] = 0;
                    a.i++;
                    map[a.i][a.j] = 1;
                    // b
                    map[b.i][b.j] = 0;
                    b.i++;
                    // c
                    map[c.i][c.j] = 0;
                    c.i++;
                    map[c.i][c.j] = 1;
                    // d
                    d.i++;
                    map[d.i][d.j] = 1;
                }
                else stop = 1;
            }
        }
        //看是否可以消除
        int clear = 1;
        for (int j=1; j<=n; j++) {
            if (map[d.i][j] == 0) clear = 0;
        }
        if (clear) {
            d.live = 0;
            for (int j=1; j<=n; j++) { // clear row --> d.i
                map[d.i][j] = 0;
            }

            for (int i = d.i-1; i>4; i--) { // 上面全部都往下移
                for (int j=1; j<=n; j++) {
                    map[i+1][j] = map[i][j];
                    map[i][j] = 0;
                }
            }
            a.i++; b.i++; c.i++;
        }
        // 判斷ａｂｃ那行可不可消
        clear = 1;
        for (int j=1; j<=n; j++) {
            if (map[a.i][j] == 0) clear = 0;
        }            
        if (clear) {
            for (int j=1; j<=n; j++) {
                map[a.i][j] = 0;
            }

            for (int i = a.i-1; i>4; i--) {
                for (int j=1; j<=n; j++) {
                    map[i+1][j] = map[i][j];
                    map[i][j] = 0;
                }
            }
        }
        //判斷是不是輸掉 看上面那塊區域還有沒有1
        for(int i=1; i<5; i++) {
            for (int j=1; j<=n; j++) {
                if(map[i][j]==1) return 1;
            }
        }         
        return 0; /// done!!!!
    }
    else if (num == 2) { // T2

    }
    else if (num == 3) { // T3

    }
    return 0;

}


int main(){
    int start_col, num;
    string type_name;
    cin >> m >> n;

    while(1){
        // input block
        cin >> type_name;
        if (type_name == "End")
            break;

        cin >> start_col;
        if (type_name == "T1")
            num = 1;
        else if (type_name == "T2")
            num = 2;
        else if (type_name == "T3")
            num = 3;
        else if (type_name == "T4")
            num = 4;
        else if (type_name == "L1")
            num = 5;
        else if (type_name == "L2")
            num = 6;
        else if (type_name == "L3")
            num = 7;
        else if (type_name == "L4")
            num = 8;
        else if (type_name == "J1")
            num = 9;
        else if (type_name == "J2")
            num = 10;
        else if (type_name == "J3")
            num = 11;
        else if (type_name == "J4")
            num = 12;
        else if (type_name == "S1")
            num = 13;
        else if (type_name == "S2")
            num = 14;
        else if (type_name == "Z1")
            num = 15;
        else if (type_name == "Z2")
            num = 16;
        else if (type_name == "I1")
            num = 17;
        else if (type_name == "I2")
            num = 18;
        else if (type_name == "O")
            num = 19;

        Block b(num, start_col);

        // debug : display
        //b.display();


        // update map
        int gameover = update_map(num, b.block_type, start_col);

        // debug : display map
        for (int i=5; i<=m+4; i++) {
            for (int j=1; j<=n; j++) {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }

        // game over
        if (gameover) {
            cout << "Game Over!" << endl;
            break;
        }

    }
}