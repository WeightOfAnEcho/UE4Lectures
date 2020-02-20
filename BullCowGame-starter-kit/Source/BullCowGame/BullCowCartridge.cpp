// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("LIME");
    Lives = 3;
}

void UBullCowCartridge::BeginPlay() // When the game starts
{
    //Begin Game
    Super::BeginPlay();
    SetupGame();

    PrintLine(TEXT("The Hidden Word is: %s "), *HiddenWord); //debug line

    PrintLine(TEXT("Hello there, Press Tab to use the Terminal")); // Prints a line to the terminal
    PrintLine(TEXT("Guess the %i letter word\n Then press enter..."), HiddenWord.Len());

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen(); // clear the terminal

    //check the guess
    //is it an isogram?
    //is is the right amount of characters?

    PrintLine(TEXT ("You guessed: " + (Input)));
    
        if (Input == HiddenWord)
    {
        PrintLine("Well done, that was correct!");
    }

    else
    {
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine (TEXT("The hidden word is %i characters long"), HiddenWord.Len());
        }

        PrintLine (TEXT("That was incorrect, please try again"));
        LoseLife();
        PrintLine (TEXT("You have %i Lives Remaining"), Lives);
        PrintLine (TEXT("Please guess again"));

        //remove a life
        //show how many lives remaining
        //prompt to guess again

    }

}

void UBullCowCartridge::LoseLife()
{
    if (Lives > 0)
    {
        Lives --;
    }

    else
    {
        PrintLine (TEXT("You have run out of lives! \n Game Over"));
    }
    
    
}

