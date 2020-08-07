void print_MOM(int **memoization_matrix, int array_size, int required_sum)
{
    cout << "Current Memoization Matrix Status" << endl;
    for (int i = 0; i < array_size + 1; i++)
    {
        for (int j = 0; j < required_sum + 1; j++)
            cout << setw(2) << memoization_matrix[i][j];
        cout << endl;
    }
    cout << endl;
}
