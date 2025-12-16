//Transpose of Matrix

#include <stdio.h>
#define ROWS 3
#define COLS 3

void transpose(int matrix[ROWS][COLS], int result[COLS][ROWS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS] = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}};
    int result[COLS][ROWS];
    
    printf("Original Matrix:\n");
    displayMatrix(matrix);
    
    transpose(matrix, result);
    
    printf("\nTranspose of Matrix:\n");
    displayMatrix(result);
    
    return 0;
}

//Matrix Multiplication
#include <stdio.h>
#define MAX 10
void multiplyMatrices(int mat1[][MAX], int mat2[][MAX], int result[][MAX], int rows1, int cols1, int rows2, int cols2) 
{
    int i, j, k;

    // Perform multiplication
    for (i = 0; i < rows1; i++) 
	{
        for (j = 0; j < cols2; j++) 
		{
            result[i][j] = 0;
            for (k = 0; k < rows2; k++) 
			{
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);

	printf("Enter the number of rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) 
	{
        printf("Matrix multiplication not possible. Number of columns in first matrix must be equal to the number of rows in the second matrix.\n");
        return 0;
    }

    printf("Enter the elements of first matrix:\n");
    for (int i = 0; i < rows1; i++) 
	{
        for (int j = 0; j < cols1; j++) 
		{
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("First Matrix:\n");
	displayMatrix(mat1, rows1, cols1);

    
    printf("Enter the elements of second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    printf("Second Matrix:\n");
	displayMatrix(mat2, rows2, cols2);

    multiplyMatrices(mat1, mat2, result, rows1, cols1, rows2, cols2);

    printf("Resultant Matrix:\n");
    displayMatrix(result, rows1, cols2);

    return 0;
}
