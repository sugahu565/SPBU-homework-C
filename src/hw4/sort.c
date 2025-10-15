void sort(int* startArr, int* endArr)
{
    if (startArr + 1 >= endArr)
	return;
    int diff = (endArr - startArr) / 2;
    sort(startArr, startArr + diff);
    sort(startArr + diff, endArr);
    
    
}