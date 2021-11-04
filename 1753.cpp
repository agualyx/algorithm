#include <iostream>
using namespace std;
int minStep = 100;
int step = 0;
bool b[4];
char chessBox[4][4];
void filp(char temp[4][4], int i, int j)
{
    if (temp[i][j] == 'b')
    {
        temp[i][j] = 'w';
    }
    else
    {
        temp[i][j] = 'b';
    }
}
bool judge(char s[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (s[i][j] != s[0][0])
            {
                return false;
            }
        }
    }
    return true;
}
bool judgeRow(char s[4],char flag){
    for(int i=0;i<4;i++){
        if(s[i]!=flag){
            return false;
        }
    }
    return true;
}
void filpStep(char flag)
{
    step=0;
    char temp[4][4];
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            temp[i][j] = chessBox[i][j];
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if (b[i])
        {
            step++;
            filp(temp, 0, i);
            if (i > 0)
                filp(temp, 0, i - 1);
            if (i < 3)
                filp(temp, 0, i + 1);
            filp(temp, 1, i);
        }
    }
    // 根据上一行来判断下一行是否翻转
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            
            if (temp[i - 1][j] != flag)
            {
                step++;
                temp[i - 1][j] = flag;
                filp(temp, i, j);
                if (j > 0)
                    filp(temp, i, j-1);
                if (j < 3)
                    filp(temp, i, j+1);
                if (i < 3)
                    filp(temp, i+1, j);
            }
        }
    }
    if(judgeRow(temp[3],flag)&&step<minStep){
        minStep=step;
    }
}
void enumerate(int count){
    if(count==4){
        filpStep('w');
        filpStep('b');
    }else{
        b[count]=true;
        enumerate(count+1);
        b[count]=false;
        enumerate(count+1);
    }
}
int main()
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>chessBox[i][j];
        }
    }
    if(judge(chessBox)){
        cout<<0<<endl;
    }else{
        enumerate(0);
        if(minStep!=100){
            cout<<minStep<<endl;
        }else{
            cout<<"Impossible"<<endl;
        }
    }
    return 0;
}