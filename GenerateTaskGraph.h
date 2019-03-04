void GenerateTaskGraph(int numMods, int numModLinks) // DAG generator
{//generate module graph
    int            i, j, k, iPreRandModID, iCurRandModID, iNextRandModID, iTimes = 0, inputSize, outputSize;
    double        modComplexity, modStorage;
    int            *pIndex, *pTmpIndex1;
    double        **ppOutput;
    
    pIndex            = new int[numMods];
    pTmpIndex1        = new int[numMods];
    ppOutput        = new double*[numMods];
    for(i = 0; i < numMods; i ++)
        ppOutput[i] = new double[numMods];
    
    for(i = 0; i < numMods; i ++)
        pTmpIndex1[i] = i;
    
    for(i = 0; i < numMods; i ++)
    {
        modComplexity    = MODCOMPLEXITY_LOW + (rand() / (double)RAND_MAX) * (double)MODCOMPLEXITY_RANGE;
        //modStorage        = MODSTORAGE_LOW + (rand() / (double)RAND_MAX) * (double)MODSTORAGE_RANGE;
        //fprintf(fp, "%d\t%8.2lf\t%8.2lf\n", i, modComplexity, modStorage);
        //V[i].storage    = modStorage;
        V[i].complexity = modComplexity;
    }
    
    for(i = 0; i < numMods; i ++)                    // initialize, "0.00" means no link
        for(j = 0; j < numMods; j ++)
            ppOutput[i][j] = 0.00;
    
    iNextRandModID                    = RandNumGivenRange(1, (numMods - 1));  // first module
    ppOutput[0][iNextRandModID]        = MODOUTPUTSIZE_LOW + (rand() / (double)RAND_MAX) * (double)MODOUTPUTSIZE_RANGE;
    E[iTimes].from                    = 0;
    E[iTimes].to                    = iNextRandModID;
    E[iTimes].size                    = ppOutput[0][iNextRandModID];
    iTimes ++;
    
    for(i = 1; i < numMods - 1; i ++)
    {
        for(k = 0; k < i; k ++)
        {
            if(ppOutput[k][i] != 0.00)  // has been chosen already
                break;
        }
        if(k == i)
        {
            iPreRandModID                    = RandNumGivenRange(0, (i - 1));
            ppOutput[iPreRandModID][i]        = MODOUTPUTSIZE_LOW + (rand() / (double)RAND_MAX) * (double)MODOUTPUTSIZE_RANGE;
            E[iTimes].from                    = iPreRandModID;
            E[iTimes].to                    = i;
            E[iTimes].size                    = ppOutput[iPreRandModID][i];
            iTimes ++;
        }
        
        iNextRandModID                    = RandNumGivenRange((i + 1), (numMods - 1));
        ppOutput[i][iNextRandModID]        = MODOUTPUTSIZE_LOW + (rand() / (double)RAND_MAX) * (double)MODOUTPUTSIZE_RANGE;
        E[iTimes].from                    = i;
        E[iTimes].to                    = iNextRandModID;
        E[iTimes].size                    = ppOutput[i][iNextRandModID];
        iTimes ++;
    }
    
    i = 0;
    
    while(i < (numModLinks - iTimes))
    {
        iCurRandModID    = 0 + rand() % (numMods - 1);
        iNextRandModID    = (iCurRandModID + 1) + rand() % (numMods - 1 - iCurRandModID);
        if(ppOutput[iCurRandModID][iNextRandModID] == 0.00) // has not been chosen already
        {
            ppOutput[iCurRandModID][iNextRandModID] = MODOUTPUTSIZE_LOW + (rand() / (double)RAND_MAX) * (double)MODOUTPUTSIZE_RANGE;
            E[iTimes+i].from                        = iCurRandModID;
            E[iTimes+i].to                            = iNextRandModID;
            E[iTimes+i].size                        = ppOutput[iCurRandModID][iNextRandModID];
            i ++;
        }
    }
    for(i = 0; i < numMods; i++)
    {
        inputSize = 0;
        outputSize = 0;
        for(j = 0; j < numModLinks; j++)
        {
            if(i == E[j].from)
                outputSize    += E[j].size;
            if(i == E[j].to)
                inputSize    += E[j].size;
        }
        if(rand()%2 == 1)
            V[i].storage = outputSize + inputSize;
        else
        {
            if(outputSize > inputSize)
                V[i].storage = outputSize;
            else
                V[i].storage = inputSize;
        }
    }
    
    if(pIndex != NULL)
        delete[] pIndex;
    
    if(pTmpIndex1 != NULL)
        delete[] pTmpIndex1;
    
    for(i = 0; i < numMods; i ++)
        if(ppOutput[i] != NULL)
            delete[] ppOutput[i];
    delete[] ppOutput;
}
