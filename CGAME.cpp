#include "CGAME.h"
#include <conio.h>


bitmapHandMake CGAME::gameBackground("image\\gameWindow\\gameBgr.bmp");
const int CGAME::MAX_LEVEL = 5;
const int CGAME::BOTTOM = 1280;


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
	m_currentLevel = 1;
	CurrentScore = 0;
	NameOfPlayer = "";
	FileBackGround = "";

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

	getline(ifs, this->FileBackGround);
	this->gameBackground.readBitmapFile(FileBackGround);

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
		ofs << *it <<" ";
			
	}
	ofs << endl;
	ofs << numOfTrucks << " ";
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
		ofs << *it <<" ";
		
	}
	ofs << endl;
	ofs << numOfCats << " ";
	for (int i = 0; i < numOfCats; i++)
	{
		CANIMAL* it = dynamic_cast<CANIMAL*> (&cat[i]);
		ofs << *it <<" ";
		

	}
	ofs << endl;
	ofs << numOfMouses << " ";
	for (int i = 0; i < numOfMouses; i++)
	{
		CANIMAL* it = dynamic_cast<CANIMAL*> (&mouse[i]);
		ofs << *it <<" ";
	}
	ofs.close();

	auto data = getListGames();
	ofs.open("Data\\FileName.txt");
	if (!ofs.is_open()) return false;

	int newIt = data.first % 5 + 1;
	data.second[data.first] = make_pair(file, make_pair(this->NameOfPlayer, CGAME::getCurTime()));
	ofs << data.second.size() << ' ' << newIt << '\n';
	for (const auto& x : data.second) 
		ofs << x.first << ' ' << x.second.first << x.second.second << '\n';
	return true;
}

void CGAME::PeopleMove(int direc)
{
	if (direc == 1) mainChar->Left(10);
	else if (direc== 2) mainChar->Right(10);
	else if (direc == 3) mainChar->Up(10);
	else if (direc == 4) mainChar->Down(10);

	if (CheckStatePepple()) mainChar->setDead();
	else if (mainChar->GetmY() > this->BOTTOM) loadNextLevel();
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
	int speed = this->getCurrentSpeed();
	// update index of CANIMAL and CVEHICLE
	for (int i = 0; i < numOfCars; i++) car[i].Move(speed);
	for (int i = 0; i < numOfTrucks; i++) truck[i].Move(speed);
	for (int i = 0; i < numOfTrains; i++) train[i].Move(speed);
	for (int i = 0; i < numOfCats; i++) cat[i].Move(speed);
	for (int i = 0; i < numOfBirds; i++) bird[i].Move(speed);
	for (int i = 0; i < numOfMouses; i++) mouse[i].Move(speed);

	if (CheckStatePepple()) mainChar->setDead();

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
	out.open("Data\\LeaderBoard.txt", ios::app);
	out << endl;
	if (!out.is_open()) return false;
	out << NameOfPlayer << " " << getCurTime() <<" "<<CurrentScore;
	out.close();
	return true;
}

void fileForGameLoading(string fileName, vector <pair<string, string>>& vect) {
	ifstream ifs;
	ifs.open(fileName);
	if (ifs.is_open()) {
		string temp;
		getline(ifs, temp);
		int numFile = temp[0] - '0'; // 0 <= number of files <= 5
		for (int i = 0; i < numFile; i++) {
			string userName, date;
			getline(ifs, temp, ' '); // No use
			getline(ifs, userName, ' ');
			getline(ifs, date);
			vect.push_back(make_pair(userName, date));
		}
	}
	ifs.close();
}

std::multimap<int, pair<string, string>> CGAME::GetLeaderBoard()
{
	std::multimap<int, pair<string, string>> res;
	ifstream in;
	in.open("Data\\LeaderBoard.txt");
	string tmp, NamePlayer, Time;
	int score;
	in >> tmp;
	while (!in.eof())
	{
		in >> NamePlayer >> Time >> score;
		pair<string, string> tmp2 = { NamePlayer,Time };
		res.insert({ score, tmp2 });
	}

	return res;

}

int CGAME::getLevelScore() const
{
	return (this->m_currentLevel + 1) * 100;
}

int CGAME::getCurrentSpeed() const
{
	return this->m_currentLevel / 3 + 1;
}

bool CGAME::checkState() const
{
	return !this->mainChar->isDead();
}

bool CGAME::loadNextLevel()
{
	if (mainChar->isDead()) return false;
	
	string name = this->NameOfPlayer;
	int score = this->CurrentScore;
	int level = this->m_currentLevel + 1;
	readFile("Data\\Default" + to_string(this->m_currentLevel) + ".txt");
	this->NameOfPlayer = name;
	this->CurrentScore = score;
	this->m_currentLevel = level;
	return true;
}

bool CGAME::isFinishGame()
{
	return m_currentLevel >= MAX_LEVEL;
}

pair<int, vector<pair<string, pair<string, string>>>> CGAME::getListGames()
{
	ifstream ifs("Data\\FileName.txt");
	pair<int, vector <pair<string, pair<string, string>>>> res;
	res.first = 0;
	res.second.clear();

	if (!ifs.is_open()) return res;

	int numFile;
	ifs >> numFile >> res.first;
	res.second.resize(max(numFile, 0));
	for (auto& x:res.second)
	{
		ifs >> x.first >> x.second.first;
		ifs.ignore();
		getline(ifs, x.second.second);
	}
	ifs.close();
	return res;
}

string CGAME::getCurTime()
{
	string res;
	auto now = std::chrono::system_clock::now();
	auto now_c = std::chrono::system_clock::to_time_t(now);
	long long time_as_ll = static_cast<long long>(now_c);

	return std::to_string(time_as_ll);

}
