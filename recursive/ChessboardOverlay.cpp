//
// Created by Waitti on 2020/5/11.
//
#include <bits/stdc++.h>
#include "ChessboardOverlay.h"

using namespace std;

const int N = 8;

int g[N][N];
int idx = 1;

void solve(int x, int y, int size) {
    memset(g, 0, sizeof g);
    g[x][y] = -1;
    chess_board(0, 0, x, y, size);
    print(4);
}

void chess_board(int tr, int tc, int dr, int dc, int size) {
    if (size == 1)return;
    int s = size / 2, t = idx++;
    if (dr < tr + s && dc < tc + s) {
        chess_board(tr, tc, dr, dc, s);
    } else {
        g[tr + s - 1][tc + s - 1] = t;
        chess_board(tr, tc, tr + s - 1, tc + s - 1, s);
    }

    if (dr >= tr + s && dc < tc + s) {
        chess_board(tr + s, tc, dr, dc, s);
    } else {
        g[tr + s][tc + s - 1] = t;
        chess_board(tr + s, tc, tr + s, tc + s - 1, s);
    }

    if (dr < tr + s && dc >= tc + s) {
        chess_board(tr, tc + s, dr, dc, s);
    } else {
        g[tr + s - 1][tc + s] = t;
        chess_board(tc, tr + s, tr + s - 1, tc + s, s);
    }

    if (dr >= tr + s && dc >= tc + s) {
        chess_board(tr + s, tc + s, dr, dc, s);
    } else {
        g[tr + s][tc + s] = t;
        chess_board(tr + s, tc + s, tr + s, tc + s, s);
    }
}

void print(int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

