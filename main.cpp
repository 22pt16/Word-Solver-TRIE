#include <iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    bool flag=false;
    Node* links[26];
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch,Node* temp)
    {
        links[ch-'a']=temp;
    }
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
};

class Trie
{
    public: Node* root;
    Trie()
    {
        root=new Node();
    }

    void insert(string s)
    {
        Node* temp=root;
        for(int i=0;i<s.length();i++)
        {
            if(!temp->containsKey(s[i]))
                temp->put(s[i],new Node());
            temp=temp->get(s[i]);
        }
        temp->flag=true;
    }

   void search(vector<vector<char> >&board, Node* temp,int i,int j,vector<string>&ans,string s)
    {
        //temp is the current node in the trie.
        // (i,j) is the current cell in the grid.
        if(i<0 || j<0 || i==board.size() || j==board[0].size() || !temp || board[i][j]=='*' || !temp->containsKey(board[i][j]))
            return;
        s+=board[i][j];
        Node* t=temp->get(board[i][j]);
        if(t->flag)
        {
            ans.push_back(s);
            t->flag=false;
        }
        char ch=board[i][j];
        board[i][j] = '*'; //preventing this from getting reconsidered in same word
        search(board,temp->get(ch),i+1,j,ans,s); //bottom cell
        search(board,temp->get(ch),i,j+1,ans,s); //right cell
        search(board,temp->get(ch),i-1,j,ans,s); // top cell
        search(board,temp->get(ch),i,j-1,ans,s); //left cell

        search(board,temp->get(ch),i-1,j-1,ans,s); // top-left diagonal
        search(board,temp->get(ch),i-1,j+1,ans,s); // top-right diagonal
        search(board,temp->get(ch),i+1,j-1,ans,s); // bottom-left diagonal
        search(board,temp->get(ch),i+1,j+1,ans,s); // bottom-right diagonal
        board[i][j]=ch; //restoring original character
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words)
    {
        Trie trie;
        for(string s:words) trie.insert(s);
             vector<string> ans;

        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                trie.search(board,trie.root,i,j,ans,"");
        return ans;
    }

};

vector<vector<char> >get()
{

    int numRows=6, numCols=10;

    vector<vector<char> >board(numRows, vector<char>(numCols));

    cout<<"\n=>Enter the elements for each column with length "<<numCols<<endl;
    for (int i = 0; i < numRows; ++i) {
        string rowInput;
        cout << "\n\tEnter characters for row as STRING " << i + 1 << ": ";
        cin >>rowInput;

        for (int j = 0; j < numCols; ++j)
        {
            board[i][j] = rowInput[j];
        }
    }


return board;
}

