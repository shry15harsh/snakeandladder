#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

struct box
{
    int arr[2][2];
};
void display_board();

main()
{
    cout<<"This is a Snake and Ladder game."<<endl<<"There are four sections in each box."<<endl<<"First box tells the position"<<endl<<"Second tell if you are there or not"<<endl<<"Fourth tells the position where the ladder or snake heads to"<<endl<<"Third box is used when there are two players";
    cout<<"\n\nPosition number\tYour presence\nTwo players\tLadder/Snake\n";
    box box[6][6];

    for(int i=5;i>=0;i--)
    {
        for(int j=5;j>=0;j--)
        {
            box[i][j].arr[0][1]=box[i][j].arr[1][0]=box[i][j].arr[1][1]=0;
            box[i][j].arr[0][1]=box[i][j].arr[1][0]=box[i][j].arr[1][1]=0;
        }
    }
    box[0][3].arr[1][1]=16;
    box[0][1].arr[1][1]=7;
    box[1][5].arr[1][1]=2;
    box[2][4].arr[1][1]=11;
    box[2][3].arr[1][1]=25;
    box[2][1].arr[1][1]=4;
    box[2][0].arr[1][1]=20;
    box[3][2].arr[1][1]=32;
    box[5][1].arr[1][1]=22;
    box[5][0].arr[1][1]=19;

    //******************************************

    cout<<endl<<"_____________________________________________________"<<endl;
    for(int i=5;i>=0;i--)
    {
        for(int j=5;j>=0;j--)
        {
            if(i%2!=0)
            {
                box[i][j].arr[0][0]=6*(i+1)-(5-j);

                    for(int l=0;l<2;l++)
                    {
                        printf("%2d",box[i][j].arr[0][l]);
                        cout<<" ";
                    }
                    cout<<" | ";
            }
            else
            {
                box[i][j].arr[0][0]=6*(i+1)-(j);
                    for(int l=0;l<2;l++)
                    {
                        printf("%2d",box[i][j].arr[0][l]);
                        cout<<" ";
                    }
                    cout<<" | ";
            }
        }
        cout<<endl;
        for(int j=5;j>=0;j--)
        {
            for(int l=0;l<2;l++)
                    {
                        printf("%2d",box[i][j].arr[1][l]);
                        cout<<" ";
                    }
            cout<<" | ";
        }
        cout<<endl<<"_____________________________________________________"<<endl;
    }
    cout<<"Scroll up for full details\n";
    //*******************


    srand(time(0));
    box[0][5].arr[0][1]=99;
    int die,posi=0,posj=5,new_pos;
    char ans='r',confirm;
    int start1=1;
    while(ans=='r')
    {
        box[posi][posj].arr[0][1]=0;
        cout<<endl<<"To roll the die, press R"<<endl;
        cin>>ans;
        if(ans=='r')
        {
            die=rand()%6+1;
            new_pos=start1+die;
            cout<<die;
            ans='r';
        }
        if(new_pos<=36)
        {
        if(new_pos<7||((new_pos>12)&&(new_pos<19))||((new_pos>24)&&(new_pos<31)))
        posj=6-new_pos%6;
        else
        {
            posj=new_pos%6-1;
            if(posj<0)
            posj=5;
        }
        if(new_pos%6!=0)
        {
            posi=new_pos/6;
        }
        else
        {
            posi=new_pos/6-1;
        }
        }
        cout<<endl<<"Press any key to refresh the screen"<<endl;
        cin>>confirm;
        start1=new_pos;
        box[posi][posj].arr[0][1]=99;
        system("cls");
        //******************************************

    cout<<endl<<"_____________________________________________________"<<endl;
    for(int i=5;i>=0;i--)
    {
        for(int j=5;j>=0;j--)
        {
            if(i%2!=0)
            {
                box[i][j].arr[0][0]=6*(i+1)-(5-j);

                    for(int l=0;l<2;l++)
                    {
                        printf("%2d",box[i][j].arr[0][l]);
                        cout<<" ";
                    }
                    cout<<" | ";
            }
            else
            {
                box[i][j].arr[0][0]=6*(i+1)-(j);
                    for(int l=0;l<2;l++)
                    {
                        printf("%2d",box[i][j].arr[0][l]);
                        cout<<" ";
                    }
                    cout<<" | ";
            }
        }
        cout<<endl;
        for(int j=5;j>=0;j--)
        {
            for(int l=0;l<2;l++)
                    {
                        printf("%2d",box[i][j].arr[1][l]);
                        cout<<" ";
                    }
            cout<<" | ";
        }
        cout<<endl<<"_____________________________________________________"<<endl;
    }
    //*******************
    cout<<endl;
    if(new_pos==36)
    {
        cout<<"!!!!!!!Congratulations!!!!!!!You are winner";
        char bye;
        cout<<endl<<"Press q to exit";
        cin>>bye;
        if(bye=='q')
        {
            exit(0);
        }
        else
        {
            cout<<"We have to go anyways, Bye";
            exit(0);
        }
    }
    if(box[posi][posj].arr[1][1]!=0)
        {
            if(new_pos<box[posi][posj].arr[1][1])
            {
                cout<<"You get the ladder, Congrats"<<endl;
            }
            else{cout<<"Oh, Snake bit you"<<endl;}
            box[posi][posj].arr[0][1]=0;
            new_pos=box[posi][posj].arr[1][1];
            if(new_pos<7||((new_pos>12)&&(new_pos<19))||((new_pos>24)&&(new_pos<31)))
        posj=6-new_pos%6;
        else
        {
            posj=new_pos%6-1;
            if(posj<0)
            posj=5;
        }
        if(new_pos%6!=0)
        {
            posi=new_pos/6;
        }
        else
        {
            posi=new_pos/6-1;
        }
        cout<<endl<<"Press any key to refresh the screen"<<endl;
        cin>>confirm;
        start1=new_pos;
        box[posi][posj].arr[0][1]=99;
        system("cls");
        //******************************************

    cout<<endl<<"_____________________________________________________"<<endl;
    for(int i=5;i>=0;i--)
    {
        for(int j=5;j>=0;j--)
        {
            if(i%2!=0)
            {
                box[i][j].arr[0][0]=6*(i+1)-(5-j);

                    for(int l=0;l<2;l++)
                    {
                        printf("%2d",box[i][j].arr[0][l]);
                        cout<<" ";
                    }
                    cout<<" | ";
            }
            else
            {
                box[i][j].arr[0][0]=6*(i+1)-(j);
                    for(int l=0;l<2;l++)
                    {
                        printf("%2d",box[i][j].arr[0][l]);
                        cout<<" ";
                    }
                    cout<<" | ";
            }
        }
        cout<<endl;
        for(int j=5;j>=0;j--)
        {
            for(int l=0;l<2;l++)
                    {
                        printf("%2d",box[i][j].arr[1][l]);
                        cout<<" ";
                    }
            cout<<" | ";
        }
        cout<<endl<<"_____________________________________________________"<<endl;
    }
    //*******************
        }
    }

}

