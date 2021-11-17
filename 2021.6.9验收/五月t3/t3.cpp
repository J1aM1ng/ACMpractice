#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const string NULLSTR = "null";
const string ENTER = "\n";
const string SPACE = " ";
vector<string> line;     //lines of the file
vector<string> pasteBin; //lines of pasteBin
vector<string> selBin;   //lines of selection
struct pos
{
    int row = 1, col = 1;
    bool operator<(const pos &pp) const
    {
        if (row == pp.row)
            return col < pp.col;
        return row < pp.row;
    }
    bool operator==(const pos &pp) const
    {
        return (row == pp.row) && (col == pp.col);
    }
    pos(int r, int c) : row(r), col(c) {}
    pos() { row = col = 1; }
};
pos _2021531_cursor;      //position of the _2021531_cursor 0=row,1=column,element=1,2,...
bool shifted = false;     //shift enabled or not.
bool inSelection = false; //selection mode enabled or not.
pos remPoint;             //remPoint for selection. (Just a copy of the _2021531_cursor there.)
pos selection[2];         //selection area.
int _2021531_getSpeciLineIndex(const pos &p) { return p.row - 1; }
int getSpeciCharIndex(const pos &p) { return p.col - 2; }
int getSpeciLineFullLength(const pos &p) { return line[_2021531_getSpeciLineIndex(p)].length(); } //get the string length of current line.
int getSpeciLineVisLength(const pos &p)
{
    if (*(line[_2021531_getSpeciLineIndex(p)].rbegin()) == '\n')
        return line[_2021531_getSpeciLineIndex(p)].length() - 1;
    return getSpeciLineFullLength(p);
}
string getSpeci_2021531_cursorLeftSub(const pos &p) { return line[_2021531_getSpeciLineIndex(p)].substr(0, p.col - 1); } //get the substring on the left of the _2021531_cursor of the line.
string getSpeci_2021531_cursorRightSub(const pos &p) { return line[_2021531_getSpeciLineIndex(p)].substr(p.col - 1); }   //get the substring on the right of the _2021531_cursor of the line.
string getSpeciLineVisStr(const pos &p) { return line[_2021531_getSpeciLineIndex(p)].substr(0, getSpeciLineVisLength(p)); }
void theCopy(vector<string> &);
vector<string> getSelectionArea()
{ //return the range of selection. if not in selection, then  return the whole file.
    vector<string> range;
    if (inSelection)
    {
        //        pasteBinBackUp=pasteBin;
        theCopy(selBin);
        range = selBin;
        //        pasteBin=pasteBinBackUp;
    }
    else
        range = line;
    return range;
}
void move_2021531_cursor(int type)
{
    inSelection = false;
    bool moveLR = false;
    switch (type)
    {
        case 1:
            _2021531_cursor.col = 1;
            break;
        case 2:
            _2021531_cursor.col = getSpeciLineVisLength(_2021531_cursor) + 1; //moded getCurLineLength().
            break;
        case 3:
            if (_2021531_cursor.row == 1)
                return;
            moveLR = false;
            if (getSpeciLineVisLength(pos(_2021531_cursor.row - 1, _2021531_cursor.col)) < _2021531_cursor.col - 1)
                moveLR = true; //moded getCurLineLength().
            --_2021531_cursor.row;
            if (moveLR)
                move_2021531_cursor(2);
            break;
        case 4:
            if (_2021531_cursor.row == line.size())
                return;
            moveLR = false;
            if (getSpeciLineVisLength(pos(_2021531_cursor.row + 1, _2021531_cursor.col)) < _2021531_cursor.col - 1)
                moveLR = true; //moded getCurLineLength().
            ++_2021531_cursor.row;
            if (moveLR)
                move_2021531_cursor(2);
            break;
        case 5:
            if (_2021531_cursor.row == 1 && _2021531_cursor.col == 1)
                return;
            if (_2021531_cursor.col == 1)
            {
                move_2021531_cursor(3);
                move_2021531_cursor(2);
                return;
            }
            --_2021531_cursor.col;
            break;
        case 6:
            if (_2021531_cursor.row == line.size() && _2021531_cursor.col == getSpeciLineVisLength(_2021531_cursor) + 1)
                return;
            if (_2021531_cursor.col == getSpeciLineVisLength(_2021531_cursor) + 1)
            { //moded getCurLineLength().
                move_2021531_cursor(4);
                move_2021531_cursor(1);
                return;
            }
            ++_2021531_cursor.col;
            break;
        case 7:
            _2021531_cursor.col = getSpeciLineVisLength(_2021531_cursor) + 2; //moded getCurLineLength().
            break;
    }
}

