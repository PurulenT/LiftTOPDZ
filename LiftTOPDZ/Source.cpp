#include <iostream>
using namespace std;

class Lift
{
	int UpperLevel;
	bool OnOf;
	bool isWorking;
	int currentLevel;
	int targetLevel;
public:
	Lift(int upper) {
		this->UpperLevel = upper;
		isWorking = false;
		currentLevel = 1;
		OnOf = false;
	}

	void Turn(bool turn) {
		turn ? isWorking = true : isWorking = false;
	}

	string GetStatus()
	{
		return isWorking ?"Working": "Not working";
	}

	void GetCurLevel()
	{
		if (isWorking) {
			cout << "Текущий этаж: " << currentLevel << endl;
		}
	}

	void GetLevel(int level) {
		if (isWorking) {
			if (currentLevel > level)
			{
				while (currentLevel > level) {
					currentLevel--;
				}
			}
			else if (currentLevel < level)
			{
				while (currentLevel < level) {
					currentLevel++;
				}
				
			}
			else cout << "Current level!" << endl;
		}
	}




};

int main()
{
	setlocale(LC_ALL, "rus");
	Lift lift(10);
	cout << lift.GetStatus() << endl;
	lift.Turn(true);
	cout<< lift.GetStatus()<< endl;
	lift.GetCurLevel();
	lift.GetLevel(6);
	lift.GetCurLevel();
	lift.GetLevel(3);
	lift.GetCurLevel();
	lift.Turn(false);
	cout << lift.GetStatus() << endl;
}