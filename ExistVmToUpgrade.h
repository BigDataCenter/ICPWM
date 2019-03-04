int ExistVmToUpgrade(int MODNUM, int VMTYPE)
{
    int i;
    for (i = 0; i < MODNUM; i++)
    {
        if (ATYPE[i][0] < VMTYPE - 1)
            return 1;
    }
    return 0;
}