void display_board()
{
    box box[6][6];
    cout<<"*******************************"<<endl;
    cout<<box[0][3].arr[1][1]<<endl;
    cout<<box[0][1].arr[1][1]<<endl;
    cout<<box[1][5].arr[1][1]<<endl;
    cout<<box[2][4].arr[1][1]<<endl;
    cout<<box[2][3].arr[1][1]<<endl;
    cout<<box[2][1].arr[1][1]<<endl;
    cout<<box[2][0].arr[1][1]<<endl;
    cout<<box[3][2].arr[1][1]<<endl;
    cout<<box[5][1].arr[1][1]<<endl;
    cout<<box[5][0].arr[1][1]<<endl;
    cout<<"*******************************";


    for(int i=5;i>=0;i--)
    {
        for(int j=5;j>=0;j--)
        {
            if(i%2!=0)
            {
                box[i][j].arr[0][0]=6*(i+1)-(5-j);

                    for(int l=0;l<2;l++)
                    {
                        printf("%2d",box[i][j].arr[0][l]);
                        cout<<" ";
                    }
                    cout<<"\t";
            }
            else
            {
                box[i][j].arr[0][0]=6*(i+1)-(j);
                    for(int l=0;l<2;l++)
                    {
                        printf("%2d",box[i][j].arr[0][l]);
                        cout<<" ";
                    }
                    cout<<"\t";
            }
        }
        cout<<endl;
        for(int j=5;j>=0;j--)
        {
            for(int l=0;l<2;l++)
                    {
                        printf("%2d",box[i][j].arr[1][l]);
                        cout<<" ";
                    }
            cout<<"\t";
        }
    }
    cout<<endl<<endl;
}
