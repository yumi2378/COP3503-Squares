#include <iostream>
#include <climits>
using namespace std;

bool checkMagic(int **square, int n)
{
	int diag;
	int diag2;
	int row;
	int col;
	int rows[n];
	int cols[n];
	
	//diagonal sum
	diag = 0;
	diag2 = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i == j)
				diag = diag + square[i][j];
			if(i+j==(n-1))
				diag2 = diag2 + square[i][j];
		}
	}
	
	//row sum
	for(int i=0; i<n; i++)
	{
		row = 0;
		for(int j=0; j<n; j++)
		{
			row = row + square[i][j];
		}
	}
	
	//column sum
	for(int i=0; i<n; i++)
	{
		col = 0;
		for(int j=0; j<n; j++)
		{
			col = col + square[j][i];
		}
	}
	
	for(int i=0; i<n; i++)
		rows[i] = row;
	
	for(int i=0; i<n; i++)
		cols[i] = col;
		
	if(diag == row && diag == col && diag == diag2)
	//print values
	{
		cout << endl;
		cout << "Checking the sums of every row:      ";
		for(int i=0; i<n; i++)
			cout << rows[i] << " ";
		cout << endl;
		cout << "Checking the sums of every column:   ";
		for(int i=0; i<n; i++)
			cout << cols[i] << " ";
		cout << endl;
		cout << "Checking the sums of every diagonal: " << diag << " " << diag << endl;
		cout << endl;
		return true;
	}
	else
		return false;
}

int **createSquare(int n)
{
	int **square = new int *[n];
	for (int i = 0; i < n; i++)
    	square[i] = new int[n];
	
	int i = n/2;
	int j = n-1;
	int N = n*n;
	for(int k = 1; k <= N;)
	{
		if(i == -1 && j == n)
		{
			j = n - 2;
			i = 0;
		}
		else
		{
			if(j == n)
				j = 0;
			if(i < 0)
				i = n - 1;
		}
		if(square[i][j])
		{
			j -= 2;
			i++;
			continue;
		}
		else
			square[i][j] = k++;
		j++;
		i--;
	}	
	
	cout << "Magic square #1 is:" << endl;
	cout << endl;
    //Print
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        	if (square[i][j] < 100 && square[i][j] > 9)
        		cout << square[i][j] << "   ";
        	else if (square[i][j] < 10)
        		cout << square[i][j] << "    ";
            else
            	cout << square[i][j] << "  "; 
        cout << endl;
    }
    checkMagic(square, n);
    return square;
}

void rotateSquare(int **square, int n, int x)
{    
    int y = 3;
    while(y > 0)
    {   
    	//Rotate matrix	
    	for(int i=0; i<n/2; i++)
    	{	
    		for(int j=i; j<n-i-1; j++)
    		{
    			int temp = square[i][j];
    			square[i][j] = square[j][n-1-i];
    			square[j][n-1-i] = square[n-1-i][n-1-j];
    			square[n-1-i][n-1-j] = square[n-1-j][i];
    			square[n-1-j][i] = temp;
    		}
    	}   
    
    	//print
   		cout << "Magic square #" << x << " is:" << endl;
   		cout << endl;
    	for(int i=0; i<n; i++)
    	{
        	for(int j=0; j<n; j++)
        		if (square[i][j] < 100 && square[i][j] > 9)
        			cout << square[i][j] << "   ";
        		else if (square[i][j] < 10)
        			cout << square[i][j] << "    ";
        	    else
        	    	cout << square[i][j] << "  "; 
        	cout << endl;
    	}
    	checkMagic(square, n);
    	y--;
    	x++;
    }  	
}

void reflectSquare(int **square, int n)
{
	int first = ((n-1)/2)-1; 
	int second = ((n-1)/2)+1;
	int k = ((n-1)/2);
    
    //reflects matrix over middle row
   	while(k>0)
   	{	
   		for (int i=0; i<n; i++)
   		{
   			int temp1;
   			temp1 = square[first][i];
   			square[first][i] = square[second][i];
   			square[second][i] = temp1;
   		}
   		first--;
   		second++;
   		k--;
   	}
   	    	
   	//print
   	cout << "Magic square #5 is:" <<endl;
   	cout << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        	if (square[i][j] < 100 && square[i][j] > 9)
        		cout << square[i][j] << "   ";
        	else if (square[i][j] < 10)
        		cout << square[i][j] << "    ";
            else
            	cout << square[i][j] << "  "; 
        cout << endl;
    }

    checkMagic(square, n);
    //rotate reflected Magic Square
    rotateSquare(square, n, 6); 
}

void swapRows(int **square, int n)
{
	int first = ((n-1)/2)-1;
	int second = ((n-1)/2)+1;
   	
   	//Switches alternating rows an equal distance from the center
   	while(first>0)
   	{
   		for (int i=0; i<n; i++)
   		{
   			int temp1;
   			int temp2;
   			temp1 = square[first][i];
   			square[first][i] = square[second][i];
   			square[second][i] = temp1;
   		}
   		first = first - 2;
   		second = second + 2;
   	}
   	//print
   	cout << "Magic square #9 is:" <<endl;
   	cout << endl;
   	for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        	if (square[i][j] < 100 && square[i][j] > 9)
        		cout << square[i][j] << "   ";
        	else if (square[i][j] < 10)
        		cout << square[i][j] << "    ";
            else
            	cout << square[i][j] << "  "; 
        cout << endl;
    }
    checkMagic(square, n);
}

void swapColumns(int **square, int n)
{
	int first = ((n-1)/2)-1;
	int second = ((n-1)/2)+1;
	/*
	Switches alternating columns an equal distance from the center.
	Switching any number rows or columns symmetrically accross the center produces new magic 		squares. This program does alternating to make it interesting. Of course, any new squares 		produced this way could also be rotated and reflected to produce many more.
	*/
	while(first>0)
	{
		for (int i=0; i<n; i++)
   		{
   			int temp1;
   			temp1 = square[i][first];
   			square[i][first] = square[i][second];
   			square[i][second] = temp1;
   		}
   		first = first - 2;
   		second = second + 2;
   	}
   	cout << "Magic square #10 is:" <<endl;
   	cout << endl;
   	//Print
   	for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        	if (square[i][j] < 100 && square[i][j] > 9)
        		cout << square[i][j] << "   ";
        	else if (square[i][j] < 10)
        		cout << square[i][j] << "    ";
            else
            	cout << square[i][j] << "  "; 
        cout << endl;
    }
    checkMagic(square, n);
}

int main()
{
    int n;
    //Take user input and validate
    while(1) 
    {
    	cout << "Enter the size of a magic square: " << endl;
    	cin >> n;
    	
    	if(cin.good())
    	{
    		if(n<3 || n%2==0 || n>15)
    		{
    			cout << "ERROR: Please enter an odd integer between 1 and 15." << endl;
    			cout << endl;
    			cin.clear();
    		}
    		else
    			break;
    	}
    	
    	else
    	{
    		cout << "ERROR: Not an integer." << endl;
    		cout << endl;
    		cin.clear();
    		cin.ignore(INT_MAX, '\n');
    		continue;
    	}
    }
    
    int **square = createSquare(n); //Generate first Magic Square
    rotateSquare(square, n, 2); //Rotates the square
    reflectSquare(square, n); //Reflects square
    //The 3x3 only has 8 possibilities consisting of rotations and reflections.
    if(n>3) 
    {
    	swapRows(square, n);
    	swapColumns(square, n);
    }
    return 0;
}
			
	


