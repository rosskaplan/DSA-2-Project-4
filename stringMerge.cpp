#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isMerge(string string1, string string2, string &string3);

int main () {
    
    string infile, outfile;
    string string1, string2, string3; 
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
                    output << << string3 << endl;
                else
                    output << "*** NOT A MERGE ***" << endl;
            }
        }
    }        
    input.close();
    return 0;

}
bool isMerge(string string1, string string2, string &string3) {

    if (string1.size() + string2.size() != string3.size())
        return false;
    return true;

}
