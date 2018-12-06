/*
 * Program 4: ACM Challenge Problem
 * Name: Ross Kaplan
 * Professor: Carl Sable
 * Goal: Implement a dynamic programming solution to a previously exponential problem.  Using a large 1001*1001 matrix, check whether two strings are a "valid merge" of one another, where the letters of one can be removed from the concatenated string to leave a proper second string.
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool Matrix[1001][1001];

bool isMerge(string string1, string string2, string &string3);

int main() {
    
    string infile, outfile, string1, string2, string3; 
    cout << "Please enter an input file: " << endl;   
    cin >> infile;
    
    cout << "Please enter an output file: " << endl;
    cin >> outfile;

    ifstream input(infile.c_str());
    ofstream output(outfile.c_str());
    if (input.is_open()) {
        while (input >> string1 >> string2 >>string3) {
            if (output.is_open()) {
                if (isMerge(string1, string2, string3))
                    output << string3 << endl;
                else
                    output << "*** NOT A MERGE ***" << endl;
            }
        }
    }        
    input.close();
    output.close();
    return 0;

}
bool isMerge(string string1, string string2, string &string3) {

    if (string1.size() + string2.size() != string3.size())
        return 0;

    for (int i=0; i<string1.size(); i++){
        if(string1[i]==string3[i])
            Matrix[0][i+1]=1;
        else{ 
            while (i < string1.size())
                Matrix[0][(i++)+1]=0;
            break;
        }
    }       
    for (int i=0;i<string2.size();i++){
        if (string2[i]==string3[i])
            Matrix[i+1][0]=1;
        else{
            while(i < string2.size())
                Matrix[(i++)+1][0]=0;
            break;
        }
    }

    for(int i=1;i<=string2.size();i++){
        for(int j=1;j<=string1.size();j++){
            Matrix[i][j]=(((string3[i+j-1]==string1[j-1])&& (Matrix[i][j-1])) || ((string3[i+j-1]==string2[i-1])&& (Matrix[i-1][j]))); //Algorithm as described in class
        }
    }

    if (Matrix[string2.size()][string1.size()] == 0)
        return 0; //Check if last bit is true

    int j=string1.size();
    int i=string2.size();
    while(i+j > 0) {
        if (i > 0 && Matrix[i-1][j] > 0) //If still matrix dimensions are defined and can move left
            --i; //No uppercase of string2 words
        else if (j > 0 && Matrix[i][j-1] > 0)
            string3[--j+i]-=32; //Uppercase this letter
        else
            break;
    }

    while(j)
        string3[--j]-=32; //All remaining characters are 

    return 1;

}
