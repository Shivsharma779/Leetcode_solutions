/*
NOT VERIFIED
*/

class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<char> board;
    bool xturn,gameended;
    int count = 9;

    TicTacToe() {
        board = vector<char>(3,vecotr<char>(3,'_'));
        xturn = true, gameended=false, count=9;
    }
    bool move(int row, int col) {
        if(gameended)
            return "gameended";

        //already taken
        if(board[row][col] != '_')
        {
            //except
            return "invalid move";
        }

        if(xturn)   board[row][col] = 'x';
        else        board[row][col] = 'o';

        bool win = true;
        char player = (xturn) ? 'x' : 'o';

        //row chk
        for(int j=0;j<3;j++)
        {
            if(board[row][j]!=player)
            {
                win = false;
                return "continue";
            }   
        }

        if(win) return player + " won";
        else    win=true;

        //col chk
        for(int i=0;i<3;i++)
        {
            if(board[row][j]!=player)
            {
                win = false;
                return "continue";
            }   
        }

        if(win) return player + " won";
        else    win=true;

        //left diag
        for(int i=0;i<3;i++)
        {
            if(board[i][i]!=player)
            {
                win = false;
                return "continue";
            }   
        }

        if(win) return player + " won";
        else    win=true;

        //right diag
        for(int i=0;i<3;i++)
        {
            if(board[i][2-i]!=player)
            {
                win = false;
                return "continue";
            }   
        }

        if(win) return player + " won";
        else    win=true;   

        count--;
        if(count==0){
            gameended=true;
            return "draw";
        }

        xturn ^= 1;
    }
};

/*
x - -
0 x -
0 - x
*/
