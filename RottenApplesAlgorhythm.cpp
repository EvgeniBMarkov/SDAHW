void RottenApplesAlgorhythm(int Apples[int arrayWidth][int arrayLength])
{
    bool change=false;
    int cycles=0;
    do
    {
        change=false;
        for(int i=0, i<arrayLength, i++)
        {
            for(int j=0, j<arrayWidth, j++)
            {
                if(Apples[i][j]==2)
                {
                    if(i>0 && Apples[i-1][j]==1)
                    {
                        Apples[i-1][j]=2;
                    }
                    
                    if(i<(arrayLength-1) && Apples[i+1][j]==1)
                    {
                        Apples[i+1][j]=2;
                    }

                    if(j>0 && Apples[i][j-1]==1)
                    {
                        Apples[i][j-1]=2;
                    }
                    
                    if(j<(arrayWidth-1) && Apples[i][j+1]==1)
                    {
                        Apples[i][j+1]=2;
                    }

                    change= true;
                    cycles++;
                }
            }
        }
    }
    while(change);
    if(cycles==0) cout<<"No rot transmitted"<<endl;
    else
    {
        cout<<cycles<<" units of time to maximum transmission of rot"<<endl;
    }

    bool completeTransmission=false;

    for(int i=0, i<arrayLength, i++)
        {
            for(int j=0, j<arrayWidth, j++)
            {
                if(Apples[i][j]==1) completeTransmission=true;
            }
        }

    if(completeTransmission)
    {
        cout<<"All apples rotten"<<endl;
    }
}