int main()
{
    int i;
    char c = 'y';
    vector<vector<char> >board;
    cout<<setfill(' ')<<setw(60);
    cout<<"\tWelcome to WORD SOLVER"<<endl;
    cout<<setfill(' ')<<setw(60);
    cout<<"\t\tWe make Cross-word easier!!\n";

    //sleep(3)
    /*-------instruction------------------------------------------------*/
    cout<<endl<<setfill(' ')<<setw(60);
    cout<<setfill('-')<<setw(100)<<'-'<<endl;
    cout << "\nINSTRUCTIONS:\n";
    cout << "1. The number of rows is 6 \n";
    cout << "2. The number of columns is 10\n";
    cout << "3. Enter characters for each column (length should at-most match the number of columns).\n";
    cout << "4. The Genre of words you would find from the crossword will be displayed\n";
    cout << "5. Program will display the words found in the crossword.\n";
    cout << "6. You can retry with a different 6x10 grid or exit the program.\n";
    cout<<endl<<setfill(' ')<<setw(60);
    cout<<setfill('-')<<setw(100)<<'-'<<endl;
    cout<<"\nPress 'y' to ENTER and continue\t:";
    cin>>c;
    /*-------------------------------------------------------*/
system("cls");

    while(c=='y' || c=='Y')
    {

        cout<<endl<<setfill(' ')<<setw(60);
        cout<<setfill('-')<<setw(100)<<'-'<<endl;
        cout<<endl<<endl<<"The genre of words that can be found  from the crossword:\n";
        cout<<"\t1.Computer components\n\t2.Computer terminology\n\t3.Communication terms\n\t4.Default-English Articles\n";
        cout<<endl<<setfill(' ')<<setw(60);
        cout<<setfill('-')<<setw(100)<<'-'<<endl;

        board=get();
        vector<string> words = {"a", "about", "after", "all", "also", "an", "and", "another", "any", "are", "as", "at","be", "because", "been", "before", "being", "between", "both","but", "by","came", "can", "come", "could","did", "do","each", "even","for", "from", "further", "furthermore","get", "got","had", "has", "have", "he", "her", "here", "hi", "him", "himself", "his", "how", "however","i", "if", "in", "indeed", "into", "is", "it", "its","just","like","made", "many", "me", "might", "more", "moreover", "most", "much", "must", "my","never", "not", "now","of", "on", "only", "or", "other", "our", "out", "over","said", "same", "see", "she", "should", "since", "some", "still", "such","take", "than", "that", "the", "their", "them", "then"," there", "therefore", "these", "they", "this", "those", "through", "thus", "to", "too","under", "up","very","was", "way", "we", "well"," were", "what", "when", "where", "which"," while", "who", "will"," with", "would","you", "your"};
        vector<string> genre_1 = {"mouse","system","keyboard","transformer","adapter","battery","cpu","harddisk","hardware","pendrive","encode","decode","motherboard","network","modem","bluetooth","speaker","printer","cloud"};
        vector<string> genre_2 = {"intel","input","debug","email","excel","complier","proxy","ascii","click","panel","stack","queue","reset","restart","virus","directory","database","output","input","server","memory","binary","data"};
        vector<string> genre_3 = {"radio","email","telegram","messenger","facebook","gmail","contact","telephone","receive","send","news","offline","online","connect","channel","visual", "media"};

        vector<string> result;
cout<<"\nPress 'y' to ENTER and continue\t:";
cin>>c;
system("cls");
         // Display the board (optional)

            cout<<endl<<"\tThe Entered WORD SOLVER grid is:"<<endl;

            for (const vector<char>& row : board)
            {
                cout<<"\t\t| ";
                for (char cell : row)
                {
                    cout << cell << " | ";
                }
                cout << endl;
            }
       //----------------------------------------1-----------------------------------------------------------------
            cout << std::setfill( '*' ) << setw( 100 ) << '*' <<  endl;
            cout<<"\n\tGENRE 1: Computer Components \n";
            cout<<"\nThis Genre finds and displays all the components of computer like 'mouse','cpu','monitor' and so on\n\n";
           // cout << std::setfill( '*' ) << setw( 100 ) << '*' <<  endl;

            result= solution.findWords(board, genre_1);
            cout<<"\nThe words found are: "<<endl;
            if(result.empty())
            cout<<"\tNO WORDS FOUND IN THIS GENRE "<<endl;
            else
            {
           //     cout << std::setfill( '*' ) << setw( 100 ) << '*' <<  endl;
                for(const string& word : result)
                {
                    cout << "\t*"<<std::left << setfill(' ' )<< setw( 100 - 2 )<<word << std::endl;
                }
              //  cout << std::setfill( '-' ) << setw( 100 ) << '*' <<  endl;

            }
    //----------------------------------------2-----------------------------------------------------------------
            cout << std::setfill( '*' ) << setw( 100 ) << '*' <<  endl;
            cout<<"\n\tGENRE 2: Computer Terminology \n";
            cout<<"\nThis Genre finds and displays the terms related to computer like 'input,'output','email' and so on\n\n";
            //cout << std::setfill( '*' ) << setw( 100 ) << '*' <<  endl;

            result = solution.findWords(board, genre_2);
            cout<<"\nThe words found are: "<<endl;
            if(result.empty())
                cout<<"\tNO WORDS FOUND IN THIS GENRE "<<endl;
            else
            {
              //  cout << std::setfill( '*' ) << setw( 100 ) << '*' <<  endl;
                for(const string& word : result)
                {
                    cout << "\t*"<<std::left << setfill(' ' )<< setw( 100 - 2 )<<word << std::endl;
                }
                //cout << std::setfill( '-' ) << setw( 100 ) << '*' <<  endl;
            }
            //----------------------------------------3-----------------------------------------------------------------
            cout << std::setfill( '*' ) << setw( 100 ) << '*' <<  endl;
            cout<<"\n\tGENRE 3: Communication Terminology \n";
            cout<<"\nThis Genre finds and displays the terms related to Communication like 'send' ,'recieve','facebook' and so on\n\n";
          //  cout << std::setfill( '*' ) << setw( 100 ) << '*' <<  endl;

            result = solution.findWords(board, genre_3);
            cout<<"\nThe words found are: "<<endl;
            if(result.empty())
                cout<<"\tNO WORDS FOUND IN THIS GENRE "<<endl;
            else
            {
            //    cout << std::setfill( '*' ) << setw( 100 ) << '*' <<  endl;
                for(const string& word : result)
                {
                    cout << "\t*"<<std::left << setfill(' ' )<< setw( 100 - 2 )<<word << std::endl;
                }
               // cout << std::setfill( '-' ) << setw( 100 ) << '*' <<  endl;
             }
           //----------------------------------------4-----------------------------------------------------------------
            cout << std::setfill( '*' ) << setw( 100 ) << '*' <<  endl;
            cout<<"\n\tGENRE 4: Default-English Articles \n";
            cout<<"\nThis Genre finds and displays the General English articles  like 'a','an','the','where','when' and so on\n\n";
          //  cout << std::setfill( '*' ) << setw( 100 ) << '*' <<  endl;

            result = solution.findWords(board, words);
            cout<<"\nThe words found are: "<<endl;
            if(result.empty())
                cout<<"\tNO WORDS FOUND IN THIS GENRE "<<endl;
            else
            {
              //  cout << std::setfill( '*' ) << setw( 100 ) << '*' <<  endl;
                for(const string& word : result)
                {
                    cout << "\t*"<<std::left << setfill(' ' )<< setw( 100 - 2 )<<word << std::endl;
                }
               // cout << std::setfill( '-' ) << setw( 100 ) << '*' <<  endl;
             }
    cout << std::setfill( '*' ) << setw( 100 ) << '*' <<  endl;
      //  vector<string> result = solution.findWords(board, words);
        // Display the found words



        cout<<endl<<"Do you wish to re-try ?(n/y) :";
        cin>>c;
        system("cls");
    }
    cout<<"\n\tProgram is Exiting...\n\tTHANK YOU";
    return 0;
}


