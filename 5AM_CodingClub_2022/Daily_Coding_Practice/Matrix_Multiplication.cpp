

#if 0
void multiplication(int arr1[][2], int row1, int col1, int arr2[][2], int row2, int col2, int result[][2]) {

    // This case is your matricx product implementation requirement.
    if (col1 != row2) {
        for (int x = 0; x < row1; x++) {
            for (int y = 0; y < col2; y++) {
                result[x][y] = -1;
            }
        }
    }
    else {
        for (int x = 0; x < row1; x++) {
            for (int y = 0; y < col2; y++) {
                result[x][y] = 0;
                for (int z = 0; z < col1; z++) {
                    result[x][y] = result[x][y] + arr1[x][z] * arr2[z][y];
                }
            }
        }
    }
}

int main()
{

    return 0;
}

#endif // 0