void insert(int, string arg);
void createNextLineWithStr(string str)
{
    auto ins = line.begin();
    for (int i = 1; i <= _2021531_getSpeciLineIndex(_2021531_cursor); i++)
        ++ins;
    line.insert(++ins, str);
    move_2021531_cursor(4);
    move_2021531_cursor(2);
}

void theCopy(vector<string> &bin)
{
    if (inSelection)
    {
        bin.clear();
        if (selection[0].row == selection[1].row)
        {
            int leftIndex = getSpeciCharIndex(selection[0]) + 1;
            int rightIndex = getSpeciCharIndex(selection[1]);
            if (leftIndex >= 0 && rightIndex >= 0)
                bin.push_back(line[_2021531_getSpeciLineIndex(selection[1])].substr(leftIndex, rightIndex - leftIndex + 1));
        }
        else
        {
            int upCharIndex = getSpeciCharIndex(selection[0]) + 1;
            int upLineIndex = _2021531_getSpeciLineIndex(selection[0]);
            int dnCharIndex = getSpeciCharIndex(selection[1]);
            int dnLineIndex = _2021531_getSpeciLineIndex(selection[1]);
            if (upCharIndex >= 0)
                bin.push_back(line[upLineIndex].substr(upCharIndex));
            else
                bin.push_back(line[upLineIndex]);
            for (int i = upLineIndex + 1; i < dnLineIndex; i++)
            {
                string tmp = line[i];
                bin.push_back(tmp);
            }
            if (dnCharIndex >= 0)
                bin.push_back(line[dnLineIndex].substr(0, dnCharIndex + 1));
        }
        return;
    }
    else if (getSpeciLineVisLength(_2021531_cursor) != 0)
    {
        bin.clear();
        bin.push_back(getSpeciLineVisStr(_2021531_cursor));
        return;
    }
}

void theRemove(int);
void insert(int type, string arg)
{
    vector<string>::iterator ins;
    string left, right;
    if (inSelection)
    {
        if (type == 4 && pasteBin.empty())
            return;
        if (selection[1] == selection[0])
        {
            _2021531_cursor = selection[1];
            inSelection = false;
            insert(type, arg);
            return;
        }
        theRemove(1); //type can be any value.
        insert(type, arg);
        inSelection = false;
        return;
    }
    switch (type)
    {
        case 1:
            line[_2021531_getSpeciLineIndex(_2021531_cursor)] = getSpeci_2021531_cursorLeftSub(_2021531_cursor) + arg + getSpeci_2021531_cursorRightSub(_2021531_cursor);
            _2021531_cursor.col += arg.length();
            break;
        case 2:
            right = getSpeci_2021531_cursorRightSub(_2021531_cursor);
            line[_2021531_getSpeciLineIndex(_2021531_cursor)] = getSpeci_2021531_cursorLeftSub(_2021531_cursor) + ENTER;
            ins = line.begin();
            for (int i = 1; i <= _2021531_getSpeciLineIndex(_2021531_cursor); i++)
                ++ins;
            line.insert(++ins, right);
            move_2021531_cursor(4);
            move_2021531_cursor(1);
            break;
        case 3:
            line[_2021531_getSpeciLineIndex(_2021531_cursor)] = getSpeci_2021531_cursorLeftSub(_2021531_cursor) + SPACE + getSpeci_2021531_cursorRightSub(_2021531_cursor);
            ++_2021531_cursor.col;
            break;
        case 4:
            if (pasteBin.empty())
                return;
            right = getSpeci_2021531_cursorRightSub(_2021531_cursor);
            if (pasteBin.size() == 1 && *(pasteBin[0].rbegin()) != '\n')
            {
                line[_2021531_getSpeciLineIndex(_2021531_cursor)] = getSpeci_2021531_cursorLeftSub(_2021531_cursor) + pasteBin[0] + right;
                for (int i = 0; i < pasteBin[0].size(); i++)
                    move_2021531_cursor(6);
            }
            else
            {
                int curLine = -1;
                line[_2021531_getSpeciLineIndex(_2021531_cursor)] = getSpeci_2021531_cursorLeftSub(_2021531_cursor) + pasteBin[++curLine];
                for (int i = 1; i < pasteBin.size() - 1; i++)
                    createNextLineWithStr(pasteBin[++curLine]);
                if (*(pasteBin[pasteBin.size() - 1].rbegin()) != '\n')
                {
                    if (curLine + 1 <= pasteBin.size() - 1)
                        createNextLineWithStr(pasteBin[pasteBin.size() - 1] + right);
                    move_2021531_cursor(1);
                    for (int i = 0; i < pasteBin[pasteBin.size() - 1].size(); i++)
                        move_2021531_cursor(6);
                }
                else
                {
                    if (curLine + 1 <= pasteBin.size() - 1)
                        createNextLineWithStr(pasteBin[pasteBin.size() - 1]);
                    createNextLineWithStr(right);
                    move_2021531_cursor(1);
                }
            }
            break;
    }
}

