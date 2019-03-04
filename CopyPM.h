void CopyPM(PMC** A)
{
    int i, j;
    
    for(i = 0; i < CLOUDNUM; i++)
    {
        for(j= 0; j < PMNUM; j++)
        {
            A[i][j].CPU        = PM[i][j].CPU;
            A[i][j].IO        = PM[i][j].IO;
            A[i][j].storage = PM[i][j].storage;
            A[i][j].trans    = PM[i][j].trans;
        }
    }
}
