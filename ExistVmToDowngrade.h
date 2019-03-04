int ExistVmToDowngrade(int MODNUM)
{
    int i;
    for (i = 0; i < MODNUM; i++)
    {
        if (ATYPE[i][0] > MINVT[i])
            return 1;
    }
    return 0;
}
