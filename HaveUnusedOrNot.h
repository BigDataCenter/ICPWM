int HaveUnusedOrNot(int MODNUM)
{
    for (int i = 0; i < MODNUM; i++)
        if (V[i].used == false)
            return 1;
    return 0;
}
