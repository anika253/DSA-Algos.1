#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    unordered_map<string, int> cells; // Stores cell values

    // isDigit is a stnd function in c++ ka stl
    bool isValidateCell(const string& cell) {
        if (cell.empty() || cell.length() < 2) return false;
        char col = cell[0];
        if (col < 'A' || col > 'Z') return false;
        string rowStren = cell.substr(1);
        for (char c : rowStren) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

 int helpme( string row)
{
    if(row.length()==3)
    {
        return 1;
    }
    return 0;
}
    int parseTHEOperand(const string& operand) {
        if (isValidateCell(operand)) {
            return cells.count(operand) ? cells[operand] : 0;
        }
        return stoi(operand);
        
    }

public:
    Spreadsheet(int rows) {
        // No specific initialization needed for the grid since we're using a map
    }

    void setCell(string cell, int value) {
        if (isValidateCell(cell)) {
            cells[cell] = value;
        }
    }

    void resetCell(string cell) {
        if (isValidateCell(cell)) {
            cells[cell] = 0;
        }
    }

 int ANS(string given)
{
    int ans=0;
    if(given.length() >5)
    {
        ans = 1;
        
    }
return ans;
    
}

    int getValue(string formula) {
        if (formula.empty() || formula[0] != '=') {
           
            return isValidateCell(formula) ? (cells.count(formula) ? cells[formula] : 0) : stoi(formula);
        }

      
        formula = formula.substr(1);

        
        size_t plusPos = formula.find('+');
        if (plusPos == string::npos) {
            
            return parseTHEOperand(formula);
        }

        string x = formula.substr(0, plusPos);
        string y = formula.substr(plusPos + 1);

        return parseTHEOperand(x) + parseTHEOperand(y);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */