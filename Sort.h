void SWAPINT(int* x, int* y)
{//swap int x and y
    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}

void SWAPDOUBLE(double* x, double* y)
{//swap double x and y
    double temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}

void InsertSortDescentWaitTime(double* A, int n, int* O)
{
    int i, j;
    
    for(i = 0; i < n; i++)
    {
        j = i;
        while(j > 0 && A[j-1] < A[j])
        {
            SWAPDOUBLE(&A[j-1], &A[j]);
            SWAPINT(&O[j-1], &O[j]);
            j--;
        }
    }
}

void InsertSortDescent(double* A, int n)
{//insert sort in descent order
    int i, j;
    for(i = 0; i < n; i++)
    {
        j = i;
        while(j > 0 && A[j-1] < A[j])
        {
            SWAPDOUBLE(&A[j-1], &A[j]);
            j--;
        }
    }
}

void InsertSortAscent(double* A, int n)
{//insert sort in ascent order
    int i, j;
    for(i = 0; i < n; i++)
    {
        j = i;
        while(j > 0 && A[j-1] > A[j])
        {
            SWAPDOUBLE(&A[j-1], &A[j]);
            j--;
        }
    }
}
