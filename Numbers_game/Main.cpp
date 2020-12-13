
#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time
using namespace std;




int RandomNumber(int LowerLimit, int UpperLimit);
char Play();
 
int main()
{   char UserResponse;

    do {
    	    UserResponse= Play();
	}
	while(UserResponse!='N');
	{
		cout<<"Thank you for playing. "<<'\n';
	}
    

	return 0;
}


char Play(){
	 
	cout<<"Lets play a game: "<<'\n';
    cout<<"I am thinking of a number. You have seven tries to guess what it is: "<<'\n';
    int Random {RandomNumber(1,100)};

	for (int i{1};i<=7;i++)
	{   
	    int userguess{};
    	int guessNo{i};
    	//cout<<"The random number is: "<< Random<<'\n';
    	cout<<"Guess # "<< guessNo<<": ";
    	cin>>userguess;		
		if (i<7)
		{
		
			if (userguess>Random)
			{ 
			   cout<<"The guess is too high"<<'\n';
			}
			else if (userguess<Random)
			{
				cout<<"The guess is too low"<<'\n';
			}
			else if (userguess==Random)
			{   char UserDecision;
				cout<<"The guess is right"<<'\n';
				cout<<"Correct! You win! "<<'\n';
					do 
					{
							cout<<"Would you like to play again? (Y/N) ?"<<'\n';
							cin>>UserDecision;
					}
					
					while ( UserDecision!= 'Y' && UserDecision!='N' );
					
					
					{ 
					   return UserDecision;
							}	
			}	
	    }
	    
	    else if(i==7)
	    {
		
		    if ( userguess!=Random)
		    {   char UserDecision;
		    	cout<<"Sorry, you lose. The correct number was "<<Random<<'\n';
		    						do 
					{
							cout<<"Would you like to play again? (Y/N) ?"<<'\n';
							cin>>UserDecision;
					}
					
					while ( UserDecision!= 'Y' && UserDecision!='N' );
					
					
					{ 
					   return UserDecision;
							}	
			}
			else if (userguess==Random)
			{   char UserDecision;
			    cout<<"The guess is right"<<'\n';
				cout<<"Correct! You win! "<<'\n';
					do 
					{
							cout<<"Would you like to play again? (Y/N) ?"<<'\n';
							cin>>UserDecision;
					}
					
					while ( UserDecision!= 'Y' && UserDecision!='N' );
					
					
					{ 
					   return UserDecision;
							}	
			}
		}
		
		
	}
	
 
}


int RandomNumber(int LowerLimit, int UpperLimit){
	
		// Initialize our mersenne twister with a random seed based on the clock
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
 
	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution<> die{ LowerLimit, UpperLimit };
	// If your compiler doesn't support C++17, use this instead
	// std::uniform_int_distribution<> die{ 1, 6 };
 
	// Print a bunch of random numbers
	for (int count{ 1 }; count == 1; ++count)
	{
		int ran{die(mersenne)};
 
		// If we've printed 6 numbers, start a new row
		return ran;
	}
}
