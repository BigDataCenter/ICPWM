int CheckCPsVM(int NumOfCP)
{
    if (NumOfCP == 1)
        return 1;
    for (int i = 0; i < NumOfCP-1; i++)
    {
        if (ATYPE[CP[i]][1] != ATYPE[CP[i + 1]][1])
            return 0;
    }
    return 1;
}
