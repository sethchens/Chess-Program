/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#include "position.h"
#include <iostream>

Position::Position(int location) : colRow(0xff)
{
    if (location >= 0 && location < 64)
    {
        int row = location / 8;
        int col = location % 8;
        set(col, row);
    }
}

int Position::getLocation() const
{
    if (isValid())
    {
        return getRow() * 8 + getCol();
    }
    return -1;
}



void Position::setLocation(int location)
{
    if (location >= 0 && location < 64)
    {
        int row = location / 8;
        int col = location % 8;
        set(col, row);
    }
    else
    {
        setInvalid();
    }
}

Position::Position(int c, int r) : colRow(0xff)
{
    set(c, r);
}


int Position::getCol() const
{
    return isValid() ? (int)((colRow & 0xf0) >> 4) : -1;
}

int Position::getRow() const
{
    return isValid() ? (int)(colRow & 0x0f) : -1;
}

void Position::setRow(int r)
{
    if (r >= 0 && r < 8)
    {
        colRow = (colRow & 0xf0) | (r & 0x0f);
    }
    else
    {
        setInvalid();
    }
}

void Position::setCol(int c)
{
    if (c >= 0 && c < 8)
    {
        colRow = (colRow & 0x0f) | ((c & 0x0f) << 4);
    }
    else
    {
        setInvalid();
    }
}

void Position::set(int c, int r)
{
    if (c >= 0 && c < 8 && r >= 0 && r < 8)
    {
        colRow = ((c & 0x0f) << 4) | (r & 0x0f);
    }
    else
    {
        setInvalid();
    }
}

void Position::setXY(double x, double y)
{
    int col = (int)((x - OFFSET_BOARD) / squareWidth);
    int row = 7 - (int)((y - OFFSET_BOARD) / squareHeight);
    set(col, row);
}

Position::Position(const char* s) : colRow(0xff)
{
    setFromText(s);
}

Position::Position(const string& s) : colRow(0xff)
{
    setFromText(s);
}

const Position& Position::operator = (const char* rhs)
{
    setFromText(rhs);
    return *this;
}

const Position& Position::operator = (const string& rhs)
{
    setFromText(rhs);
    return *this;
}

string Position::getText() const
{
    if (!isValid())
        return string("error");

    char col = 'a' + getCol();
    char row = '1' + getRow();
    return string(1, col) + string(1, row);
}

void Position::setFromText(const string& s)
{
    if (s.length() != 2)
    {
        setInvalid();
        return;
    }

    char col = std::tolower(s[0]);
    char row = s[1];

    if (col < 'a' || col > 'h' || row < '1' || row > '8')
    {
        setInvalid();
        return;
    }

    set(col - 'a', row - '1');
}

Position::Position(const Position& rhs, const Delta& delta) : colRow(rhs.colRow)
{
    *this += delta;
}

void Position::adjustRow(int dRow)
{
    if (isValid())
    {
        int newRow = getRow() + dRow;
        if (newRow >= 0 && newRow < 8)
        {
            setRow(newRow);
        }
        else
        {
            setInvalid();
        }
    }
}

void Position::adjustCol(int dCol)
{
    if (isValid())
    {
        int newCol = getCol() + dCol;
        if (newCol >= 0 && newCol < 8)
        {
            setCol(newCol);
        }
        else
        {
            setInvalid();
        }
    }
}

const Position& Position::operator += (const Delta& rhs)
{
    if (isValid())
    {
        int newRow = getRow() + rhs.dRow;
        int newCol = getCol() + rhs.dCol;

        if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8)
        {
            setInvalid();
        }
        else
        {
            set(newCol, newRow);
        }
    }
    return *this;
}

Position Position::operator + (const Delta& rhs) const
{
    Position result(*this);
    result += rhs;
    return result;
}

/******************************************
 * POSITION INSERTION OPERATOR
 ******************************************/
ostream & operator << (ostream & out, const Position & rhs)
{
    out << rhs.getText();
    return out;
}

/*************************************
 * POSITION EXTRACTION OPERATOR
 **************************************/
istream & operator >> (istream & in,  Position & rhs)
{
    string text;
    in >> text;
    rhs.setFromText(text);
    return in;
}