void theRemove(int type)
{
    vector<string>::iterator ins;
    string left, right;
    if (inSelection)
    {
        theCopy(selBin);
        left = getSpeci_2021531_cursorLeftSub(selection[0]);
        right = getSpeci_2021531_cursorRightSub(selection[1]);
        _2021531_cursor = selection[0];
        line[_2021531_getSpeciLineIndex(selection[0])] = left + right;
        int firstDelLineIndex;
        firstDelLineIndex = _2021531_getSpeciLineIndex(selection[0]) + 1;
        for (int i = firstDelLineIndex; i <= selection[1].row - 1;)
        {
            ins = line.begin();
            for (int j = 1; j <= i; j++)
                ++ins;
            line.erase(ins);
            --selection[1].row;
        }
        inSelection = false;
        if (_2021531_cursor.row > line.size())
        {
            move_2021531_cursor(3);
            move_2021531_cursor(2);
        }
        return;
    }
    switch (type)
    {
        case 1:
            if (_2021531_getSpeciLineIndex(_2021531_cursor) + 1 == line.size() && getSpeciCharIndex(_2021531_cursor) == getSpeciLineVisLength(_2021531_cursor) - 1)
                return; //moded getCurLineLength().
            if (getSpeciCharIndex(_2021531_cursor) == getSpeciLineVisLength(_2021531_cursor) - 1)
            { //moded getCurLineLength().
                line[_2021531_getSpeciLineIndex(_2021531_cursor)] = getSpeciLineVisStr(_2021531_cursor) + line[_2021531_getSpeciLineIndex(_2021531_cursor) + 1];
                ins = line.begin();
                for (int i = 1; i <= _2021531_getSpeciLineIndex(_2021531_cursor); i++)
                    ++ins;
                line.erase(++ins);
                return;
            }
            left = getSpeci_2021531_cursorLeftSub(_2021531_cursor);
            right = getSpeci_2021531_cursorRightSub(_2021531_cursor).substr(1);
            line[_2021531_getSpeciLineIndex(_2021531_cursor)] = left + right;
            break;
        case 2:
            if (getSpeciCharIndex(_2021531_cursor) == -1 && _2021531_getSpeciLineIndex(_2021531_cursor) == 0)
                return;
            if (getSpeciCharIndex(_2021531_cursor) == -1)
            {
                pos tmpCurs = _2021531_cursor; //backup the _2021531_cursor. so we can move the _2021531_cursor before line is merged.
                move_2021531_cursor(3);
                move_2021531_cursor(2);
                line[_2021531_getSpeciLineIndex(tmpCurs) - 1] = getSpeciLineVisStr(pos(tmpCurs.row - 1, tmpCurs.col)) + line[_2021531_getSpeciLineIndex(tmpCurs)];
                ins = line.begin();
                for (int i = 1; i <= _2021531_getSpeciLineIndex(tmpCurs); i++)
                    ++ins;
                line.erase(ins);
                return;
            }
            left = getSpeci_2021531_cursorLeftSub(_2021531_cursor).substr(0, getSpeciCharIndex(_2021531_cursor));
            right = getSpeci_2021531_cursorRightSub(_2021531_cursor);
            line[_2021531_getSpeciLineIndex(_2021531_cursor)] = left + right;
            --_2021531_cursor.col; //_2021531_cursor goes back 1 char.
            break;
    }
}

