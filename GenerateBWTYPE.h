void GenerateBWTYPE(int numBW)
{//generate BW types
    int        i, j;
    double    bw, price;
    
    for(j = 0; j < CLOUDNUM; j++)
    {
        BWTYPENUM[j] = RandNumGivenRange(1, numBW);
        for(i = 0; i < BWTYPENUM[j]; i ++)
        {
            bw        = BW_LOW - 1 + i + (rand() / (double)RAND_MAX) * (double)BW_RANGE/BWTYPENUM[j];
            price    = BWPERPRICE * bw;
            BW[j][i].value = bw;
            BW[j][i].price = price;
        }
    }
}
