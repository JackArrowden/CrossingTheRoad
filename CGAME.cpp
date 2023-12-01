#include "CGAME.h"
#include <conio.h>


bitmapHandMake CGAME::gameBackground("image\\gameWindow\\gameBgr.bmp");


CGAME::CGAME()
{
	mainChar = NULL;
	numOfCars = 0;
	car = NULL;
	numOfTrucks = 0;
	truck = NULL;
	numOfTrains = 0;
	train = NULL;

	numOfBirds = 0;
	bird = NULL;
	numOfCats = 0;
	cat = NULL;
	numOfMouses = 0;
	mouse = NULL;
	m_isRunning = 0;
	m_currentLevel = 0;
	CurrentScore = 0;
	NameOfPlayer = "";
	FileBackGround = "";
}

CGAME::CGAME(const std::string& file)
{
	mainChar = NULL;
	numOfCars = 0;
	car = NULL;
	numOfTrucks = 0;
	truck = NULL;
	numOfTrains = 0;
	train = NULL;

	numOfBirds = 0;
	bird = NULL;
	numOfCats = 0;
	cat = NULL;
	numOfMouses = 0;
	mouse = NULL;
	m_isRunning = 0;
	m_currentLevel = 0;
	CurrentScore = 0;
	NameOfPlayer = "";

	readFile(file);
}

CGAME::~CGAME()
{
	clear();
}

bool CGAME::readFile(const std::string& file)
{
	ifstream ifs(file);
	if (!ifs.is_open()) return false;
	clear();
	getline(ifs, NameOfPlayer);
	ifs >> CurrentScore >> m_currentLevel;
	mainChar = new CPEOPLE();
	ifs >> *mainChar;

	ifs >> numOfCars;
	if (numOfCars > 0) car = new CAR[numOfCars];
	for (int i = 0; i < numOfCars; i++)
	{
		CVEHICLE* it = dynamic_cast<CVEHICLE*> (&car[i]);
		ifs >> *it;
		m[-it->getY()].push_back(make_pair((void*)it, CAR_NUMBER));
	}

	ifs >> numOfTrucks;
	if (numOfTrucks > 0) truck = new CTRUCK[numOfTrucks];
	for (int i = 0; i < numOfTrucks; i++)
	{
		CVEHICLE* it = dynamic_cast<CVEHICLE*> (&truck[i]);
		ifs >> *it;
		m[-it->getY()].push_back(make_pair((void*)it, TRUCK_NUMBER));
	}

	ifs >> numOfTrains;
	if (numOfTrains > 0) train = new CTRAIN[numOfTrains];
	for (int i = 0; i < numOfTrains; i++)
	{
		ifs >> train[i];
		m[-train[i].getY()].push_back(make_pair(((void*)&train[i]), TRAIN_NUMBER));
	}
	
	ifs >> numOfBirds;
	if (numOfBirds > 0) bird = new CBIRD[numOfBirds];
	for (int i = 0; i < numOfBirds; i++)
	{
		CANIMAL* it = dynamic_cast<CANIMAL*> (&bird[i]);
		ifs >> *it;
		m[-it->getY()].push_back(make_pair((void*)it, BIRD_NUMBER));
	}

	ifs >> numOfCats;
	if (numOfCats > 0) cat = new CAT[numOfCats];
	for (int i = 0; i < numOfCats; i++)
	{
		CANIMAL* it = dynamic_cast<CANIMAL*> (&cat[i]);
		ifs >> *it;
		m[-it->getY()].push_back(make_pair((void*)it, CAT_NUMBER));
	}

	ifs >> numOfMouses;
	if (numOfMouses > 0) mouse = new CMOUSE[numOfMouses];
	for (int i = 0; i < numOfMouses; i++)
	{
		CANIMAL* it = dynamic_cast<CANIMAL*> (&mouse[i]);
		ifs >> *it;
		m[-it->getY()].push_back(make_pair((void*)it, MOUSE_NUMBER));
	}

	ifs.close();
	return true;
}

bool CGAME::SaveGame(const std::string& file)
{
	ofstream ofs;
	ofs.open(file);
	if (!ofs.is_open()) return false;
	ofs << NameOfPlayer << endl;
	ofs << FileBackGround << endl;
	ofs << CurrentScore << " " << m_currentLevel << endl;
	ofs << *mainChar << endl;
	ofs << numOfCars << " ";
	for (int i = 0; i < numOfCars; i++)
	{
		CVEHICLE* it = dynamic_cast<CVEHICLE*> (&car[i]);
		ofs << *it<<" ";
			
	}
	ofs << endl;
	ofs << numOfTrucks <<" ";
	for (int i = 0; i < numOfTrucks; i++)
	{
		CVEHICLE* it = dynamic_cast<CVEHICLE*> (&truck[i]);
		ofs << *it << " ";
		
	}
	ofs << endl;
	ofs << numOfTrains << " ";
	for (int i = 0; i < numOfTrains; i++)
	{
		ofs << train[i] << " ";
		
	}
	ofs << endl;
	ofs << numOfBirds << " ";
	for (int i = 0; i < numOfBirds; i++)
	{
		CANIMAL* it = dynamic_cast<CANIMAL*> (&bird[i]);
		ofs << *it<<" ";
		
	}
	ofs << endl;
	ofs << numOfCats << " ";
	for (int i = 0; i < numOfCats; i++)
	{
		CANIMAL* it = dynamic_cast<CANIMAL*> (&cat[i]);
		ofs << *it<<" ";
		

	}
	ofs << endl;
	ofs << numOfMouses << " ";
	for (int i = 0; i < numOfMouses; i++)
	{
		CANIMAL* it = dynamic_cast<CANIMAL*> (&mouse[i]);
		ofs << *it<<" ";
		

	}
	ofs.close();
	return true;



	
	

	
}