int theFind(string word)
{
    vector<string> range = getSelectionArea();
    int ans = 0;
    for (string curLine : range)
    {
        int fIndex = 0;
        while (fIndex < curLine.length() && (fIndex = curLine.find(word)) != string::npos)
        {
            ++ans;
            curLine = curLine.substr(fIndex + 1);
            fIndex = 0;
        }
    }
    return ans;
}

void shift()
{
    shifted = !shifted;
    if (shifted)
    {
        if (inSelection)
        {
            inSelection = false;
            return;
        }
        remPoint = _2021531_cursor;
    }
    else
    {
        if (remPoint == _2021531_cursor)
            return;
        if (remPoint < _2021531_cursor)
        {
            selection[0] = remPoint;
            selection[1] = _2021531_cursor;
        }
        else
        {
            selection[1] = remPoint;
            selection[0] = _2021531_cursor;
        }
        inSelection = true;
    }
}

int theCount()
{
    vector<string> range = getSelectionArea();
    int ans = 0;
    for (string str : range)
        for (char c : str)
            if (c != ' ' && c != '\n')
                ans++;
    return ans;
}

void thePrint()
{
    for (string str : line)
        if (!str.empty())
            cout << str;
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    int opCnt;
    cin >> opCnt;
    line.emplace_back("");
    string op, arg1;
    bool insertChar = false; //for debug.
    for (int opI = 1; opI <= opCnt; opI++)
    {
        insertChar = false;
        cin >> op;
        if (op == "MOVE")
        {
            cin >> arg1;
            if (arg1 == "Home")
            {
                move_2021531_cursor(1);
            }
            else if (arg1 == "End")
            {
                move_2021531_cursor(2);
            }
            else if (arg1 == "Up")
            {
                move_2021531_cursor(3);
            }
            else if (arg1 == "Down")
            {
                move_2021531_cursor(4);
            }
            else if (arg1 == "Left")
            {
                move_2021531_cursor(5);
            }
            else if (arg1 == "Right")
            {
                move_2021531_cursor(6);
            }
        }
        else if (op == "INSERT")
        {
            cin >> arg1;
            if (arg1 == "Char")
            {
                string arg2;
                cin >> arg2;
                insert(1, arg2);
                insertChar = true; //for debug.
            }
            else if (arg1 == "Enter")
            {
                insert(2, NULLSTR);
            }
            else if (arg1 == "Space")
            {
                insert(3, NULLSTR);
            }
            else if (arg1 == "Paste")
            {
                insert(4, NULLSTR);
            }
        }
        else if (op == "REMOVE")
        {
            cin >> arg1;
            if (arg1 == "Del")
            {
                theRemove(1);
            }
            else if (arg1 == "Backspace")
            {
                theRemove(2);
            }
        }
        else if (op == "SHIFT")
        {
            shift();
        }
        else if (op == "FIND")
        {
            cin >> arg1;
            int ans = theFind(arg1);
            cout << ans << endl;
        }
        else if (op == "COPY")
        {
            theCopy(pasteBin);
        }
        else if (op == "PRINT")
        {
            thePrint();
        }
        else if (op == "COUNT")
        {
            cout << theCount() << endl;
        }
    }
    return 0;
}