int ATYPEIsEmpty(int MODNUM)
{//check whether VM types are assigned
    for(int i = 0; i < MODNUM; i++)
    {
        if(ATYPE[i][0] != -1)
        {
            return 0;
        }
    }
    return 1;
}