void CGAME::PeopleMove(int direc)
{
	if (direc == 1) mainChar->Left(10);
	else if (direc== 2) mainChar->Right(10);
	else if (direc == 3) mainChar->Up(10);
	else if (direc == 4) mainChar->Down(10);
}

void CGAME::clear()
{
	m_isRunning = 0;
	m_currentLevel = 0;
	CurrentScore = 0;
	NameOfPlayer.clear();
	m.clear();

	if (mainChar) {
		delete mainChar;
		mainChar = NULL;
	}
	if (numOfCars) {
		delete[] car;
		numOfCars = 0;
		car = NULL;
	}
	if (numOfTrucks) {
		delete[] truck;
		numOfTrucks = 0;
		truck = NULL;
	}
	if (numOfTrains) {
		delete[] train;
		numOfTrains = 0;
		train = NULL;
	}

	if (numOfBirds) {
		delete[] bird;
		numOfBirds = 0;
		bird = NULL;
	}
	if (numOfCats) {
		delete[] cat;
		numOfCats = 0;
		cat = NULL;
	}
	if (numOfMouses) {
		delete[] mouse;
		numOfMouses = 0;
		mouse = NULL;
	}
	mciSendStringA("close MyFile", NULL, 0, NULL);
}

void CGAME::run()
{
	// update index of CANIMAL and CVEHICLE
	for (int i = 0; i < numOfCars; i++) car[i].Move(this->m_currentLevel);
	for (int i = 0; i < numOfTrucks; i++) truck[i].Move(this->m_currentLevel);
	for (int i = 0; i < numOfTrains; i++) train[i].Move(this->m_currentLevel);
	for (int i = 0; i < numOfCats; i++) cat[i].Move(this->m_currentLevel);
	for (int i = 0; i < numOfBirds; i++) bird[i].Move(this->m_currentLevel);
	for (int i = 0; i < numOfMouses; i++) mouse[i].Move(this->m_currentLevel);

}

void CGAME::tell()
{
	//if (PlaySound(TEXT("Sound\\BACKGROUND.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC)) 
	//{
	//	// Sound started playing successfully
	//	// You can add additional code here if needed
	//	//getch();
	//	//PlaySound(0, 0, 0);
	//	//getch();
	//}
	//else {
	//	// Error handling
	//	DWORD error = GetLastError();
	//	if (error != MMSYSERR_NOERROR) {
	//		// Handle the error
	//		// You can print an error message or perform other actions
	//	}
	//}
	mciSendStringA("open Sound/BACKGROUND.wav type waveaudio alias MyFile", NULL, 0, 0);
	// Play the audio
	mciSendStringA("play MyFile", NULL, 0, NULL);	//std::cerr << "Error playing the sound." << std::endl;
	

	// You might want to add some delay to let the sound play before closing
	// For example, using Sleep function (don't forget to include Windows.h)
	// Sleep(5000); // Sleep for 5000 milliseconds (5 seconds)

	// Close the audio file
	//mciSendStringA("close MyFile", NULL, 0, NULL);

}

std::string CGAME::getName() const
{
	return this->NameOfPlayer;
}

void CGAME::Draw(Render_State& screen)
{
	screen.drawImage(this->gameBackground, 0, 0, 1);
	bool peopleDraw = false;
	for (const auto& it : m)
	{
		if (it.first >= -mainChar->GetmY() && !peopleDraw)
		{
			mainChar->draw(screen);
			peopleDraw = true;
		}
		for (const auto& x : it.second)
		{
			switch (x.second)
			{
			case CAR_NUMBER:
				((CAR*)x.first)->draw(screen);
				break;

			case CAT_NUMBER:
				((CAT*)x.first)->draw(screen);
				break;

			case TRUCK_NUMBER:
				((CTRUCK*)x.first)->draw(screen);
				break;
			case TRAIN_NUMBER:
				((CTRAIN*)x.first)->draw(screen);
				break;
			case BIRD_NUMBER:
				((CBIRD*)x.first)->draw(screen);
				break;
			case MOUSE_NUMBER:
				((CMOUSE*)x.first)->draw(screen);
				break;
			}
		}
	}
	if (!peopleDraw)
	{
		mainChar->draw(screen);
		peopleDraw = true;
	}
}

int CGAME::CheckStatePepple() // 0: ko va cham, 1: va cham vehicle, 2: va cham animal
{
	for (const auto& it : m)
	{
		for (const auto& x : it.second)
		{
			switch (x.second)
			{
			case CAR_NUMBER:			
			case TRAIN_NUMBER:
			case TRUCK_NUMBER:
				if (mainChar->isImpact((CVEHICLE*)x.first)) return 1;
				
			break;

			case CAT_NUMBER:
			case MOUSE_NUMBER:
			case BIRD_NUMBER:
				if (mainChar->isImpact((CANIMAL*)x.first)) return 2;
				
				break;
			}
		}
	}

	return 0;
}

bool CGAME::SaveScoreToLeaderBoard()
{
	ofstream out;
	out.open("\\Data\\LeaderBoard.txt", ios::app);
	out << endl;
	if (!out.is_open()) return false;
	out << NameOfPlayer << " " << CurrentScore;
	out.close();
	return true;
}

std::multimap<int, pair<string, string>> CGAME::GetLeaderBoard()
{
	std::multimap<int, pair<string, string>> res;
	ifstream in;
	in.open("\\Data\\LeaderBoard.txt");
	string tmp, NamePlayer, Time;
	int score;
	in >> tmp;
	while (!in.eof())
	{
		in >> NamePlayer >> Time >> score;
		pair<string, string> tmp = { NamePlayer,Time };
		res.insert({ score, tmp });
	}

	return res;
	
}
