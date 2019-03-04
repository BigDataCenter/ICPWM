int SimDataGenerator(int times, int MODNUM, int MODLINK, int VMTYPE)
{//generate modules, VM type, BW type and clouds
    int        i;
    double    CPU[CLOUDNUM], IO[CLOUDNUM], storage[CLOUDNUM], trans[CLOUDNUM];
    
    time_t t;
    srand((unsigned) time(&t)*times);
    
    GenerateTaskGraph(MODNUM, MODLINK);
    GenerateVMTYPE(VMTYPE);
    GenerateBWTYPE(BWTYPE);
    
    for(i = 0; i < CLOUDNUM; i++)
    {
        CPU[i]        = PMCPUCYCLE_LOW + (rand() / (double)RAND_MAX) * (double)PMCPUCYCLE_RANGE;
        IO[i]        = PMIO_LOW + (rand() / (double)RAND_MAX) * (double)PMIO_RANGE;
        storage[i]    = PMSTORAGE_LOW + (rand() / (double)RAND_MAX) * (double)PMSTORAGE_RANGE;
        trans[i]    = PMTRANS_LOW + (rand() / (double)RAND_MAX) * (double)PMTRANS_RANGE;
    }
    
    InsertSortDescent(CPU, CLOUDNUM);
    InsertSortAscent(IO, CLOUDNUM);
    InsertSortAscent(storage, CLOUDNUM);
    InsertSortAscent(trans, CLOUDNUM);
    
    for(i = 0; i < CLOUDNUM; i++)
    {
        GenerateNetworkGraph(PMNUM, i, CPU[i], IO[i], storage[i], trans[i]);
    }
    
    return 0;
}
