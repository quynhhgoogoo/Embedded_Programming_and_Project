/* */ 
float calc_average(float data[], int size) {
	int i;
	float average=0;
	for (i=0;i<size;i++)
	{
		average=average+data[i];
	}
    return average/size;
}

